#ifndef REPPORT_H_INCLUDED
#define REPPORT_H_INCLUDED
#define MAX_MEDICAMENTS_PAR_PAGE 5  
#include "interface.h"
#include "employer.h"
#include "medical.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include"interface.h"
#include <unistd.h>
// Définition de la structure des ventes
typedef struct vente {
    char id_medicament[6];
    int quantite;
    char date_vente[11]; // Format YYYY-MM-DD
    struct vente *next;
} vente_list;
// Fonction pour ajouter un médicament
med_list* ajouterMedicament(med_list *head, medical med) {
    med_list* nouveau = (med_list*)malloc(sizeof(med_list));
    if (!nouveau) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    nouveau->data = med;
    nouveau->next = head;
    return nouveau;
}

// Fonction pour enregistrer une vente dans la liste et dans un fichier
void enregistrerVente(med_list *head, vente_list **ventes_head, char id[], int quantite, char date_vente[]) {
    med_list* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->data.id, id) == 0) {
            if (temp->data.quantity >= quantite) {
                temp->data.quantity -= quantite;
                temp->data.quantity_sold += quantite;
                temp->data.profit += quantite * (temp->data.sale_price - temp->data.purchase_price);

                // Ajouter la vente à la liste des ventes
                vente_list* nouvelle_vente = (vente_list*)malloc(sizeof(vente_list));
                if (!nouvelle_vente) {
                    printf("Memory allocation error.\n");
                    exit(EXIT_FAILURE);
                }
                strcpy(nouvelle_vente->id_medicament, id);
                nouvelle_vente->quantite = quantite;
                strcpy(nouvelle_vente->date_vente, date_vente);
                nouvelle_vente->next = *ventes_head;
                *ventes_head = nouvelle_vente;

                // Enregistrer la vente dans le fichier texte
                FILE *file = fopen("ventes.txt", "a");
                if (!file) {
                    printf("Error opening the file ventes.txt.\n");
                    exit(EXIT_FAILURE);
                }
                fprintf(file, "%s %d %s\n", id, quantite, date_vente);
                fclose(file);
            } else {
                printf("Insufficient stock for the medicine %s.\n", temp->data.medi_name);
            }
            return;
        }
        temp = temp->next;
    }
    printf("Medicine with ID %s not found.\n", id);
}

// Fonction pour afficher le stock restant
void afficherStock(med_list *head) {
    med_list* temp = head;
    int row = 2;  // Position de départ pour afficher les médicaments

    // Affichage du cadre de la table
    box();  // Assurez-vous que cette fonction affiche la boîte sans dépasser

    // Titre
    gotoxy(20, 0);
    textcolor(2);
    printf("-----Remaining stock by medicine:------\n");

    // Affichage de la ligne du tableau (bordure)
    gotoxy(10, row);
    textcolor(14);
    printf("========================================================");
    row++;

    // Affichage de l'en-tête du tableau
    gotoxy(10, row);
    textcolor(15);
    printf("| %-15s | %-16s | %-16s |", "Medicine Name", "Stock Quantity", "Unit Price");
    row++;

    // Affichage de la ligne de séparation après l'en-tête
    gotoxy(10, row);
    textcolor(14);
    printf("+-----------------+------------------+------------------+");
    row++;

    // Affichage des médicaments
    while (temp != NULL) {
        // Affichage des informations du médicament dans chaque ligne
        gotoxy(10, row);
        textcolor(15);
        printf("| %-15s | %-16d | %-16.2f |", temp->data.medi_name, temp->data.quantity, temp->data.purchase_price);
        row++;

        // Affichage de la ligne de séparation après chaque ligne de médicament
        gotoxy(10, row);
        textcolor(14);
        printf("+-----------------+------------------+------------------+");
        row++;

        temp = temp->next;
    }

    // Si aucun médicament n'est trouvé
    if (head == NULL) {
        gotoxy(10, row);
        textcolor(12);
        printf("No medicines available in stock.\n");
    }
}

// Fonction pour afficher les ventes hebdomadaires
void rapportVentesHebdomadaires(vente_list *head) {
    int ventes_par_semaine[52] = {0};
    vente_list* temp = head;
    box();
    while (temp != NULL) {
        int annee, mois, jour;
        sscanf(temp->date_vente, "%d-%d-%d", &annee, &mois, &jour);
        int semaine = ((mois - 1) * 30 + jour) / 7; // Approximation
        ventes_par_semaine[semaine] += temp->quantite;
        temp = temp->next;
    }
    gotoxy(20, 10);
    textcolor(2);
    printf("-----Weekly Sales Report------\n");
    gotoxy(20, 11);
    textcolor(14);
    for (int i = 0; i < 52; i++) {
        if (ventes_par_semaine[i] > 0) {
            printf("\t Week %d: %d sales\n", i + 1, ventes_par_semaine[i]);
        }
    }
}

// Fonction pour afficher une page de médicaments
void afficher_page(medical *med_array, int page, int total_meds) {
    system("cls");
    box();
    textcolor(2);
    gotoxy(20, 9);
    printf("----- Best-Selling Medicines -----\n");

    int start = page * MAX_MEDICAMENTS_PAR_PAGE;
    int end = start + MAX_MEDICAMENTS_PAR_PAGE;
    if (end > total_meds) end = total_meds;

    int row = 11;
    for (int i = start; i < end; i++) {
        gotoxy(20, row++);
        textcolor(15);
        printf("%d. %-15s | Sold: %-5d | Profit: %.2f\n", i + 1, med_array[i].medi_name, med_array[i].quantity_sold, med_array[i].profit);
    }

    // Si la page suivante existe, demander à l'utilisateur de passer à la page suivante
    if (end < total_meds) {
        gotoxy(20, row++);
        printf("Press 'n' for next page...\n");
    }
}

// Fonction pour afficher un graphique avec GNUPLOT
void plot_graph(medical *med_array, int count) {
    // Créer un fichier temporaire pour GNUPLOT
    FILE *temp_file = fopen("medicines_data.txt", "w");
    if (temp_file == NULL) {
        printf("Erreur d'ouverture du fichier temporaire.\n");
        return;
    }

    // Écrire les données des médicaments dans le fichier
    for (int i = 0; i < count; i++) {
        fprintf(temp_file, "%d %d\n", i + 1, med_array[i].quantity_sold);
    }
    fclose(temp_file);

    // Créer une commande pour GNUPLOT
    FILE *gnupipe = popen("gnuplot -persistent", "w");
    if (gnupipe == NULL) {
        printf("Erreur d'ouverture du pipe GNUPLOT.\n");
        return;
    }

    // Envoyer les commandes GNUPLOT pour créer le graphique
    fprintf(gnupipe, "set title 'Top-Selling Medicines'\n");
    fprintf(gnupipe, "set xlabel 'Medicine'\n");
    fprintf(gnupipe, "set ylabel 'Quantity Sold'\n");
    fprintf(gnupipe, "set xtics rotate by -45\n");
    fprintf(gnupipe, "plot 'medicines_data.txt' using 1:2 with boxes title 'Quantity Sold'\n");
    fclose(gnupipe);

    // Supprimer le fichier temporaire
    remove("medicines_data.txt");
}

// Fonction pour afficher les médicaments les plus vendus
void medicamentLePlusVendu(med_list *head) {
    int count = 0;
    med_list *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    if (count == 0) {
        gotoxy(20, 10);
        printf("No medicines available.\n");
        return;
    }

    // Tableau de médicaments trié
    medical *med_array = (medical *)malloc(count * sizeof(medical));
    if (!med_array) {
        printf("Erreur d'allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }

    temp = head;
    for (int i = 0; i < count; i++) {
        med_array[i] = temp->data;
        temp = temp->next;
    }

    // Trier les médicaments par quantité vendue
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (med_array[j].quantity_sold < med_array[j + 1].quantity_sold) {
                medical temp_med = med_array[j];
                med_array[j] = med_array[j + 1];
                med_array[j + 1] = temp_med;
            }
        }
    }

    // Affichage des médicaments par page
    int total_pages = (count + MAX_MEDICAMENTS_PAR_PAGE - 1) / MAX_MEDICAMENTS_PAR_PAGE;
    int page = 0;
    char choice;

    do {
        afficher_page(med_array, page, count);

        // Afficher le graphique
        plot_graph(med_array, count);

        // Gérer la navigation entre les pages
        if (page < total_pages - 1) {
            choice = getchar();
            if (choice == 'n' || choice == 'N') {
                page++;
            }
        }

    } while (choice == 'n' || choice == 'N');

    free(med_array);
}


// Fonction pour afficher le menu de rapport
void afficherMenuRapport() {
    system("cls");
    box();
    textcolor(14);
    gotoxy1(20, 5);
    printf("------------------------");
    gotoxy1(20, 6);
    textcolor(2);
    printf("  ----REPORT MENU----");
    gotoxy1(20, 7);
    textcolor(14);
    printf("------------------------");
    gotoxy1(20, 9);
    textcolor(14);
    printf("1. Display Remaining Stock\n");
    gotoxy1(20, 11);
    printf("2. Weekly Sales Report\n");
    gotoxy1(20, 13);
    printf("3. Best-Selling Medicine\n");
    gotoxy1(20, 15);
    printf("4. Graph: Weekly Sales\n");
    gotoxy1(20, 17);
    printf("5. Graph: Stock of Medicines\n");
    gotoxy1(20, 19);
    printf("6. Exit\n");
    gotoxy1(20, 21);
    printf("\t Select an option: ");
}

// Fonction pour afficher les graphiques avec GNUPLOT
void afficherGraphiqueVentesHebdomadaires(vente_list *head) {
    int ventes_par_semaine[52] = {0};
    vente_list* temp = head;

    while (temp != NULL) {
        int annee, mois, jour;
        sscanf(temp->date_vente, "%d-%d-%d", &annee, &mois, &jour);
        int semaine = ((mois - 1) * 30 + jour) / 7;
        ventes_par_semaine[semaine] += temp->quantite;
        temp = temp->next;
    }

    FILE *dataFile = fopen("ventes_hebdo.dat", "w");
    if (!dataFile) {
        printf("Error: Unable to create the data file.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 52; i++) {
        if (ventes_par_semaine[i] > 0) {
            fprintf(dataFile, "%d %d\n", i + 1, ventes_par_semaine[i]);
        }
    }
    fclose(dataFile);

    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    if (!gnuplotPipe) {
        printf("Error: Unable to launch GNUPLOT.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(gnuplotPipe, "set title 'Weekly Sales'\n");
    fprintf(gnuplotPipe, "set xlabel 'Weeks'\n");
    fprintf(gnuplotPipe, "set ylabel 'Quantity Sold'\n");
    fprintf(gnuplotPipe, "set grid\n");
    fprintf(gnuplotPipe, "set style data linespoints\n");
    fprintf(gnuplotPipe, "plot 'ventes_hebdo.dat' using 1:2 with linespoints title 'Sales'\n");

    pclose(gnuplotPipe);
    remove("ventes_hebdo.dat");
}

void afficherGraphiqueStock(med_list *head) {
    med_list* temp = head;

    FILE *dataFile = fopen("stock_medicaments.dat", "w");
    if (!dataFile) {
        printf("Error: Unable to create the data file.\n");
        exit(EXIT_FAILURE);
    }

    while (temp != NULL) {
        fprintf(dataFile, "%s %d\n", temp->data.medi_name, temp->data.quantity);
        temp = temp->next;
    }
    fclose(dataFile);

    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    if (!gnuplotPipe) {
        printf("Error: Unable to launch GNUPLOT.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(gnuplotPipe, "set title 'Stock of Medicines'\n");
    fprintf(gnuplotPipe, "set xlabel 'Medicines'\n");
    fprintf(gnuplotPipe, "set ylabel 'Stock Quantity'\n");
    fprintf(gnuplotPipe, "set grid\n");
    fprintf(gnuplotPipe, "set style data histograms\n");
    fprintf(gnuplotPipe, "set style fill solid\n");
    fprintf(gnuplotPipe, "set xtics rotate by -45\n");
    fprintf(gnuplotPipe, "plot 'stock_medicaments.dat' using 2:xtic(1) title 'Stock'\n");

    pclose(gnuplotPipe);
    remove("stock_medicaments.dat");
}

// Fonction principale pour gérer le menu des rapports
void report_menu() {
    med_list *head = NULL;
    vente_list *ventes_head = NULL;

    // Ajout de médicaments exemples
    medical med1 = {"001", "Paracetamol", 100, 101, 0, 0.50, 0.0, 0.30, 0.50, "2024-12-31", "Supplier A"};
    medical med2 = {"002", "Ibuprofen", 50, 102, 0, 1.00, 0.0, 0.60, 1.00, "2025-01-31", "Supplier B"};
    head = ajouterMedicament(head, med1);
    head = ajouterMedicament(head, med2);
      // Ajout de médicaments exemples supplémentaires
    medical med3 = {"003", "Aspirin", 200, 103, 0, 0.80, 0.0, 0.50, 0.80, "2024-12-31", "Supplier C"};
    medical med4 = {"004", "Cough Syrup", 150, 104, 0, 2.00, 0.0, 1.50, 2.00, "2025-01-31", "Supplier D"};
    medical med5 = {"005", "Vitamin C", 300, 105, 0, 0.60, 0.0, 0.40, 0.60, "2025-02-28", "Supplier E"};

    head = ajouterMedicament(head, med3);
    head = ajouterMedicament(head, med4);
    head = ajouterMedicament(head, med5);
    enregistrerVente(head, &ventes_head, "003", 10, "2024-1-05");
    enregistrerVente(head, &ventes_head, "004", 5, "2024-10-06");
    enregistrerVente(head, &ventes_head, "005", 20, "2024-12-07");

    // Enregistrement des ventes exemples
    enregistrerVente(head, &ventes_head, "001", 5, "2024-12-01");
    enregistrerVente(head, &ventes_head, "002", 3, "2024-12-02");
    enregistrerVente(head, &ventes_head, "001", 2, "2024-12-02");
    // Ajout de médicaments supplémentaires
    medical med6 = {"006", "Antibiotic X", 500, 106, 0, 3.00, 0.0, 2.50, 3.00, "2024-12-31", "Supplier F"};
    medical med7 = {"007", "Painkiller Y", 100, 107, 0, 1.50, 0.0, 1.00, 1.50, "2025-01-15", "Supplier G"};
    medical med8 = {"008", "Allergy Medicine Z", 250, 108, 0, 2.50, 0.0, 1.80, 2.50, "2025-01-30", "Supplier H"};
    medical med9 = {"009", "Cold Medicine W", 450, 109, 0, 1.20, 0.0, 0.90, 1.20, "2025-02-28", "Supplier I"};
    medical med10 = {"010", "Fever Reducer V", 300, 110, 0, 1.80, 0.0, 1.20, 1.80, "2025-03-15", "Supplier J"};

// Ajouter les nouveaux médicaments à la liste
    head = ajouterMedicament(head, med6);
    head = ajouterMedicament(head, med7);
    head = ajouterMedicament(head, med8);
    head = ajouterMedicament(head, med9);
    head = ajouterMedicament(head, med10);

// Enregistrement de ventes pour ces nouveaux médicaments
enregistrerVente(head, &ventes_head, "006", 20, "2024-12-10");
enregistrerVente(head, &ventes_head, "007", 15, "2024-12-12");
enregistrerVente(head, &ventes_head, "008", 50, "2024-12-14");
enregistrerVente(head, &ventes_head, "009", 30, "2024-12-15");
enregistrerVente(head, &ventes_head, "010", 25, "2024-12-16");

    int choix;
    do {
        afficherMenuRapport();
        scanf("%d", &choix);
        system("cls");
        box();

        switch (choix) {
            case 1:
                gotoxy(20,8);
                printf("-----Display medical-----");
                afficherStock(head);
                break;
            case 2:
                gotoxy(20,8);
                printf("-----VENTES_HEBDOMADAIRES----");
                rapportVentesHebdomadaires(ventes_head);
                break;
            case 3:
                medicamentLePlusVendu(head);
                break;
            case 4:
                afficherGraphiqueVentesHebdomadaires(ventes_head);
                break;
            case 5:
                afficherGraphiqueStock(head);
                break;
            case 6:
               gotoxy(20,10);
               textcolor(2);
                printf("\t Exiting...\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }

        if (choix != 6) {
            printf("\n\n\n\tPress any key to return to the menu...\n");
            getch();
        }
    } while (choix != 6);
}

#endif

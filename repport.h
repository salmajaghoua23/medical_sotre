#ifndef REPPORT_H_INCLUDED
#define REPPORT_H_INCLUDED
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
#include"menu_adm.h"
#include <unistd.h>
typedef struct medical2 {
    char id[6];
    char medi_name[20];
    int quantity;
    int id_prescription;
    int quantity_sold;
    float cost;
    float profit;
    float purchase_price;
	 float sale_price; 
    char exp_date[15];
    char supplier_name[30];
} medical2;


// Linked list structure
typedef struct node1 {
    medical2 data;
    struct node1 *next;
} med_list1;
//Définition de la structure des ventes
typedef struct vente {
    char id_medicament[6];
    int quantite;
    char date_vente[11]; // Format YYYY-MM-DD
    struct vente *next;
} vente_list;
med_list1* ajouterMedicament(med_list1 *head, medical2 med) {
    med_list1* nouveau = (med_list1*)malloc(sizeof(med_list1));
    if (!nouveau) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    nouveau->data = med;
    nouveau->next = head;
    return nouveau;
}
void report_menu();
void afficherStock(med_list1 *head);
void afficherMenuRapport();
void rapportVentesHebdomadaires(vente_list *head);
void medicamentLePlusVendu(med_list1 *head);
void afficherGraphiqueStock(med_list1 *head);
void afficherGraphiqueVentesHebdomadaires(vente_list *head);
med_list1* ajouterMedicament(med_list1 *head, medical2 med);
void gotoxy1(int x, int y);
void textcolor(int color);
void box();
// Fonction pour ajouter un médicament

// Fonction pour enregistrer une vente dans la liste et dans un fichier
void enregistrerVente(med_list1 *head, vente_list **ventes_head, char id[], int quantite, char date_vente[]) {
    med_list1* temp = head;
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
void afficherStock(med_list1 *head) {
    med_list1* temp = head;
    int row = 2;  // Position de départ pour afficher les médicaments

    // Affichage du cadre de la table
    box();  // Assurez-vous que cette fonction affiche la boîte sans dépasser

    // Titre
    gotoxy(30, 0);
    textcolor(2);
    printf("-----Remaining stock by medicine:------\n");

    // Affichage de la ligne du tableau (bordure)
    gotoxy(30, row);
    textcolor(14);
    printf("========================================================");
    row++;

    // Affichage de l'en-tête du tableau
    gotoxy(30, row);
    textcolor(15);
    printf("| %-15s | %-16s | %-16s |", "Medicine Name", "Stock Quantity", "Unit Price");
    row++;

    // Affichage de la ligne de séparation après l'en-tête
    gotoxy(30, row);
    textcolor(14);
    printf("+-----------------+------------------+------------------+");
    row++;

    // Affichage des médicaments
    while (temp != NULL) {
        // Affichage des informations du médicament dans chaque ligne
        gotoxy(30, row);
        textcolor(15);
        printf("| %-15s | %-16d | %-16.2f |", temp->data.medi_name, temp->data.quantity, temp->data.purchase_price);
        row++;

        // Affichage de la ligne de séparation après chaque ligne de médicament
        gotoxy(30, row);
        textcolor(14);
        printf("+-----------------+------------------+------------------+");
        row++;

        temp = temp->next;
    }

    // Si aucun médicament n'est trouvé
    if (head == NULL) {
        gotoxy(30, row);
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
    gotoxy(30, 10);
    textcolor(2);
    printf("-----Weekly Sales Report------\n");
    textcolor(14);
    
    for (int i = 0; i < 52; i++) {
        if (ventes_par_semaine[i] > 0) {
            printf("\t\t\t Week %d: | \t\t %d sales\n", i + 1, ventes_par_semaine[i]);
        }
    }
    printf("\n\n\n\n\n\n");
}
#define MAX_MEDICAMENTS_PAR_PAGE 5  // Limite de médicaments par page
// Fonction pour afficher une page de médicaments
void afficher_page(medical2 *med_array, int page, int total_meds) {
    system("cls");
    box();
    textcolor(2);
    gotoxy(40, 9);
    printf("----- Best-Selling Medicines -----\n");

    int start = page * MAX_MEDICAMENTS_PAR_PAGE;
    int end = start + MAX_MEDICAMENTS_PAR_PAGE;
    if (end > total_meds) end = total_meds;

    int row = 11;
    for (int i = start; i < end; i++) {
        gotoxy(30, row++);
        textcolor(15);
        printf("%d. %-18s | Sold: %-5d | Profit: %.2f\n", i + 1, med_array[i].medi_name, med_array[i].quantity_sold, med_array[i].profit);
    }
    
    // Si la page suivante existe, demander à l'utilisateur de passer à la page suivante
    if (end < total_meds) {
        gotoxy(30, row++);
        printf("Press 'n' for next page...\n");
    }
}

// Fonction pour afficher un graphique avec GNUPLOT
void plot_graph(medical2 *med_array, int count) {
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
   printf("\t\tOpening GNUPLOT...\n");

fprintf(gnupipe, "set title 'Top-Selling Medicines'\n");
    fprintf(gnupipe, "set xlabel 'Medicine'\n");
    fprintf(gnupipe, "set ylabel 'Quantity Sold'\n");
    fprintf(gnupipe, "set xtics rotate by -45\n");
    fprintf(gnupipe, "set style fill solid 1.0 border -1\n");  // Remplir les barres avec une couleur solide
    fprintf(gnupipe, "plot 'medicines_data.txt' using 1:2 with boxes title 'Quantity Sold'\n");
    fclose(gnupipe);

}
// Fonction pour afficher les médicaments les plus vendus
void medicamentLePlusVendu(med_list1 *head) {
    int count = 0;
    med_list1 *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    if (count == 0) {
        gotoxy(40, 10);
        printf("No medicines available.\n");
        return;
    }

    // Tableau de médicaments trié
    medical2 *med_array = (medical2 *)malloc(count * sizeof(medical2));
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
                medical2 temp_med = med_array[j];
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
     printf("\n\n\n\n\n\n");
    free(med_array);
}

// Fonction pour afficher le menu de rapport
void afficherMenuRapport() {
    system("cls");
    box();
    textcolor(14);
    gotoxy1(40, 5);
    printf("------------------------");
    gotoxy1(40, 6);
    textcolor(2);
    printf("  ----REPORT MENU----");
    gotoxy1(40, 7);
    textcolor(14);
    printf("------------------------");
    gotoxy1(40, 9);
    textcolor(14);
    printf("1. Display Remaining Stock\n");
    gotoxy1(40, 11);
    printf("2. Weekly Sales Report\n");
    gotoxy1(40, 13);
    printf("3. Best-Selling Medicine\n");
    gotoxy1(40, 15);
    printf("4. Exit\n");
    gotoxy1(40, 18);
    textcolor(5);
    printf("\t\t\t\t Select an option: ");
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

void afficherGraphiqueStock(med_list1 *head) {
    med_list1* temp = head;

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
    med_list1 *head = NULL;
    vente_list *ventes_head = NULL;

    // Ajout de médicaments exemples
    medical2 med1 = {"001", "Paracetamol", 100, 101, 0, 0.50, 0.0, 0.30, 0.50, "2024-12-31", "Supplier A"};
    medical2 med2 = {"002", "Ibuprofen", 50, 102, 0, 1.00, 0.0, 0.60, 1.00, "2025-01-31", "Supplier B"};
    head = ajouterMedicament(head, med1);
    head = ajouterMedicament(head, med2);
      // Ajout de médicaments exemples supplémentaires
    medical2 med3 = {"003", "Aspirin", 200, 103, 0, 0.80, 0.0, 0.50, 0.80, "2024-12-31", "Supplier C"};
    medical2 med4 = {"004", "Cough Syrup", 150, 104, 0, 2.00, 0.0, 1.50, 2.00, "2025-01-31", "Supplier D"};
    medical2 med5 = {"005", "Vitamin C", 300, 105, 0, 0.60, 0.0, 0.40, 0.60, "2025-02-28", "Supplier E"};

    head = ajouterMedicament(head, med3);
    head = ajouterMedicament(head, med4);
    head = ajouterMedicament(head, med5);
    enregistrerVente(head, &ventes_head, "003", 10, "2024-12-05");
    enregistrerVente(head, &ventes_head, "004", 5, "2024-12-06");
    enregistrerVente(head, &ventes_head, "005", 20, "2024-12-07");

    int choix;
    do {
        afficherMenuRapport();
        scanf("%d", &choix);
        system("cls");
        box();

        switch (choix) {
            case 1:
                afficherStock(head);
                 afficherGraphiqueStock(head);
                break;
            case 2:
                rapportVentesHebdomadaires(ventes_head);
                 afficherGraphiqueVentesHebdomadaires(ventes_head);
                break;
            case 3:
                medicamentLePlusVendu(head);
                break;
            case 4:
               box();
               gotoxy(30,12);
               textcolor(2);
                printf("Exiting...\n");
                main_menu();
                break;
            default:
                box();
                gotoxy(30,12);
                textcolor(1);
                printf("Invalid option. Try again.\n");
        }

        if (choix != 4) {
            printf("\n\n\n\tPress any key to return to the menu...\n");
            getch();
        }
    } while (choix != 6);
}
#endif
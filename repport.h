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
        printf("Erreur d'allocation mémoire.\n");
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
                    printf("Erreur d'allocation mémoire.\n");
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
                    printf("Erreur d'ouverture du fichier ventes.txt.\n");
                    exit(EXIT_FAILURE);
                }
                fprintf(file, "%s %d %s\n", id, quantite, date_vente);
                fclose(file);
            } else {
                printf("Stock insuffisant pour le médicament %s.\n", temp->data.medi_name);
            }
            return;
        }
        temp = temp->next;
    }
    printf("Médicament avec l'ID %s introuvable.\n", id);
}

// Fonction pour afficher le stock restant
void afficherStock(med_list *head) {
    med_list* temp = head;
    box();
    gotoxy(20,9);
    textcolor(2);
    printf("-----Remaining stock by medicine:------\n");
    gotoxy(20,10);
    
    while (temp != NULL) {
        gotoxy(20,12);
        textcolor(14);
        printf("%s : %d units in stock\n", temp->data.medi_name, temp->data.quantity);
        temp = temp->next;
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
    gotoxy(20,10);
    textcolor(2);
    printf("-----Weekly Sales Report------\n");
    gotoxy(20,11);
    textcolor(14);
    for (int i = 0; i < 52; i++) {
        if (ventes_par_semaine[i] > 0) {
            printf("\t Week %d: %d sales\n", i + 1, ventes_par_semaine[i]);
        }
    }
}
void medicamentLePlusVendu(med_list *head) {
    // Compter le nombre d'éléments dans la liste chaînée
    int count = 0;
    med_list *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    // Créer un tableau dynamique pour stocker les médicaments
    medical *med_array = (medical *)malloc(count * sizeof(medical));
    if (!med_array) {
        printf("Erreur d'allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }

    // Copier les données de la liste chaînée dans le tableau
    temp = head;
    for (int i = 0; i < count; i++) {
        med_array[i] = temp->data;
        temp = temp->next;
    }

    // Trier le tableau en fonction de quantity_sold (du plus au moins vendu)
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (med_array[j].quantity_sold < med_array[j + 1].quantity_sold) {
                medical temp = med_array[j];
                med_array[j] = med_array[j + 1];
                med_array[j + 1] = temp;
            }
        }
    }

    // Afficher le médicament le plus vendu
    if (count > 0 && med_array[0].quantity_sold > 0) {
        gotoxy(20,8);
        textcolor(2);
        printf("----- Best-Selling Medicine -----");
        textcolor(14);
        gotoxy(10,10);
        printf("Name: %s\n", med_array[0].medi_name);
        gotoxy(10,12);
        printf("Quantity Sold: %d\n\n", med_array[0].quantity_sold);
    } else {
        gotoxy(15,10);
        printf("No sales recorded.\n");
    }

    // Afficher les autres médicaments triés
    textcolor(2);
    gotoxy(20,14);
    printf("----- All Medicines Sorted by Sales -----\n");
    for (int i = 0; i < count; i++) {
        textcolor(15);
        printf("\n\t Name: %s,\n\t Quantity Sold: %d\n", med_array[i].medi_name, med_array[i].quantity_sold);
    }

    // Libérer la mémoire allouée
    free(med_array);
}

// Fonction pour afficher le menu de rapport
void afficherMenuRapport() {
    system("cls"); // Effacer l'�cran
        box();         // Dessiner le cadre avec votre fonction
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
        printf("4. Exit\n");
        gotoxy1(20, 17);
        printf("Select an option: ");
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

    // Enregistrement des ventes exemples
    enregistrerVente(head, &ventes_head, "001", 5, "2024-12-01");
    enregistrerVente(head, &ventes_head, "002", 3, "2024-12-02");
    enregistrerVente(head, &ventes_head, "001", 2, "2024-12-02");
    int choix;
    do {
        system("cls");
        box();  // Dessiner une boîte pour le menu principal
        afficherMenuRapport(); // Affiche les options du menu
        printf("\n\n\t Enter your choice:\t ");
        Sleep(5); 
        scanf("%d", &choix);
         Sleep(5); 
        system("cls"); // Effacer l'écran avant d'afficher le rapport
        switch (choix) {
            case 1:
                box();
                afficherStock(head); // Appel à la fonction d'affichage du stock
                printf("\n\n\n\n\n\n\n\n\n\n\n\t");
                break;

            case 2:
                box();
                rapportVentesHebdomadaires(ventes_head); // Rapport des ventes hebdomadaires
                 printf("\n\n\n\n\n\n\n\n\n\n\n\t");
                break;

            case 3:
                box();
                medicamentLePlusVendu(head); // Médicament le plus vendu
                 printf("\n\n\n\n\n\n\n\n\n\n\n\n\t");
                break;

            case 4:
                box();
                gotoxy(20,12);
                textcolor(2);
                printf("Exiting...\n");
                Sleep(2000); // Pause de 2 secondes avant de quitter
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }

        if (choix != 4) {
            printf("\nPress any key to return to the menu...\n");
            getch(); // Pause en attendant l'entrée de l'utilisateur
        }
    } while (choix != 4);
}
/* Fonction pour afficher le médicament le plus vendu
void medicamentLePlusVendu(med_list *head) {
    med_list* temp = head;
    medical *plus_vendu = NULL;
    int max_ventes = 0;
    box();
    textcolor(2);
    gotoxy(20,8);
     printf("----Best-Selling Medicine-----\n");
    while (temp != NULL) {
        textcolor(15);
        if (temp->data.quantity_sold > max_ventes) {
            max_ventes = temp->data.quantity_sold;
            plus_vendu = &temp->data;
        }
        temp = temp->next;
    }

    if (plus_vendu != NULL) {
        textcolor(14);
        gotoxy(7,12);
        printf("Best-Selling Medicine: %s with %d units sold\n", plus_vendu->medi_name, plus_vendu->quantity_sold);
    } else {
        printf("No sales recorded.\n");
    }
}
*/

#endif
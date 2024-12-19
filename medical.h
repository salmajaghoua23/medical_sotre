#ifndef MEDICAL_H_INCLUDED
#define MEDICAL_H_INCLUDED
#include <conio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include"interface.h"
#include"menu_adm.h"
#include"Notification.h"
#include"menu login.h"
 void medication_menu();
  void setTextColor(int color);
  void textcolor(int color );
  void gotoxy(int x, int y);

// Insert a new medicine
void insert_med(med_list **list, medical med) {
    FILE *file = fopen("medicines.txt", "a+");
    if (file == NULL) {
        box();
        setTextColor(4); // Red for error
        printf("The file cannot be found.\n");
        setTextColor(7); // Reset to white
        exit(1);
    }

    med_list *new_node = (med_list *)malloc(sizeof(med_list));
    if (new_node == NULL) {
        setTextColor(4);
        printf("Memory allocation failed.\n");
        setTextColor(7);
        fclose(file);
        return;
    }

    new_node->data = med;
    new_node->next = NULL;

    if (*list == NULL) {
        *list = new_node; // First element in the list
    } else {
        med_list *temp = *list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    fprintf(file, "%s %s %d %d %d %.2f %.2f %.2f %s %s\n",
            med.id, med.medi_name, med.quantity, med.id_prescription, med.quantity_sold,
            med.cost, med.profit, med.purchase_price, med.exp_date, med.supplier_name);

    fclose(file);
}

void display_meds() {
    system("cls");
    box(); // Dessine la boîte pour l'affichage

    FILE *file = fopen("medicines.txt", "r");
    if (file == NULL) {
        gotoxy1(20, 3); // Position dans la boîte
        setTextColor(4); // Rouge pour les avertissements
        printf("Erreur : Impossible d'ouvrir le fichier des médicaments.\n");
        setTextColor(7); // Blanc par défaut
        return;
    }

    // Affichage des titres de la table
    gotoxy1(20, 3); // Début des titres dans la boîte
    setTextColor(2); // Vert pour les titres
    printf(" ID    | Name         | Qty | PrescID | Sold | Cost   | Profit | Exp. Date   | Supplier");
    gotoxy1(20, 4);
    printf("------------------------------------------------------------------------------------------");
    setTextColor(7); // Blanc par défaut

    // Variables pour lire les données
    char id[10], medi_name[20], exp_date[15], supplier_name[30];
    int quantity, id_prescription, quantity_sold;
    float cost, profit, purchase_price;

    int row = 5; // Première ligne après les titres
    int page = 1;

    // Lire et afficher les données ligne par ligne
    while (fscanf(file, "%s %s %d %d %d %f %f %f %s %s",
                  id, medi_name, &quantity, &id_prescription, &quantity_sold,
                  &cost, &profit, &purchase_price, exp_date, supplier_name) != EOF) {
        gotoxy1(4, row);
        printf(" %-5s | %-12s | %-3d | %-7d | %-4d | %-6.2f | %-6.2f | %-11s | %-10s",
               id, medi_name, quantity, id_prescription, quantity_sold,
               cost, profit, exp_date, supplier_name);

        row++;

        // Gestion de la pagination si le contenu dépasse une page
        if (row == 22) { // Limite pour 18 lignes dans une boîte
            gotoxy1(20, row);
            printf("Appuyez sur une touche pour continuer...");
            getch(); // Pause
            system("cls"); // Nettoie l'écran
            box(); // Redessine la boîte

            // Réafficher les titres pour la nouvelle page
            gotoxy1(20, 3);
            setTextColor(2); // Vert pour les titres
            printf(" ID    | Name         | Qty | PrescID | Sold | Cost   | Profit | Exp. Date   | Supplier");
            gotoxy1(20, 4);
            printf("------------------------------------------------------------------------------------------");
            setTextColor(7); // Blanc par défaut

            row = 5; // Réinitialise la ligne pour la nouvelle page
            page++;
        }
    }

    fclose(file);

    // Afficher un message de fin
    gotoxy1(4, row);
    printf("\nFin de la liste. Total pages : %d\n", page);
}

void display_Medicines() {
    FILE *file = fopen("medicines.txt", "r");
    if (file == NULL) {
        textcolor(12);
        printf("File 'medicines.txt' not found . .\n");
        getch();
        return;
    }
    medical med;
    system("cls");

    // Titre principal
    textcolor(14);
    gotoxy(15, 2);
    printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════════════╗");
    gotoxy(15,3);
    textcolor(10);
    printf("║                                        PHARMACY SYSTEM                                                     ║");
    textcolor(14);
    gotoxy(15, 4);
    printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════╝");

    // En-tête du tableau
    textcolor(14);
    gotoxy(10, 6);
    printf("╔═══════╦══════════════════════╦══════════╦══════════╦══════════╦══════════╦════════════════════╦════════════════════╦══════════════╗");
    gotoxy(10, 7);
    printf("║  ID   ║    Medicine Name     ║ Quantity ║ Presc ID ║  Sold    ║   Cost   ║      Profit        ║ Expiration Date    ║   Supplier   ║");
    gotoxy(10, 8);
    printf("╠═══════╬══════════════════════╬══════════╬══════════╬══════════╬══════════╬════════════════════╬════════════════════╬══════════════╣");

    int row = 9;
    // Lire et afficher les données
    while (fscanf(file, "%5s %19s %d %d %d %f %f %f %14s %29s",
                  med.id, med.medi_name, &med.quantity, &med.id_prescription,
                  &med.quantity_sold, &med.cost, &med.profit, &med.purchase_price,
                  med.exp_date, med.supplier_name) == 10) {
        textcolor(7);
        gotoxy(10, row);
        printf("║ %-5s ║ %-20s ║ %-8d ║ %-8d ║ %-8d ║ %-8.2f ║ %-18.2f ║ %-18s ║ %-12s ║",
               med.id, med.medi_name, med.quantity, med.id_prescription, 
               med.quantity_sold, med.cost, med.profit, med.exp_date, med.supplier_name);

        row++;

        // Ligne de séparation après chaque médicament
        textcolor(14);
        gotoxy(10, row);
        printf("╟───────┼──────────────────────┼──────────┼──────────┼──────────┼──────────┼────────────────────┼────────────────────┼──────────────╢");
        row++;
    }

    // Bas du tableau
    textcolor(14);
    gotoxy(10, row);
    printf("╚═══════╩══════════════════════╩══════════╩══════════╩══════════╩══════════╩════════════════════╩════════════════════╩══════════════╝");

    fclose(file);

    // Message de fin
    textcolor(10);
    gotoxy(40, row + 2);
    printf("Press any key to return to the menu...");
    textcolor(7);
    getch();
}

// Delete a medicine by ID
void delete_med(med_list **list, char id[]) {
    system("cls");
    box(); // Draw the box

    if (*list == NULL) {
        gotoxy1(4, 3);
        setTextColor(4); // Red for error
        printf("The list is empty !!\n");
        setTextColor(7);
        return;
    }

    FILE *file = fopen("medicines.txt", "w");
    if (file == NULL) {
        gotoxy1(4, 3);
        setTextColor(4);
        printf("Failed to open the file\n");
        setTextColor(7);
        exit(1);
    }

    med_list *temp = *list;
    med_list *prev = NULL;
    int found = 0;

    while (temp != NULL) {
        if (strcmp(temp->data.id, id) == 0) {
            found = 1;
            if (prev == NULL) {
                *list = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    med_list *current = *list;
    while (current != NULL) {
        fprintf(file, "%s %s %d %d %d %.2f %.2f %.2f %s %s\n",
                current->data.id, current->data.medi_name, current->data.quantity,
                current->data.id_prescription, current->data.quantity_sold, current->data.cost,
                current->data.profit, current->data.purchase_price, current->data.exp_date, current->data.supplier_name);
        current = current->next;
    }

    fclose(file);

    if (found) {
        gotoxy1(4, 3);
        setTextColor(2); // Green for success
        printf("Item with ID %s successfully deleted!\n", id);
    } else {
        gotoxy1(4, 3);
        setTextColor(4); // Red for error
        printf("Item with ID %s not found!\n", id);
    }
    setTextColor(7); // Reset to white
}
void menuP3() {
    system("cls");

    textcolor(14);
    for (int i = 3; i <= 25; i++) {
        gotoxy(20, i); printf("║");
        gotoxy(90, i); printf("║");
    }
    for (int i = 20; i <= 90; i++) {
        gotoxy(i, 3); printf("═");
        gotoxy(i, 25); printf("═");
    }
    gotoxy(20, 3); printf("╔");
    gotoxy(90, 3); printf("╗");
    gotoxy(20, 25); printf("╚");
    gotoxy(90, 25); printf("╝");


    textcolor(2);
    gotoxy(30, 4);
    printf("=====================================================");


    textcolor(10);
    gotoxy(30, 5);
    printf("      THIS IS THE ADMINISTRATION OF MIDICAL STORE        ");
    gotoxy(30, 6);
    textcolor(2);
    printf("======================================================");
        gotoxy1(40, 8);
        setTextColor(2); // Green
        printf("---Medicine Inventory Management---\n");
        setTextColor(7); // Reset to white
        gotoxy1(40, 10);
        printf("1. Add new Medicine");
        gotoxy1(40, 12);
        printf("2. Display Medicines");
        gotoxy1(40, 14);
        printf("3. Delete Medicine");
        gotoxy1(40, 16);
        printf("4. Exit ");
    textcolor(7);
}
// Main menu for medicines
void medication_menu() {
    med_list *list = NULL;
    char choice;
    char id[10];
      medical med;
    do {
    system("cls");
    menuP3();
    printf("\n\n\n\t\tPress the correct number  .........?\t");
    gotoxy(30, 18);
    textcolor(1);
    choice=toupper(getche());
        switch (choice) {
       case '1': {

    int isValid = 0;
    system("cls");
    box();
    textcolor(14);
    gotoxy1(30, 5);
    printf("--Enter Medicine ID (max 5 chars): ");
    scanf("%5s", med.id);

    // Validation pour le nom du médicament (seulement des lettres et taille max)
    do {
        gotoxy1(30, 6);
        printf("--Enter Medicine Name (only letters): ");
        scanf("%19s", med.medi_name);
        isValid = 1;
        for (int i = 0; med.medi_name[i] != '\0'; i++) {
            if (!isalpha(med.medi_name[i])) { // Vérifie si ce n'est pas une lettre
                isValid = 0;
                break;
            }
        }
        if (!isValid) {
            gotoxy1(30, 7);
            textcolor(12); // Rouge pour erreur
            printf("Invalid name. Please use only letters.\n");
            textcolor(14); // Retour à la couleur par défaut
        }
    } while (!isValid);

    // Validation pour la quantité (doit être un entier positif)
    do {
        gotoxy1(30, 8);
        printf("--Enter Quantity (positive number): ");
        scanf("%d", &med.quantity);
        if (med.quantity < 0) {
            gotoxy1(30, 9);
            textcolor(12);
            printf("Invalid quantity. It must be positive.\n");
            textcolor(14);
        }
    } while (med.quantity < 0);

    // Validation pour Prescription ID (doit être un entier positif)
    do {
        gotoxy1(30, 10);
        printf("--Enter Prescription ID (positive number): ");
        scanf("%d", &med.id_prescription);
        if (med.id_prescription < 0) {
            gotoxy1(30, 11);
            textcolor(12);
            printf("Invalid Prescription ID. It must be positive.\n");
            textcolor(14);
        }
    } while (med.id_prescription < 0);

    // Validation pour la quantité vendue
    do {
        gotoxy1(30, 12);
        printf("--Enter Quantity Sold (positive number): ");
        scanf("%d", &med.quantity_sold);
        if (med.quantity_sold < 0) {
            gotoxy1(30, 13);
            textcolor(12);
            printf("Invalid quantity sold. It must be positive.\n");
            textcolor(14);
        }
    } while (med.quantity_sold < 0);

    // Les autres champs (comme cost, profit, purchase_price) peuvent aussi être validés
    do {
        gotoxy1(30, 14);
        printf("--Enter Cost (positive number): ");
        scanf("%f", &med.cost);
        if (med.cost < 0) {
            gotoxy1(15, 15);
            textcolor(12);
            printf("Invalid cost. It must be positive.\n");
            textcolor(14);
        }
    } while (med.cost < 0);

    do {
        gotoxy1(30, 16);
        printf("--Enter Profit (positive number): ");
        scanf("%f", &med.profit);
        fflush(stdin);
        if (med.profit < 0) {
            gotoxy1(30, 17);
            textcolor(12);
            printf("Invalid profit. It must be positive.\n");
            textcolor(14);
        }
    } while (med.profit < 0);

    gotoxy1(30, 18);
    printf("--Enter Expiry Date (dd/mm/yyyy): ");
    scanf("%14s", med.exp_date); // Tu peux ajouter une validation pour la date au besoin

    gotoxy1(30, 19);
    printf("--Enter Supplier Name: ");
    scanf("%29s", med.supplier_name);
    fflush(stdin);
    // Insertion dans la liste
    insert_med(&list, med);
    break;
}

            case '2':
                display_Medicines();
                break;
            case '3':
                system("cls");
                box();
                textcolor(2);
                gotoxy1(40, 5);
                printf("----Enter Medicine ID to delete---- ");
                scanf("%s", id);
                textcolor(15);
                delete_med(&list, id);
                break;
            case '4':
                box();
                system("cls");
                gotoxy(30,10);
                textcolor(4);
                printf("Exit !!");
                main_menu();
                break;
            default:
                gotoxy1(30, 15);
                printf("Invalid choice, try again.\n");
                break;
        }
        getch(); // Wait for user input
    } while (choice != '6');
}

#endif // MEDICAL_H_INCLUDED

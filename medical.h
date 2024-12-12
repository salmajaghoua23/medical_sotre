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
#include"interface.h"
// Medical structure
typedef struct {
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
} medical;

// Linked list structure
typedef struct node {
    medical data;
    struct node *next;
} med_list;
 medical med;
// Insert a new medicine
void insert_med(med_list **list, medical med) {
    FILE *file = fopen("medicines.txt", "a+");
    if (file == NULL) {
        box2();
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

// Display medicines with pagination
void display_meds(med_list **list) {
    system("cls");
    box2(); // Dessine la boîte

    FILE *file = fopen("medicines.txt", "r");
    if (file == NULL) {
        gotoxy1(4, 3); // Position dans la boîte
        setTextColor(4); // Rouge pour les avertissements
        printf("Erreur : Impossible d'ouvrir le fichier des médicaments.\n");
        setTextColor(7); // Blanc par défaut
        return;
    }

    // Charger les données dans la liste si elle est vide
    if (*list == NULL) {
        medical med;
        while (fscanf(file, "%s %s %d %d %d %f %f %f %s %s",
                      med.id, med.medi_name, &med.quantity, &med.id_prescription, &med.quantity_sold,
                      &med.cost, &med.profit, &med.purchase_price, med.exp_date, med.supplier_name) != EOF) {
            insert_med(list, med);
        }
    }

    fclose(file);

    // Vérifier si la liste est vide
    if (*list == NULL) {
        gotoxy1(4, 3); // Position dans la boîte
        setTextColor(4); // Rouge pour les avertissements
        printf("La liste est vide.\n");
        setTextColor(7); // Blanc par défaut
        return;
    }

    // Affichage des titres de la table
    gotoxy1(4, 3); // Début des titres dans la boîte
    setTextColor(2); // Vert pour les titres
    printf(" ID    | Name         | Qty | PrescID | Sold | Cost   | Profit | Exp. Date   ");
    gotoxy1(4, 4);
    printf("--------------------------------------------------------------------");
    setTextColor(7); // Blanc par défaut

    // Affichage des données avec pagination
    med_list *current = *list;
    int row = 5;  // Première ligne après les titres
    int page = 1;

    while (current != NULL) {
        gotoxy1(4, row);
        printf(" %-5s | %-12s | %-3d | %-7d | %-4d | %-6.2f | %-6.2f | %-11s ",
               current->data.id, current->data.medi_name, current->data.quantity,
               current->data.id_prescription, current->data.quantity_sold,
               current->data.cost, current->data.profit, current->data.exp_date);

        current = current->next;
        row++;

        // Si la ligne dépasse les limites de la boîte, passer à la page suivante
        if (row == 22) { // Limite pour 18 lignes de données dans une boîte
            gotoxy1(4, row);
            printf("Appuyez sur une touche pour continuer...");
            getch();
            system("cls");
            box2();

            // Réinitialiser les titres pour la nouvelle page
            gotoxy1(4, 3);
            setTextColor(2); // Vert pour les titres
            printf(" ID    | Name         | Qty | PrescID | Sold | Cost   | Profit | Exp. Date   ");
            gotoxy1(4, 4);
            printf("---------------------------------------------------------------------");
            setTextColor(7); // Blanc par défaut
            row = 5; // Recommencer en bas
            page++;
        }
    }

    gotoxy1(4, row);
    printf("\n\n\n\n\n\n\n\n\tFin de la liste. Total pages : %d\n", page);
}

// Delete a medicine by ID
void delete_med(med_list **list, char id[]) {
    system("cls");
    box2(); // Draw the box

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

// Main menu for medicines
void medication_menu() {
    med_list *list = NULL;
    char choice;
    char id[10];

    do {
        system("cls");
        box2(); // Draw the box
        gotoxy1(20, 8);
        setTextColor(2); // Green
        printf("---Medicine Inventory Management---\n");
        setTextColor(7); // Reset to white
        gotoxy1(20, 10);
        printf("1. Add new Medicine");
        gotoxy1(20, 12);
        printf("2. Display Medicines");
        gotoxy1(20, 14);
        printf("3. Delete Medicine");
        gotoxy1(20, 16);
        printf("4. Exit ");
        gotoxy1(20, 18);

        printf("Enter choice: ");
        choice = getch();

        switch (choice) {
            case '1': {
                medical med;
                system("cls");
                box2();
                textcolor(14);
                gotoxy1(15, 5);
                printf("--Enter Medicine ID: ");
                scanf("%5s", med.id);
                gotoxy1(15, 6);
                printf("--Enter Medicine Name: ");
                scanf("%19s", med.medi_name);
                gotoxy1(15, 7);
                printf("--Enter Quantity: ");
                scanf("%d", &med.quantity);
                gotoxy1(15, 8);
                printf("--Enter Prescription ID: ");
                scanf("%d", &med.id_prescription);
                gotoxy1(15, 9);
                printf("--Enter Quantity Sold: ");
                scanf("%d", &med.quantity_sold);
                gotoxy1(15, 10);
                printf("--Enter Cost: ");
                scanf("%f", &med.cost);
                gotoxy1(15, 11);
                printf("--Enter Profit: ");
                scanf("%f", &med.profit);
                gotoxy1(15, 12);
                printf("--Enter Purchase Price: ");
                scanf("%f", &med.purchase_price);
                gotoxy1(15, 13);
                printf("--Enter Expiry Date (dd/mm/yyyy): ");
                scanf("%14s", med.exp_date);
                gotoxy1(15, 14);
                printf("--Enter Supplier Name: ");
                scanf("%29s", med.supplier_name);

                insert_med(&list, med);
                break;
            }
            case '2':
                display_meds(&list);
                break;
            case '3':
                system("cls");
                box2();
                textcolor(2);
                gotoxy1(4, 5);
                printf("----Enter Medicine ID to delete---- ");
                scanf("%s", id);
                textcolor(15);
                delete_med(&list, id);
                break;
            case '4':
                box();
                gotoxy(20,10);
                textcolor(4);
                printf("Exit !!");
                break;
            default:
                gotoxy1(4, 15);
                printf("Invalid choice, try again.\n");
                break;
        }
        getch(); // Wait for user input
    } while (choice != '6');
}




int remplisage() {
    // Déclaration d'un tableau de 15 médicaments
    medical medicines[15];
    
    // Remplissage des informations pour chaque médicament
    strcpy(medicines[0].id, "M001");
    strcpy(medicines[0].medi_name, "Aspirin");
    medicines[0].quantity = 100;
    medicines[0].id_prescription = 101;
    medicines[0].quantity_sold = 25;
    medicines[0].cost = 10.5;
    medicines[0].profit = 5.75;
    medicines[0].purchase_price = 5.0;
    medicines[0].sale_price = 15.0;
    strcpy(medicines[0].exp_date, "2025-12-31");
    strcpy(medicines[0].supplier_name, "ABC Pharma");

    strcpy(medicines[1].id, "M002");
    strcpy(medicines[1].medi_name, "Paracetamol");
    medicines[1].quantity = 200;
    medicines[1].id_prescription = 102;
    medicines[1].quantity_sold = 50;
    medicines[1].cost = 8.0;
    medicines[1].profit = 4.0;
    medicines[1].purchase_price = 4.0;
    medicines[1].sale_price = 12.0;
    strcpy(medicines[1].exp_date, "2026-06-30");
    strcpy(medicines[1].supplier_name, "XYZ Meds");

    strcpy(medicines[2].id, "M003");
    strcpy(medicines[2].medi_name, "Ibuprofen");
    medicines[2].quantity = 150;
    medicines[2].id_prescription = 103;
    medicines[2].quantity_sold = 30;
    medicines[2].cost = 12.0;
    medicines[2].profit = 6.0;
    medicines[2].purchase_price = 6.0;
    medicines[2].sale_price = 18.0;
    strcpy(medicines[2].exp_date, "2024-11-15");
    strcpy(medicines[2].supplier_name, "PharmaLife");

    strcpy(medicines[3].id, "M004");
    strcpy(medicines[3].medi_name, "Amoxicillin");
    medicines[3].quantity = 80;
    medicines[3].id_prescription = 104;
    medicines[3].quantity_sold = 40;
    medicines[3].cost = 15.0;
    medicines[3].profit = 8.0;
    medicines[3].purchase_price = 8.0;
    medicines[3].sale_price = 22.0;
    strcpy(medicines[3].exp_date, "2025-01-10");
    strcpy(medicines[3].supplier_name, "HealthCorp");

    strcpy(medicines[4].id, "M005");
    strcpy(medicines[4].medi_name, "Ciprofloxacin");
    medicines[4].quantity = 120;
    medicines[4].id_prescription = 105;
    medicines[4].quantity_sold = 35;
    medicines[4].cost = 18.0;
    medicines[4].profit = 9.5;
    medicines[4].purchase_price = 9.5;
    medicines[4].sale_price = 28.0;
    strcpy(medicines[4].exp_date, "2027-04-10");
    strcpy(medicines[4].supplier_name, "PharmaPlus");

    strcpy(medicines[5].id, "M006");
    strcpy(medicines[5].medi_name, "Metformin");
    medicines[5].quantity = 200;
    medicines[5].id_prescription = 106;
    medicines[5].quantity_sold = 70;
    medicines[5].cost = 25.0;
    medicines[5].profit = 12.0;
    medicines[5].purchase_price = 12.0;
    medicines[5].sale_price = 35.0;
    strcpy(medicines[5].exp_date, "2025-09-15");
    strcpy(medicines[5].supplier_name, "MedGlobal");

    strcpy(medicines[6].id, "M007");
    strcpy(medicines[6].medi_name, "Lisinopril");
    medicines[6].quantity = 180;
    medicines[6].id_prescription = 107;
    medicines[6].quantity_sold = 45;
    medicines[6].cost = 30.0;
    medicines[6].profit = 15.0;
    medicines[6].purchase_price = 15.0;
    medicines[6].sale_price = 45.0;
    strcpy(medicines[6].exp_date, "2026-02-20");
    strcpy(medicines[6].supplier_name, "HeartMed");

    strcpy(medicines[7].id, "M008");
    strcpy(medicines[7].medi_name, "Cetirizine");
    medicines[7].quantity = 90;
    medicines[7].id_prescription = 108;
    medicines[7].quantity_sold = 60;
    medicines[7].cost = 7.5;
    medicines[7].profit = 4.0;
    medicines[7].purchase_price = 3.5;
    medicines[7].sale_price = 10.5;
    strcpy(medicines[7].exp_date, "2026-08-01");
    strcpy(medicines[7].supplier_name, "AllergyPharm");

    strcpy(medicines[8].id, "M009");
    strcpy(medicines[8].medi_name, "Omeprazole");
    medicines[8].quantity = 50;
    medicines[8].id_prescription = 109;
    medicines[8].quantity_sold = 30;
    medicines[8].cost = 20.0;
    medicines[8].profit = 10.0;
    medicines[8].purchase_price = 10.0;
    medicines[8].sale_price = 30.0;
    strcpy(medicines[8].exp_date, "2024-12-31");
    strcpy(medicines[8].supplier_name, "GastroMed");

    strcpy(medicines[9].id, "M010");
    strcpy(medicines[9].medi_name, "Furosemide");
    medicines[9].quantity = 160;
    medicines[9].id_prescription = 110;
    medicines[9].quantity_sold = 20;
    medicines[9].cost = 5.0;
    medicines[9].profit = 2.0;
    medicines[9].purchase_price = 2.5;
    medicines[9].sale_price = 7.5;
    strcpy(medicines[9].exp_date, "2025-03-15");
    strcpy(medicines[9].supplier_name, "Diuretics Inc");

    strcpy(medicines[10].id, "M011");
    strcpy(medicines[10].medi_name, "Prednisone");
    medicines[10].quantity = 90;
    medicines[10].id_prescription = 111;
    medicines[10].quantity_sold = 40;
    medicines[10].cost = 15.0;
    medicines[10].profit = 7.5;
    medicines[10].purchase_price = 7.5;
    medicines[10].sale_price = 22.5;
    strcpy(medicines[10].exp_date, "2026-07-10");
    strcpy(medicines[10].supplier_name, "SteroidPharm");

    strcpy(medicines[11].id, "M012");
    strcpy(medicines[11].medi_name, "Losartan");
    medicines[11].quantity = 120;
    medicines[11].id_prescription = 112;
    medicines[11].quantity_sold = 60;
    medicines[11].cost = 18.0;
    medicines[11].profit = 9.0;
    medicines[11].purchase_price = 9.0;
    medicines[11].sale_price = 27.0;
    strcpy(medicines[11].exp_date, "2027-05-20");
    strcpy(medicines[11].supplier_name, "HeartCare");

    strcpy(medicines[12].id, "M013");
    strcpy(medicines[12].medi_name, "Atorvastatin");
    medicines[12].quantity = 110;
    medicines[12].id_prescription = 113;
    medicines[12].quantity_sold = 50;
    medicines[12].cost = 25.0;
    medicines[12].profit = 12.5;
    medicines[12].purchase_price = 12.5;
    medicines[12].sale_price = 37.5;
    strcpy(medicines[12].exp_date, "2026-11-25");
    strcpy(medicines[12].supplier_name, "CholesterolMed");

    strcpy(medicines[13].id, "M014");
    strcpy(medicines[13].medi_name, "Sildenafil");
    medicines[13].quantity = 130;
    medicines[13].id_prescription = 114;
    medicines[13].quantity_sold = 45;
    medicines[13].cost = 40.0;
    medicines[13].profit = 20.0;
    medicines[13].purchase_price = 20.0;
    medicines[13].sale_price = 60.0;
    strcpy(medicines[13].exp_date, "2025-01-25");
    strcpy(medicines[13].supplier_name, "PharmaMax");

    strcpy(medicines[14].id, "M015");
    strcpy(medicines[14].medi_name, "Hydrochlorothiazide");
    medicines[14].quantity = 140;
    medicines[14].id_prescription = 115;
    medicines[14].quantity_sold = 60;
    medicines[14].cost = 10.0;
    medicines[14].profit = 5.0;
    medicines[14].purchase_price = 5.0;
    medicines[14].sale_price = 15.0;
    strcpy(medicines[14].exp_date, "2026-09-10");
    strcpy(medicines[14].supplier_name, "HypertensionCare");

    // Affichage des médicaments
    for (int i = 0; i < 15; i++) {
        printf("ID: %s\n", medicines[i].id);
        printf("Name: %s\n", medicines[i].medi_name);
        printf("Quantity: %d\n", medicines[i].quantity);
        printf("Prescription ID: %d\n", medicines[i].id_prescription);
        printf("Quantity Sold: %d\n", medicines[i].quantity_sold);
        printf("Cost: %.2f\n", medicines[i].cost);
        printf("Profit: %.2f\n", medicines[i].profit);
        printf("Purchase Price: %.2f\n", medicines[i].purchase_price);
        printf("Sale Price: %.2f\n", medicines[i].sale_price);
        printf("Expiration Date: %s\n", medicines[i].exp_date);
        printf("Supplier Name: %s\n\n", medicines[i].supplier_name);
    }

    return 0;
}



#endif // MEDICAL_H_INCLUDED

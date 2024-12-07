#ifndef MEDICAL_H_INCLUDED
#define MEDICAL_H_INCLUDED

#include <conio.h>
#include <string.h>
#include <math.h>
#include <direct.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include"interface.h"

// Medical structure
struct medical {
    char id[6];
    char medi_name[20];
    int quantity;
    int id_prescription;
    int quantity_sold;
    float cost;
    float profit;
    float purchase_price;
    float sale_price;  // Nouveau champ ajout� pour le prix de vente
    char exp_date[15];
    char supplier_name[30];
};

typedef struct medical medical;

// Linked list structure
typedef struct node {
    medical data;
    struct node *next;
} med_list;

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
    box2(); // Draw the box

    FILE *file = fopen("medicines.txt", "r");
    if (file == NULL) {
        gotoxy1(4, 3); // Position inside the box
        setTextColor(4); // Red for warning
        printf("Failed to open the medicines file.\n");
        setTextColor(7); // Reset to white
        return;
    }

    // Load data from file into the list if necessary
    if (*list == NULL) {
        medical med;
        while (fscanf(file, "%s %s %d %d %d %f %f %f %s %s",
                      med.id, med.medi_name, &med.quantity, &med.id_prescription, &med.quantity_sold,
                      &med.cost, &med.profit, &med.purchase_price, med.exp_date, med.supplier_name) != EOF) {
            insert_med(list, med);
        }
    }

    fclose(file);

    // Check if the list is still empty after loading the file
    if (*list == NULL) {
        gotoxy1(4, 3); // Position inside the box
        setTextColor(4); // Red for warning
        printf("The list is empty.\n");
        setTextColor(7); // Reset to white
        return;
    }

    // Table header
    gotoxy1(4, 3); // Position inside the box
    setTextColor(2); // Green for headers
    printf("%-10s %-20s %-10s %-20s %-15s %-15s %-15s %-15s %-15s %-20s",
           "ID", "Name", "Quantity", "Prescription ID", "Sold Qty", "Cost", "Profit", "Purchase", "Exp. Date", "Supplier");
    gotoxy1(4, 4);
    printf("----------------------------------------------------------------------------------------------------------");
    setTextColor(7); // Reset to white

    // Display medicines with pagination
    med_list *current = *list;
    int row = 5;
    int page = 1;

    while (current != NULL) {
        gotoxy1(4, row);
        printf("%-10s %-20s %-10d %-20d %-15d %-15.2f %-15.2f %-15.2f %-15s %-20s",
               current->data.id, current->data.medi_name, current->data.quantity, current->data.id_prescription,
               current->data.quantity_sold, current->data.cost, current->data.profit, current->data.purchase_price,
               current->data.exp_date, current->data.supplier_name);

        current = current->next;
        row++;

        if (row == 24) {
            gotoxy1(4, row);
            printf("Press any key for next page...");
            getch();
            system("cls");
            box2();
            row = 5;
            page++;
        }
    }

    gotoxy1(4, row);
    printf("End of list. Total pages: %d\n", page);
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
        printf("4. Exit");
        gotoxy1(20, 18);

        printf("Enter choice: ");
        choice = getch();

        switch (choice) {
            case '1': {
                medical med;
                system("cls");
                box2();
                gotoxy1(4, 5);
                printf("Enter Medicine ID: ");
                scanf("%5s", med.id);
                gotoxy1(4, 6);
                printf("Enter Medicine Name: ");
                scanf("%19s", med.medi_name);
                gotoxy1(4, 7);
                printf("Enter Quantity: ");
                scanf("%d", &med.quantity);
                gotoxy1(4, 8);
                printf("Enter Prescription ID: ");
                scanf("%d", &med.id_prescription);
                gotoxy1(4, 9);
                printf("Enter Quantity Sold: ");
                scanf("%d", &med.quantity_sold);
                gotoxy1(4, 10);
                printf("Enter Cost: ");
                scanf("%f", &med.cost);
                gotoxy1(4, 11);
                printf("Enter Profit: ");
                scanf("%f", &med.profit);
                gotoxy1(4, 12);
                printf("Enter Purchase Price: ");
                scanf("%f", &med.purchase_price);
                gotoxy1(4, 13);
                printf("Enter Expiry Date (dd/mm/yyyy): ");
                scanf("%14s", med.exp_date);
                gotoxy1(4, 14);
                printf("Enter Supplier Name: ");
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
                gotoxy1(4, 5);
                printf("Enter Medicine ID to delete: ");
                scanf("%s", id);
                delete_med(&list, id);
                break;
            case '4':
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




#endif // MEDICAL_H_INCLUDED

#ifndef SUPPLIER_H_INCLUDED
#define SUPPLIER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include"interface.h"
// Defining the structures
struct supplier {
    int supp_id;
    char supp_name[25];
    char city[20];
    char mob_no[11];
    char email[30];
};
typedef struct supplier Supplier;

typedef struct str1 {
    Supplier data;
    struct str1 *next;
} *list1;

// Function prototypes
void insert_at_end_supplier(list1 *l, Supplier temp1);
void delete_supplier(list1 *l, int supp_id);
void display_suppliers(list1 l);
void load_suppliers(list1 *l);
void supplier_menu();
void gotoxy2(int x, int y);  // Change the name here
void box();

// Function to insert a supplier at the end of the list
void insert_at_end_supplier(list1 *l, Supplier temp1) {
    FILE *p = fopen("supplier.txt", "a+");
    if (p == NULL) {
        printf("Error opening file\n");
        return;
    }

    list1 b = (list1)malloc(sizeof(struct str1));
    if (b == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    b->data = temp1;
    b->next = NULL;

    if (*l == NULL) {
        *l = b;
    } else {
        list1 tp = *l;
        while (tp->next != NULL) {
            tp = tp->next;
        }
        tp->next = b;
    }

    fprintf(p, "%d %s %s %s %s\n", temp1.supp_id, temp1.supp_name, temp1.city, temp1.mob_no, temp1.email);
    fclose(p);
}

// Function to delete a supplier
void delete_supplier(list1 *l, int supp_id) {
    if (*l == NULL) {
        printf("The list is empty!\n");
        return;
    }

    FILE *p = fopen("supplier.txt", "w");
    if (p == NULL) {
        printf("Error opening file\n");
        return;
    }

    list1 current = *l;
    list1 prev = NULL;
    int found = 0;

    while (current != NULL) {
        if (current->data.supp_id == supp_id) {
            found = 1;
            if (prev == NULL) {
                *l = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Supplier with ID %d deleted successfully!\n", supp_id);
            break;
        }
        prev = current;
        current = current->next;
    }

    if (!found) {
        printf("Supplier with ID %d not found!\n", supp_id);
    }

    list1 temp = *l;
    while (temp != NULL) {
        fprintf(p, "%d %s %s %s %s\n", temp->data.supp_id, temp->data.supp_name, temp->data.city, temp->data.mob_no, temp->data.email);
        temp = temp->next;
    }

    fclose(p);
}

// Function to display all suppliers
void display_suppliers(list1 l) {
    if (l == NULL) {
        printf("The supplier list is empty!\n");
        return;
    }

    printf("List of Suppliers:\n");
    printf("ID\tName\tCity\tPhone\tEmail\n");
    printf("-----------------------------------------------------\n");
    while (l != NULL) {
        printf("%d\t%s\t%s\t%s\t%s\n",
               l->data.supp_id,
               l->data.supp_name,
               l->data.city,
               l->data.mob_no,
               l->data.email);
        l = l->next;
    }
}

// Function to load suppliers from a file
void load_suppliers(list1 *l) {
    FILE *p = fopen("supplier.txt", "r");
    if (p == NULL) {
        printf("Unable to open the suppliers file.\n");
        return;
    }

    Supplier temp1;
    while (fscanf(p, "%d %s %s %s %s",
                  &temp1.supp_id,
                  temp1.supp_name,
                  temp1.city,
                  temp1.mob_no,
                  temp1.email) != EOF) {
        insert_at_end_supplier(l, temp1);
    }
    fclose(p);
    printf("Suppliers loaded from the file successfully!\n");
}

// Function to move cursor to specific coordinates (renamed gotoxy2)
void gotoxy3(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Function to draw a simple box around the menu
// Main menu function
void supplier_menu() {
    list1 l = NULL;
    char ch;

    // Load suppliers from file
    load_suppliers(&l);

    do {
        system("cls");
        gotoxy3(34, 3);
        printf("---------------------");
        gotoxy3(35, 4);
        printf("----Supplier MENU----");
        gotoxy3(34, 5);
        printf("---------------------");

        box(); // Draw the box
        gotoxy3(26, 8);
        printf("1- Add New Supplier");
        gotoxy3(26, 10);
        printf("2- Display All Suppliers");
        gotoxy3(26, 12);
        printf("3- Delete Supplier");
        gotoxy3(26, 14);
        printf("4- Quit");

        gotoxy3(26, 18);
        printf("Press a key for operation...");

        ch = toupper(getche()); // Get user input

        switch (ch) {
            case '1': {
                Supplier temp1;
                system("cls");
                box();
                gotoxy3(10, 3);
                printf("=== Add a New Supplier ===");
                gotoxy3(10, 5);
                printf("ID: ");
                scanf("%d", &temp1.supp_id);
                gotoxy3(10, 7);
                printf("Name: ");
                scanf("%s", temp1.supp_name);
                gotoxy3(10, 9);
                printf("City: ");
                scanf("%s", temp1.city);
                gotoxy3(10, 11);
                printf("Phone: ");
                scanf("%s", temp1.mob_no);
                gotoxy3(10, 13);
                printf("Email: ");
                scanf("%s", temp1.email);

                insert_at_end_supplier(&l, temp1);
                system("pause");
                break;
            }
            case '2':
                system("cls");
                box();
                display_suppliers(l);
                system("pause");
                break;
            case '3': {
                int id_deletion;
                system("cls");
                box();
                gotoxy3(10, 3);
                printf("=== Delete a Supplier ===");
                gotoxy3(10, 5);
                printf("Enter Supplier ID to delete: ");
                scanf("%d", &id_deletion);
                delete_supplier(&l, id_deletion);
                system("pause");
                break;
            }
            case '4':
                printf("\nExiting Supplier Menu...\n");
                break;
            default:
                printf("\nPlease enter a valid option.\n");
                system("pause");
        }
    } while (ch != '4');
}

#endif

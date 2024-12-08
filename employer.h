#ifndef EMPLOYER_H_INCLUDED
#define EMPLOYER_H_INCLUDED

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

// === Structures ===
typedef struct Employe {
    int employeID;
    char nom[50];
    char role[50];
    char contact[100];
    float salaire;
    struct Employe *next;
} Employe;

typedef struct str {
    Employe data;
    struct str *suivant;
} *liste;
void draw_box(int x, int y, int width, int height) {
    gotoxy(x, y);
    printf("%c", 201);
    for (int i = 0; i < width - 2; i++) printf("%c", 205);
    printf("%c", 187);

    for (int i = 1; i < height - 1; i++) {
        gotoxy(x, y + i);
        printf("%c", 186);
        gotoxy(x + width - 1, y + i);
        printf("%c", 186);
    }

    gotoxy(x, y + height - 1);
    printf("%c", 200);
    for (int i = 0; i < width - 2; i++) printf("%c", 205);
    printf("%c", 188);
}
// === Main Functions ===
void insererfin(liste *l, Employe e1) {
    FILE *p = fopen("employer.txt", "a+");
    if (p == NULL) {
        printf("Error opening file\n");
        return;
    }

    liste b = (liste)malloc(sizeof(struct str));
    if (b == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    b->data = e1;
    b->suivant = NULL;

    if (*l == NULL) {
        *l = b;
    } else {
        liste tp = *l;
        while (tp->suivant != NULL) {
            tp = tp->suivant;
        }
        tp->suivant = b;
    }

    fprintf(p, "%d %s %s %s %.2f\n", e1.employeID, e1.nom, e1.role, e1.contact, e1.salaire);
    fclose(p);

    textcolor(10); // Green for success
    printf("\nEmployee added successfully!\n");
    textcolor(7); // Default color
}
void afficher_tous_les_employes(liste l) {
    const int LINES_PER_PAGE = 10; // Nombre de lignes � afficher par page
    system("cls");

    FILE *p = fopen("employer.txt", "r");
    if (p == NULL) {
        draw_box(5, 2, 70, 10);
        gotoxy(10, 5);
        printf("Error: Could not open file 'employer.txt'\n");
        gotoxy(10, 6);
        printf("No employees to display.\n");
        gotoxy(10, 8);
        system("pause");
        return;
    }

    int employeID;
    char nom[50], role[50], contact[100];
    float salaire;

    int totalEmployees = 0;   // Compteur pour les employ�s
    int page = 1;             // Page actuelle
    char choice;              // Choix de l'utilisateur pour naviguer

    do {
        system("cls");
        draw_box(5, 2, 70, 20);

        // Afficher l'en-t�te
        textcolor(11); // Cyan for title
        gotoxy(10, 3);
        printf("=== List of All Employees (Page %d) ===", page);
        textcolor(7); // Default color
        gotoxy(8, 5);
        printf("+-----------------------------------------------------------+");
        gotoxy(8, 6);
        printf("| ID   | Name               | Role         | Salary        |");
        gotoxy(8, 7);
        printf("+-----------------------------------------------------------+");

        // Afficher les lignes de la page
        int line = 8;
        int displayed = 0; // Nombre de lignes affich�es sur la page

        // Avancer le curseur dans le fichier selon la page
        rewind(p);
        for (int skip = 0; skip < (page - 1) * LINES_PER_PAGE; skip++) {
            if (fscanf(p, "%d %[^\n] %[^\n] %[^\n] %f", &employeID, nom, role, contact, &salaire) != 5) {
                break; // Fin du fichier atteinte
            }
        }

        // Lire les employ�s pour cette page
        while (fscanf(p, "%d\t%[^\n]\t%[^\n]\t%[^\n]\t%f\n", &employeID, nom, role, contact, &salaire) == 5) {
            gotoxy(8, line++);
            printf("| %-4d | %-20s | %-12s | %-12.2f |", employeID, nom, role, salaire);
            displayed++;
            totalEmployees++;

            if (displayed >= LINES_PER_PAGE) {
                break; // Rempli la page
            }
        }

        // Afficher une ligne de s�paration en bas
        gotoxy(8, line);
        printf("+-----------------------------------------------------------+");

        // Options de navigation

        printf("\n\n\n\n\n\tPress (N)ext, (P)revious, or (Q)uit:\t ");
        choice = toupper(getch());

        if (choice == 'N') {
            page++;
        } else if (choice == 'P' && page > 1) {
            page--;
        }
    } while (choice != 'Q');

    fclose(p);

    gotoxy(10, 22);
    printf("End of employee list.\n");

    system("pause");
}

void supprimer_employe(liste *l, int employeID) {
    if (*l == NULL) {
        printf("The list is empty!\n");
        return;
    }

    FILE *p = fopen("employer.txt", "w");
    if (p == NULL) {
        printf("Error opening file\n");
        return;
    }

    liste current = *l;
    liste prev = NULL;
    int found = 0;

    while (current != NULL) {
        if (current->data.employeID == employeID) {
            found = 1;
            if (prev == NULL) {
                *l = current->suivant;
            } else {
                prev->suivant = current->suivant;
            }
            free(current);
            textcolor(12); // Red for deletion
            printf("Employee with ID %d deleted successfully!\n", employeID);
            textcolor(7); // Default color
            break;
        }
        prev = current;
        current = current->suivant;
    }

    if (!found) {
        printf("Employee with ID %d not found!\n", employeID);
    }

    liste temp = *l;
    while (temp != NULL) {
        fprintf(p, "%d %s %s %s %.2f\n", temp->data.employeID, temp->data.nom, temp->data.role, temp->data.contact, temp->data.salaire);
        temp = temp->suivant;
    }

    fclose(p);
}

void menu_employer(liste *l) {
    int choix, id_suppression;
    Employe e1;

    do {
        system("cls");
        draw_box(5, 2, 70, 20);
        textcolor(14); // Yellow for title
        gotoxy(30, 3);
        printf("---EMPLOYEE MANAGEMENT MENU---");
        textcolor(7); // Default color

        gotoxy(10, 6);
        printf("1. Add an employee");
        gotoxy(10, 8);
        printf("2. Display all employees");
        gotoxy(10, 10);
        printf("3. Delete an employee");
        gotoxy(10, 12);
        printf("4. Quit");

        gotoxy(10, 15);
        printf("Enter your choice: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                system("cls");
                draw_box(5, 2, 70, 10);
                gotoxy(10, 3);
                printf("=== Add a New Employee ===");
                gotoxy(10, 5);
                printf("Enter Employee ID: ");
                scanf("%d", &e1.employeID);
                gotoxy(10, 6);
                printf("Enter Name: ");
                scanf(" %[^\n]s", e1.nom);
                gotoxy(10, 7);
                printf("Enter Role: ");
                scanf(" %[^\n]s", e1.role);
                gotoxy(10, 8);
                printf("Enter Contact: ");
                scanf("%s", e1.contact);
                gotoxy(10,9);

                printf("Enter Salary: ");
                scanf("%f", &e1.salaire);

                insererfin(l, e1);
                system("pause");
                break;

            case 2:
                afficher_tous_les_employes(*l);
                break;

            case 3:
                system("cls");
                draw_box(5, 2, 70, 10);
                gotoxy(10, 3);
                printf("=== Delete an Employee ===");
                gotoxy(10, 5);
                printf("Enter Employee ID to delete: ");
                scanf("%d", &id_suppression);
                supprimer_employe(l, id_suppression);
                system("pause");
                break;

            case 4:
                textcolor(14);
                printf("Thank you for using the program!\n");
                textcolor(7);
                break;

            default:
                textcolor(12); // Red for error
                printf("Invalid choice, please try again!\n");
                textcolor(7);
                system("pause");
                break;
        }
    } while (choix != 4);
}
#endif

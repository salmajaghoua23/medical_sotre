#ifndef EMPLOYER_H_INCLUDED
#define EMPLOYER_H_INCLUDED
#include"interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include"menu_adm.h"
typedef struct Employe {
    int employeID;
    char nom[50];
    char role[50];
    char contact[100];
    float salaire;
    struct Employe *next;
} Employe;
void notification_menu();
typedef struct str {
    Employe data;
    struct str *suivant;
} *liste;
void main_menu();
void gotoxy1(int x, int y) ;
 void gotoxy(int x,int y);
void textcolor(int color) ;
 void menu_employer();
void box();
// === Déclaration des structures ===

// === Fonctions principales ===
void insererfin(liste *l, Employe e1) {
    FILE *p = fopen("employer.txt", "a");
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

    textcolor(10); // Vert pour le succès
    printf("\nEmployé ajouté avec succès !\n");
    textcolor(7); // Couleur par défaut
}

void afficher_tous_les_employes(liste l) {
    FILE *p = fopen("employer.txt", "r+");
    if (p == NULL) {
        box();
        gotoxy1(10, 5);
        printf("Erreur : Impossible opnenig this file  'employer.txt'.");
        gotoxy1(10, 7);
        printf("Aucun employé à afficher.");
        return;
    }

    system("cls");
    box();

    gotoxy1(40, 5);
    textcolor(11); // Cyan pour le titre
    printf("=== Liste de tous les employés ===");
    textcolor(7);

    int employeID;
    char nom[50], role[50], contact[100];
    float salaire;
    int line = 5;

    while (fscanf(p, "%d %[^\n] %[^\n] %[^\n] %f", &employeID, nom, role, contact, &salaire) == 5) {
        gotoxy1(20, line++);
        printf("ID: %d | Nom: %s | Role: %s | Salaire: %.2f", employeID, nom, role, salaire);
    }

    fclose(p);
    gotoxy1(20, line + 2);
    printf("\n\n\n\n\n\n\n\t\tFin de la liste.");
    system("pause");
}

void supprimer_employe(liste *l, int employeID) {
    if (*l == NULL) {
        printf("La liste est vide !\n");
        return;
    }

    FILE *p = fopen("employer.txt", "w");
    if (p == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }

    liste current = *l, prev = NULL;
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
            textcolor(12); // Rouge pour suppression
            printf("Employé avec ID %d supprimé avec succès !\n", employeID);
            textcolor(7);
            break;
        }
        prev = current;
        current = current->suivant;
    }

    if (!found) {
        printf("Employé avec ID %d non trouvé !\n", employeID);
    }

    liste temp = *l;
    while (temp != NULL) {
        fprintf(p, "%d %s %s %s %.2f\n", temp->data.employeID, temp->data.nom, temp->data.role, temp->data.contact, temp->data.salaire);
        temp = temp->suivant;
    }

    fclose(p);
}
/*
void menu_employer(liste *l) {
    int choix, id_suppression;
    Employe e1;

    do {
        system("cls");
        box();
        gotoxy1(40, 8);
        textcolor(2); 
        printf("--- MENU GESTION DES EMPLOYÉS ---");
        textcolor(15);

        gotoxy1(40, 10); printf("1. Add employer");
        gotoxy1(40, 12); printf("2. Display employers");
        gotoxy1(40, 14); printf("3.Delete employer");
        gotoxy1(40, 16); printf("4. Exit");

        gotoxy1(20, 18);
        textcolor(1);
        printf("\tEntre your choice : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                system("cls");
                box();
                gotoxy1(40, 3);
                printf("=== Add a  new  employer ===");
                gotoxy1(30, 5);
                printf("ID : "); scanf("%d", &e1.employeID);
                gotoxy1(30, 6);
                printf("Nom : "); scanf(" %[^\n]", e1.nom);
                gotoxy1(30, 7);
                printf("Role : "); scanf(" %[^\n]", e1.role);
                gotoxy1(30, 8);
                printf("Contact : "); scanf("%s", e1.contact);
                gotoxy1(30, 9);
                printf("Salaire : "); scanf("%f", &e1.salaire);
           
                insererfin(l, e1);
                system("pause");
                sleep(1000);
                break;

            case 2:system("cls");
                box();
                afficher_tous_les_employes(*l);
                break;

            case 3:
                system("cls");
                box();
                gotoxy1(40, 3);
                printf("=== Delete  a employer ===");
                gotoxy1(20, 5);
                printf("Entre ID a delete of  employer: ");
                scanf("%d", &id_suppression);
                supprimer_employe(l, id_suppression);
                system("pause");
                break;

            case 4:
                printf("Thank you for your visite  !");
                main_menu();
                break;

            default:
                textcolor(12); // Rouge pour erreur
                printf("Invalide choice .... !");
                textcolor(7);
                system("pause");
        }
    } while (choix != 4);
}
*/
liste employes = NULL;
void menu_employer() {
    int choix, id_suppression;
    Employe e1;

    do {
        system("cls");
        box();
        gotoxy(30,8);
        printf("=== MENU GESTION DES EMPLOYÉS ===\n");
          gotoxy(40,10);
                textcolor(15);
        printf("1. Add employer\n");
          gotoxy(40,12);
                textcolor(15);
        printf("2. Display employers\n");
          gotoxy(40,14);
                textcolor(15);
        printf("3. Delete employer\n");
          gotoxy(40,16);
                textcolor(15);
        printf("4. Exit\n");
  gotoxy(40,18);
                textcolor(5);
        printf("Enter your choice: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                system("cls");
                box();
                gotoxy(30,8);
                textcolor(2);
                printf("=== Add a new employer ===\n");
                gotoxy(40,10);
                textcolor(15);
                printf("ID: "); scanf("%d", &e1.employeID);
                gotoxy(40,12);
                textcolor(15);
                printf("Name: "); scanf(" %[^\n]", e1.nom);
                gotoxy(40,14);
                textcolor(15);
                printf("Role: "); scanf(" %[^\n]", e1.role);
                gotoxy(40,16);
                textcolor(15);
                printf("Contact: "); scanf("%s", e1.contact);
                gotoxy(40,18);
                textcolor(15);
                printf("Salary: "); scanf("%f", &e1.salaire);

                insererfin(&employes, e1);
                printf("Employee added successfully!\n");
                system("pause");
                break;

            case 2:
                system("cls");
             box();
             gotoxy(30,12);
             textcolor(2);
                afficher_tous_les_employes(employes);
                system("pause");
                break;

            case 3:
            system("cls");
             box();
             gotoxy(30,8);
             textcolor(2);
                printf("=== Delete an employer ===\n");
                gotoxy(40,10);
                textcolor(7);
                printf("Enter the ID of the employer to delete: ");
                scanf("%d", &id_suppression);
                supprimer_employe(&employes, id_suppression);
                system("pause");
                break;

            case 4:
            system("cls");
             box();
             gotoxy(30,12);
             textcolor(2);
                printf("Thank you for your visit!\n");
                break;

            default:
            system("cls");
             box();
             gotoxy(30,12);
             textcolor(4);
                printf("Invalid choice, try again!\n");
                system("pause");
        }
    } while (choix != 4);
}

#endif
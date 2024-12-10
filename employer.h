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

// === Déclaration des structures ===
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

    gotoxy1(10, 3);
    textcolor(11); // Cyan pour le titre
    printf("=== Liste de tous les employés ===");
    textcolor(7);

    int employeID;
    char nom[50], role[50], contact[100];
    float salaire;
    int line = 5;

    while (fscanf(p, "%d %[^\n] %[^\n] %[^\n] %f", &employeID, nom, role, contact, &salaire) == 5) {
        gotoxy1(5, line++);
        printf("ID: %d | Nom: %s | Role: %s | Salaire: %.2f", employeID, nom, role, salaire);
    }

    fclose(p);
    gotoxy1(5, line + 2);
    printf("\n\n\n\n\tFin de la liste.");
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

void menu_employer(liste *l) {
    int choix, id_suppression;
    Employe e1;

    do {
        system("cls");
        box();
        gotoxy1(25, 8);
        textcolor(2); 
        printf("--- MENU GESTION DES EMPLOYÉS ---");
        textcolor(15);

        gotoxy1(20, 10); printf("1. Add employer");
        gotoxy1(20, 12); printf("2. Display employers");
        gotoxy1(20, 14); printf("3.Delete employer");
        gotoxy1(20, 16); printf("4. Exit");

        gotoxy1(20, 25);
        printf("Entre your choice : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                system("cls");
                box();
                gotoxy1(10, 3);
                printf("=== Add a  new  employer ===");
                gotoxy1(10, 5);
                printf("ID : "); scanf("%d", &e1.employeID);
                gotoxy1(10, 6);
                printf("Nom : "); scanf(" %[^\n]", e1.nom);
                gotoxy1(10, 7);
                printf("Role : "); scanf(" %[^\n]", e1.role);
                gotoxy1(10, 8);
                printf("Contact : "); scanf("%s", e1.contact);
                gotoxy1(10, 9);
                printf("Salaire : "); scanf("%f", &e1.salaire);

                insererfin(l, e1);
                system("pause");
                break;

            case 2:system("cls");
                box();
                afficher_tous_les_employes(*l);
                break;

            case 3:
                system("cls");
                box();
                gotoxy1(10, 3);
                printf("=== Delete  a employer ===");
                gotoxy1(10, 5);
                printf("Entre ID a delete of  employer: ");
                scanf("%d", &id_suppression);
                supprimer_employe(l, id_suppression);
                system("pause");
                break;

            case 4:
                printf("Thank you for your visite  !");
                break;

            default:
                textcolor(12); // Rouge pour erreur
                printf("Invalide choice .... !");
                textcolor(7);
                system("pause");
        }
    } while (choix != 4);
}


#endif
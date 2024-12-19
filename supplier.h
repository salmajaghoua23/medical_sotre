#ifndef SUPPLIER_H_INCLUDED
#define SUPPLIER_H_INCLUDED

#include "menu_adm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>
#include "interface.h"

// Définition de la structure Supplier
struct supplier {
    int supp_id;
    char supp_name[25];
    char city[20];
    char mob_no[11];  // Le numéro de téléphone doit contenir 10 chiffres
    char email[30];
};
typedef struct supplier Supplier;

typedef struct str1 {
    Supplier data;
    struct str1 *next;
} *list1;

// Prototypes des fonctions
void insert_at_end_supplier(list1 *l, Supplier temp1);
void delete_supplier(list1 *l, int supp_id);
void display_suppliers();
void load_suppliers(list1 *l);
void supplier_menu();
void gotoxy3(int x, int y);
void box();

// Fonction pour vérifier si un numéro de téléphone est valide
int validate_phone_number(char *mob_no) {
    if (strlen(mob_no) != 10) return 0;  // Le numéro doit avoir 10 chiffres
    for (int i = 0; i < 10; i++) {
        if (!isdigit(mob_no[i])) return 0;  // Le numéro doit être composé de chiffres uniquement
    }
    return 1;  // Numéro valide
}

// Fonction pour vérifier si un email est valide
int validate_email(char *email) {
    // Vérifier la présence de "@" et "."
    char *at_sign = strchr(email, '@');
    char *dot_sign = strchr(email, '.');
    
    if (at_sign && dot_sign && at_sign < dot_sign) {
        return 1;  // Email valide
    }
    return 0;  // Email invalide
}

// Fonction pour vérifier si un ID fournisseur existe déjà dans le fichier
int check_supplier_id(int supp_id) {
    FILE *file = fopen("supplier.txt", "r");
    if (file == NULL) {
        printf("File 'supplier.txt' not found . .\n");
        return 0;  // Si le fichier n'existe pas, considérer l'ID comme valide
    }

    Supplier sep;
    while (fscanf(file, "%d %24s %19s %10s %29s", &sep.supp_id, sep.supp_name, sep.city, sep.mob_no, sep.email) == 5) {
        if (sep.supp_id == supp_id) {
            fclose(file);
            return 1;  // ID existe déjà
        }
    }

    fclose(file);
    return 0;  // ID valide, n'existe pas
}

// Fonction pour insérer un fournisseur dans le fichier
void insert_at_end_supplier(list1 *l, Supplier temp1) {
    if (check_supplier_id(temp1.supp_id)) {
        printf("Supplier with ID %d already exists.\n", temp1.supp_id);
        return;
    }

    if (!validate_phone_number(temp1.mob_no)) {
        printf("Invalid phone number. It must be 10 digits.\n");
        return;
    }

    if (!validate_email(temp1.email)) {
        printf("Invalid email format. It must contain '@' and '.'\n");
        return;
    }

    FILE *p = fopen("supplier.txt", "a+");
    if (p == NULL) {
        printf("Error opening file\n");
        return;
    }

    fprintf(p, "%d %s %s %s %s\n", temp1.supp_id, temp1.supp_name, temp1.city, temp1.mob_no, temp1.email);
    fclose(p);
    printf("Supplier added successfully!\n");
}

// Fonction pour afficher les fournisseurs
// Fonction pour afficher les fournisseurs avec bordure et couleurs ajustées
void display_suppliers() {
    FILE *file = fopen("supplier.txt", "r");
    if (file == NULL) {
        printf("File 'supplier.txt' not found . .\n");
        getchar(); // Pause pour Windows/Linux
        return;
    }
    system("cls");

    // Positionner l'affichage à gotoxy(20, 10)
    gotoxy3(20, 10);

    // Bordure colorée
    textcolor(14);  // Couleur bordure (jaune)
    printf("╔═════════════════════════════════════════════════════════════════════════╗\n");

    // Titre du système
    gotoxy(20, 12);
    textcolor(7);   // Couleur texte (blanc)
    printf("║                           PHARMACY SYSTEM                               ║\n");

    // Bordure du bas du titre
    gotoxy(20, 14);
    textcolor(14);  // Couleur bordure (jaune)
    printf("╚═════════════════════════════════════════════════════════════════════════╝\n");

    // Affichage des entêtes avec couleur
    gotoxy(20, 16);
    textcolor(11);  // Couleur de l'entête (cyan)
    printf("╔═══════╦══════════════════════╦══════════╦══════════╦════════════════════╗\n");

    gotoxy(20, 18);
    textcolor(11);  // Couleur de l'entête (cyan)
    printf("║  ID   ║    Supplier Name     ║  City    ║  Phone   ║  Email             ║\n");

    gotoxy(20, 20);
    textcolor(11);  // Couleur de l'entête (cyan)
    printf("╠═══════╬══════════════════════╬══════════╬══════════╬════════════════════╣\n");

    // Affichage des données des fournisseurs
    Supplier sep;
    int row = 0;
    int line_num = 22;  // La ligne où commence l'affichage des données (après l'entête)

    while (fscanf(file, "%d %24s %19s %10s %29s", &sep.supp_id, sep.supp_name, sep.city, sep.mob_no, sep.email) == 5) {
        textcolor(7);  // Couleur du texte (blanc)
        gotoxy(20, line_num);  // Positionner chaque ligne de données
        printf("║ %-5d ║ %-20s ║ %-8s ║ %-8s ║ %-18s ║\n",
               sep.supp_id, sep.supp_name, sep.city, sep.mob_no, sep.email);

        row++;
        line_num++;  // Passer à la ligne suivante pour chaque fournisseur

        if (row % 5 == 0) {
            // Après chaque 5 lignes, ajouter une ligne de séparation
            textcolor(14);  // Couleur de bordure (jaune)
            gotoxy(20, line_num);
            printf("╟───────┼──────────────────────┼──────────┼──────────┼───────────────╢\n");
            line_num++;  // Passer à la ligne suivante après la séparation
        }
    }

    // Bordure en bas
    textcolor(14);  // Couleur bordure (jaune)
    gotoxy(20, line_num);  // Placer la bordure en bas à la dernière ligne
    printf("╚═══════╩══════════════════════╩══════════╩══════════╩════════════════════╝\n");

    fclose(file);

    // Demander à l'utilisateur s'il veut revenir au menu
    printf("\nPress any key to return to the menu...");
    char c = getch();
    if (c == 'y' || c == 'Y') {
        supplier_menu();
    }
}


// Fonction pour supprimer un fournisseur
void delete_supplier(list1 *l, int supp_id) {
    FILE *file = fopen("supplier.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf("Error opening file\n");
        return;
    }

    Supplier sep;
    int found = 0;

    while (fscanf(file, "%d %24s %19s %10s %29s", &sep.supp_id, sep.supp_name, sep.city, sep.mob_no, sep.email) == 5) {
        if (sep.supp_id == supp_id) {
            found = 1;
            continue; // Ne pas écrire le fournisseur à supprimer
        }
        fprintf(temp, "%d %s %s %s %s\n", sep.supp_id, sep.supp_name, sep.city, sep.mob_no, sep.email);
    }

    fclose(file);
    fclose(temp);

    remove("supplier.txt");
    rename("temp.txt", "supplier.txt");

    if (found)
        printf("Supplier with ID %d deleted successfully!\n", supp_id);
    else
        printf("Supplier with ID %d not found!\n", supp_id);

    printf("Press any key to continue...");
    getch();
}

// Fonction pour le menu des fournisseurs
void supplier_menu() {
    char ch;
    Supplier temp1;

    do {
        system("cls");
        box();
        gotoxy3(40, 4);
        textcolor(2);
        printf("---- Supplier MENU ----");
        textcolor(7);
        gotoxy3(40, 6);
        printf("1- Add New Supplier");
        gotoxy3(40, 8);
        printf("2- Display All Suppliers");
        gotoxy3(40, 10);
        printf("3- Delete Supplier");
        gotoxy3(40, 12);
        printf("4- Quit");
        textcolor(1);
        gotoxy3(40, 14);
        printf("Enter your choice: ");
        ch = toupper(getche());
       
        switch (ch) {
            case '1':
                box();
                gotoxy(30,5);
                system("cls");
                textcolor(7);
                gotoxy(30,8);
                printf("Enter Supplier ID: ");
                scanf("%d", &temp1.supp_id);

                // Vérifier si l'ID existe déjà
                if (check_supplier_id(temp1.supp_id)) {
                    printf("Supplier with ID %d already exists.\n", temp1.supp_id);
                    break;
                }
                gotoxy(30,10);
                printf("Enter Supplier Name: ");
                scanf("%s", temp1.supp_name);
                gotoxy(30,12);
                printf("Enter City: ");
                gotoxy(30,14);
                scanf("%s", temp1.city);
                printf("Enter Phone: ");
                gotoxy(30,16);
                scanf("%s", temp1.mob_no);

                // Valider le téléphone
                if (!validate_phone_number(temp1.mob_no)) {
                    printf("Invalid phone number. It must be 10 digits.\n");
                    break;
                }
                gotoxy(30,18);
                printf("Enter Email: ");
                scanf("%s", temp1.email);

                // Valider l'email
                if (!validate_email(temp1.email)) {
                    printf("Invalid email format. It must contain '@' and '.'\n");
                    break;
                }

                insert_at_end_supplier(NULL, temp1); // Pas besoin de la liste ici
                break;

            case '2':
                display_suppliers();
                system("pause");
                break;

            case '3': {
                int id;
                system("cls");
                printf("Enter Supplier ID to delete: ");
                scanf("%d", &id);
                delete_supplier(NULL, id); // Pas besoin de la liste ici
                break;
            }

            case '4':
            box();
            gotoxy(30,10);
            textcolor(2);
            printf("\nExiting Supplier Menu...\n");
            main_menu();
                return;

            default:
                box();
                 gotoxy(30,10);
                 textcolor(14);
                printf("\nInvalid option! Try again.\n");
        }
    } while (ch != '4');
}

// Fonction pour positionner le curseur (gotoxy3)
void gotoxy3(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

#endif

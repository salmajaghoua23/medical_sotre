
#ifndef COMMANDE_H_INCLUDED
#define COMMANDE_H_INCLUDED
#include"medical.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
#include"interface.h"
#include"menu login.h"
void commande(const char *filename, const char *critere);
void commande(const char *filename, const char *critere) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        system("cls");
        textcolor(15);
        box();
        gotoxy(20, 8);
        textcolor(8);
        printf("Error: Unable to open the medication file.\n");
        Sleep(3333);
        return;
    }
    rewind(file);

    medical med;
    int found = 0; // Flag to check if the medication is found

    // Read the file line by line
    while (fscanf(file, "%s %s %d %d %d %f %f %f %s %s",
                  med.id, med.medi_name, &med.quantity, &med.id_prescription,
                  &med.quantity_sold, &med.cost, &med.profit,
                  &med.purchase_price, med.exp_date, med.supplier_name) == 10) {

        // Compare the criteria with the medication ID or name
        if (strcmp(med.id, critere) == 0 || strcmp(med.medi_name, critere) == 0) {
            found = 1; // Medication found

            if (med.quantity <= 0) {
                system("cls");
                textcolor(15);
                box();
                gotoxy(20, 8);
                textcolor(15);
                printf("Sorry, this medication is out of stock.\n");
                Sleep(1033);
                break;
            }

            if (med.id_prescription == 1) {
             //  verifyOrdonnance(); // Prescription validation if required
                break;
            }

            // Update quantity and sold quantity
            med.quantity--;
            med.quantity_sold++;

            // Display success message
            system("cls");
            textcolor(15);
            box();
            gotoxy(20, 4);
            textcolor(2);
            printf("Order placed successfully!\n");
            Sleep(2220);
            break;
        }
    }

    if (!found) {
        system("cls");
        textcolor(15);
        box();
        gotoxy(20, 8);
        textcolor(2);
        printf("No matching medication found.\n");
        Sleep(10);
    }

    fclose(file);
}
void makeOrder() {
    int choice;
    char recherche[50];
    char cont;

    do {
        // Afficher le menu de choix du type de recherche
        system("cls");
        textcolor(15);
        box();
        gotoxy(20, 10);
        textcolor(6);
        printf("Choose the type:\n\n");
        gotoxy(20, 11);
        printf("1. By name\n");
        gotoxy(20, 12);
        printf("2. By ID\n");
        gotoxy(10, 25);
        textcolor(2);
        printf("Your choice: ");
        scanf("%d", &choice);

        // Demander le critère de recherche en fonction du choix
        if (choice == 1) {
            system("cls");
            textcolor(15);
            box();
            gotoxy(20, 8);
            textcolor(6);
            printf("Enter the name of the medicine: ");
            scanf("%s", recherche);
        } else if (choice == 2) {
            system("cls");
            textcolor(15);
            box();
            gotoxy(20, 8);
            textcolor(6);
            printf("Enter the ID of the medicine: ");
            scanf("%s", recherche);
        } else {
            system("cls");
            textcolor(15);
            box();
            gotoxy(20, 8);
            textcolor(8);
            printf("Invalid choice. Please try again.\n");
            continue;  // Recommence le choix si l'utilisateur fait une erreur
        }

        // Ouvrir le fichier des médicaments pour la recherche
        FILE *file = fopen("medicines.txt", "r");
        if (file == NULL) {
            system("cls");
            textcolor(15);
            box();
            gotoxy(20, 8);
            textcolor(8);
            printf("Error: Unable to open the medications file.\n");
            sleep(8);
            return;
        }

        // Appeler la fonction commande pour traiter la recherche
        commande("medicines.txt", recherche);

        // Demander si l'utilisateur souhaite entrer un autre médicament
        printf("\nWould you like to order another medicine? (Y/N): ");
        scanf(" %c", &cont);  // L'espace avant %c est pour gérer les retours de ligne
    } while (cont == 'Y' || cont == 'y');  // Répéter tant que l'utilisateur répond par Y ou y

    // Fin de la commande
    system("cls");
    textcolor(15);
    box();
    gotoxy(20, 8);
    textcolor(6);
    printf("Thank you for your order!\n");
}

#endif
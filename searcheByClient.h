#ifndef SEARCHEBYCLIENT_H_INCLUDED
#define SEARCHEBYCLIENT_H_INCLUDED
#include"Affiche_med_cli.h"
#include"medical.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include"menu login.h"
#include"menu_adm.h"
#include"interface.h"
#include"commande.h"
#include"panier.h"
#include"client_info.h"
#include"menu_client.h"
void commande(const char *filename, const char *critere);
void add_to_cart(medical *mede);
void search_medicine() {
    char recherche[50];
    int choice;
    medical med;
    int found = 0;

    // Request search type (by name or by ID)
    system("cls");
    textcolor(15);
    box();
    gotoxy(20, 8);
    textcolor(6);

    printf("Choose the type of search:\n\n");
    gotoxy(20, 10);
    textcolor(15);
    printf("1. By name\n");
    gotoxy(20, 11);
    printf("2. By ID\n");
    gotoxy(10, 25);
    textcolor(2);
    printf("Your choice: ");

    scanf("%d", &choice);

    // Request search criterion
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
        return;
    }

    // Open the medication file for search
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

    // Read line by line
    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        // Parse the line
        if (sscanf(line, "%s %s %d %d %d %f %f %f %s %s",
                   med.id, med.medi_name, &med.quantity, &med.id_prescription,
                   &med.quantity_sold, &med.cost, &med.profit,
                   &med.purchase_price, med.exp_date, med.supplier_name) == 10) {
            if ((choice == 1 && strcmp(recherche, med.medi_name) == 0) ||
                (choice == 2 && strcmp(recherche, med.id) == 0)) {
                // If a match is found
                found = 1;
                system("cls");
                textcolor(15);
                box();
                gotoxy(20, 5);
                textcolor(2);
                printf("The medicine exists.");
                afficherInfoMedicament(&med);
                sleep(3);

                // Ask for action
                int action;
                system("cls");
                textcolor(15);
                box();
                gotoxy(20, 8);
                textcolor(2);
                printf("What do you want to do?");
                gotoxy(20, 10);
                textcolor(15);
                printf("1. Order\n");
                gotoxy(20, 11);
                printf("2. Add to cart\n");
                gotoxy(20, 12);
                printf("3. Cancel\n");
                gotoxy(10, 25);
                textcolor(2);
                printf("Your choice: ");
                scanf("%d", &action);

                switch (action) {
                    case 1:

                       fclose(file);
                        commande("medicines.txt", recherche);

                        clientiinfo();
                        break;
                    case 2:
                        add_to_cart(&med);
                        break;
                    case 3:
                        system("cls");
                        textcolor(15);
                        box();
                        gotoxy(20, 8);
                        textcolor(15);
                        printf("Action cancelled.\n");
                        break;
                    default:
                        system("cls");
                        textcolor(15);
                        box();
                        gotoxy(20, 8);
                        textcolor(8);
                        printf("Invalid choice.\n");
                }
                break;
            }
        }
    }

    // If the medicine is not found
    if (!found) {
        system("cls");
        textcolor(15);
        box();
        gotoxy(20, 8);
        textcolor(15);
        printf("Medicine not found.\n");
        sleep(8);
    }

    fclose(file);
}
#   endif
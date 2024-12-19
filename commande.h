#ifndef COMMANDE_H_INCLUDED
#define COMMANDE_H_INCLUDED
#include "medical.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
#include "interface.h"
#include "panier.h"
#include "menu login.h"

void menuBasket();
void menu_client();
void clientiinfo();
int verifyOrdonnance();
void getCurrentDate(char *date);
void makeOrder();
void commande(const char *filename, const char *critere);

// Fonction pour afficher un message d'erreur avec délai
void displayErrorMessage(const char *message) {
    system("cls");
    textcolor(15);
    box();
    gotoxy(40, 8);
    textcolor(8);
    printf("%s\n", message);
    sleep(5);
}

// Fonction pour obtenir la date actuelle au format YYYY-MM-DD
void getCurrentDate(char *date) {
    time_t t;
    struct tm *tm_info;

    // Obtenir l'heure actuelle
    time(&t);
    tm_info = localtime(&t);

    // Formater la date en 'YYYY-MM-DD' et la stocker dans 'date'
    strftime(date, 11, "%Y-%m-%d", tm_info);
}

// Fonction pour ajouter une commande
void makeOrder() {
    int choice;
    char recherche[50];
    char cont;
    int orderCount = 0;  // Variable pour suivre le nombre de médicaments dans le panier
    char panier[100][50];  // Stocke les ID des médicaments dans le panier (max 100 médicaments)

    do {
        // Afficher le menu de choix du type de recherche
        system("cls");
        textcolor(7);
        box();
        gotoxy(40, 10);
        textcolor(6);
        printf("Choose the type:\n\n");
        gotoxy(40, 11);
        printf("1. By name\n");
        gotoxy(40, 12);
        printf("2. By ID\n");
        gotoxy(30, 20);
        textcolor(2);
        printf("Your choice: ");
        scanf("%d", &choice);

        // Demander le critère de recherche en fonction du choix
        if (choice == 1) {
            system("cls");
            textcolor(15);
            box();
            gotoxy(40, 8);
            textcolor(6);
            printf("Enter the name of the medicine: ");
            scanf("%s", recherche);
        } else if (choice == 2) {
            system("cls");
            textcolor(15);
            box();
            gotoxy(40, 8);
            textcolor(6);
            printf("Enter the ID of the medicine: ");
            scanf("%s", recherche);
        } else {
            displayErrorMessage("Invalid choice. Please try again.");
            continue;  // Recommence le choix si l'utilisateur fait une erreur
        }

        // Ouvrir le fichier des médicaments pour la recherche
        FILE *file = fopen("medicines.txt", "r");
        if (file == NULL) {
            displayErrorMessage("Error: Unable to open the medications file.");
            return;
        }

        // Appeler la fonction commande pour traiter la recherche
        commande("medicines.txt", recherche);

        // Ajouter le médicament au panier (une unité par médicament)
        strcpy(panier[orderCount], recherche);  // Ajouter l'ID du médicament dans le panier
        orderCount++;  // Incrémenter le compteur de médicaments dans le panier

        // Demander si l'utilisateur souhaite ajouter un autre médicament
        printf("\nWould you like to order another medicine? (Y/N): ");
        scanf(" %c", &cont);  // L'espace avant %c est pour gérer les retours de ligne

    } while (cont == 'Y' || cont == 'y');  // Répéter tant que l'utilisateur répond par Y ou y

    // Passer la commande de tous les médicaments dans le panier
    if (orderCount > 0) {
        // Appeler la fonction commande pour chaque médicament dans le panier
        for (int i = 0; i < orderCount; i++) {
            commande("medicines.txt", panier[i]);
        }

        // Fin de la commande
        system("cls");
        textcolor(15);
        box();
        gotoxy(40, 6);
        printf("Please enter your information!\n");
        gotoxy(40, 7);
        system("pause");

        system("cls");
        textcolor(15);
        box();
        gotoxy(40, 8);
        textcolor(6);
        printf("The order has been placed successfully!\n");
        gotoxy(40, 15);
        textcolor(15);
        system("pause");
        menuBasket();
    } else {
        displayErrorMessage("No items were added to your cart.");
        menuBasket();
    }
}

// Fonction pour traiter une commande en fonction du critère (nom ou ID)
void commande(const char *filename, const char *critere) {
    FILE *file = fopen(filename, "r+");
    if (file == NULL) {
        displayErrorMessage("Error: Unable to open the medication file.");
        menu_client();
        return;
    }

    medical med;
    int found = 0;
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%s %s %d %d %d %f %f %f %s %s",
               med.id, med.medi_name, &med.quantity, &med.id_prescription,
               &med.quantity_sold, &med.cost, &med.profit,
               &med.purchase_price, med.exp_date, med.supplier_name);

        if (strcmp(med.id, critere) == 0 || strcmp(med.medi_name, critere) == 0) {
            found = 1;

            // Vérification du stock
            if (med.quantity <= 0) {
                displayErrorMessage("Sorry, this medication is out of stock.");
                menu_client();
                return;
            }

            // Vérification si une ordonnance est requise
            if (med.id_prescription == 1) {
                if (!verifyOrdonnance()) {
                    // Si l'ordonnance est invalide ou expirée, afficher un message et revenir à la recherche
                    displayErrorMessage("Prescription is invalid or expired. Please check your prescription.");
                    menu_client();
                    return;  // Retourner à la recherche, aucune entrée d'informations personnelles
                } else {
                    system("cls");
                    textcolor(2);
                    box();
                    gotoxy(40, 8);
                    printf("The prescription has been successfully verified.\n");
                    Sleep(3);
                    textcolor(15);
                    clientiinfo();  // Demander les informations personnelles après validation
                }
            }

            // Mise à jour des données
            med.quantity--;
            med.quantity_sold++;
            med.profit += med.cost - med.purchase_price;

            // Réécriture dans le fichier
            fseek(file, -strlen(line), SEEK_CUR);
            fprintf(file, "%s %s %d %d %d %.2f %.2f %.2f %s %s\n",
                    med.id, med.medi_name, med.quantity, med.id_prescription,
                    med.quantity_sold, med.cost, med.profit,
                    med.purchase_price, med.exp_date, med.supplier_name);

            // Sauvegarder la commande dans "ventes.txt"
            char client_id[20];
            char current_date[11];
            getCurrentDate(current_date);

            system("cls");
            textcolor(15);
            box();
            gotoxy(30, 8);
            printf("Enter your client ID: ");
            scanf("%s", client_id);

            FILE *commande_file = fopen("ventes.txt", "a");
            if (commande_file == NULL) {
                displayErrorMessage("Error opening ventes.txt file.");
                fclose(file);
                menu_client();
                return;
            }
            fprintf(commande_file, "%s %s %s %s\n", client_id, med.id, med.medi_name, current_date);
            fclose(commande_file);

            system("cls");
            textcolor(2);
            box();
            gotoxy(40, 8);
            printf("The order has been successfully placed!\n");
            textcolor(15);
            gotoxy(40, 12);
            system("pause");
            menu_client();
            break;
        }
    }

    if (!found) {
        displayErrorMessage("No matching medication found.");
        menu_client();
    }

    fclose(file);
}

#endif

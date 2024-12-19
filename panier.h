
#ifndef PANIER_H_INCLUDED
#define PANIER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include"interface.h"
#include"medical.h"
#include"commande.h"
#include"menu_client.h"
#include"menu login.h"
//-------------------------------------
int verifyOrdonnance();
void menuBasket();
void add_to_cart(medical *mede);
void add_to_cart(medical *mede);
void commande2(const char *filename, const char *recherche);

void add_to_cart(medical *mede) {
    FILE *carte = fopen("cart5.txt", "a+");
    if (carte == NULL) {
        system("cls");
        textcolor(15);
        box();
        gotoxy(20, 8);
        textcolor(2);
        printf("Error: Unable to open the cart file.\n");
        sleep(3);
        menu_client();
        return;
    }

    fprintf(carte, "%s %s %.2f\n", mede->id, mede->medi_name, mede->cost);
    fclose(carte);
    system("cls");
    textcolor(15);
    box();
    gotoxy(20, 8);
    textcolor(2);
    printf("Medicine successfully added to the cart.\n");
    sleep(3);
    menu_client();
}
void displayCart() { // aficher panier
    FILE *carte = fopen("cart5.txt", "r");
    if (carte == NULL) {
        system("cls");
        textcolor(15);
        box();
        gotoxy(40, 8);
        textcolor(2);
        printf("Error: Unable to open the cart file.\n");
        Sleep(8);
        menuBasket();
        return;
    }
    system("cls");
    textcolor(15);
    box();
    gotoxy(30, 5);
    textcolor(6);
    printf("Items in your cart:\n\n");

    char line[256];
    int line_count = 0;
    // Read and display each item in the cart
    while (fgets(line, sizeof(line), carte) != NULL) {
        char id[50], name[50];
        float cost;

        // Parse each line
        if (sscanf(line, "%s %s %f", id, name, &cost) == 3) {
            line_count++;
            gotoxy(30, 8 + line_count);
            textcolor(15);
            printf("ID: %s, Name: %s, Cost: %.2f\n", id, name, cost);
        }

    }
    if (line_count == 0) {
        gotoxy(30, 8);
        textcolor(15);
        printf("Your cart is empty.\n");
        Sleep(5);
        menuBasket();
    }

    fclose(carte);
}
void commande2(const char *filename, const char *critere) {
    FILE *file = fopen(filename, "r+");
    if (file == NULL) {
        system("cls");
        textcolor(15);
        box();
        gotoxy(20, 8);
        textcolor(8);
        printf("Error: Unable to open the medication file.\n");
        Sleep(6);
        menuBasket();
       
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
                system("cls");
                textcolor(15);
                box();
                gotoxy(20, 8);
                printf("Sorry, this medication is out of stock.\n");
                Sleep(5);
                menuBasket();
             
            }

            // Vérification si une ordonnance est requise
            if (med.id_prescription == 1) {
                if (!verifyOrdonnance()) {
                    system("cls");
                    textcolor(15);
                    box();
                    gotoxy(40, 8);
                    printf("Prescription is invalid.\n");
                   textcolor(15);

                   gotoxy(40, 12);
                   system("pause");
                    menuBasket();
                   
                } else {
                    system("cls");
                    textcolor(2);
                    box();
                    gotoxy(40, 8);
                    printf("The prescription has been successfully verified.\n");
                   // Sleep(3);
                    textcolor(15);

                   gotoxy(40, 12);
                   system("pause");
                }

            }

            // Saisie des informations du client
           // clientiinfo();

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

            // Générer automatiquement la date de commande
            char client_id[20];
            char current_date[11];
            getCurrentDate(current_date);

            system("cls");
            textcolor(15);
            box();
            gotoxy(40, 8);
            printf("Enter your client ID: ");
            scanf("%s", client_id);

            // Sauvegarde dans ventes.txt
            FILE *commande_file = fopen("ventes.txt", "a");
            if (commande_file == NULL) {
                system("cls");
                textcolor(15);
                box();
                gotoxy(40, 8);
                printf("Error opening ventes.txt file.\n");
                fclose(file);
                menuBasket();
              
                return;
            }
            fprintf(commande_file, "%s %s %s %s\n", client_id, med.id, med.medi_name, current_date);
            fclose(commande_file);

            // Affichage final
            system("cls");
            textcolor(2);
            box();
            gotoxy(40, 8);
            printf("The order has been successfully placed!\n");
           // Sleep(5);
            textcolor(15);
            gotoxy(40, 12);
             system("pause");
                 //  menu();
           
        }
    }

    if (!found) {
        system("cls");
        textcolor(15);
        box();
        gotoxy(40, 8);
        printf("No matching medication found.\n");
                textcolor(15);
                gotoxy(40, 12);
                   system("pause");
                menuBasket();
    }

    fclose(file);
}
void removeFromCart() {
    char search_value[50];
    int choice;

    // Demande du critère de recherche
    system("cls");
    textcolor(15);
    box();
    gotoxy(40, 8);
    textcolor(6);

    printf("Choose the type of search to remove from cart:\n\n");
    gotoxy(40, 10);
    textcolor(15);
    printf("1. By Name\n");
    gotoxy(40, 11);
    printf("2. By ID\n");
    gotoxy(30, 18);
    textcolor(2);
    printf("Your choice: ");
    scanf("%d", &choice);

    // Demande de l'ID ou du nom du médicament
    if (choice == 1) {
        system("cls");
        textcolor(15);
        box();
        gotoxy(30, 8);
        textcolor(6);
        printf("Enter the name of the medicine to remove: ");
        scanf("%s", search_value);
    } else if (choice == 2) {
        system("cls");
        textcolor(15);
        box();
        gotoxy(30, 8);   
        textcolor(6);
        printf("Enter the ID of the medicine to remove: ");
        scanf("%s", search_value);
    } else {
        system("cls");
        textcolor(15);
        box();
        gotoxy(30, 8);
        textcolor(8);
        printf("Invalid choice. Please try again.\n");
        sleep(4);
        menuBasket();
        return;
    }

    // Ouvrir le fichier du panier pour la suppression
    FILE *cart = fopen("cart.txt", "r");
    if (cart == NULL) {
        system("cls");
        textcolor(15);
        box();
        gotoxy(30, 8);
        textcolor(2);
        printf("Error: Unable to open the cart file.\n");
        sleep(3);
        return;
    }

    FILE *temp = fopen("temp_cart.txt", "w");
    if (temp == NULL) {
        fclose(cart);
        system("cls");
        textcolor(15);
        box();
        gotoxy(30, 8);
        textcolor(2);
        printf("Error: Unable to create a temporary file.\n");
        sleep(4);
        menuBasket();
        return;
    }

    char line[256];
    int found = 0;

    // Lire chaque ligne du fichier panier et copier dans le fichier temporaire, sauf si c'est l'élément à supprimer
    while (fgets(line, sizeof(line), cart) != NULL) {
        char id[50], name[50];
        float cost;

        // Analyser la ligne pour extraire les détails du médicament
        if (sscanf(line, "%s %s %f", id, name, &cost) == 3) {
            if ((choice == 1 && strcmp(name, search_value) != 0) ||
                (choice == 2 && strcmp(id, search_value) != 0)) {
                // Si l'ID ou le nom ne correspond pas, copier dans le fichier temporaire
                fputs(line, temp);
            } else {
                found = 1; // Marquer que l'élément a été trouvé et supprimé
            }
        }
    }

    fclose(cart);
    fclose(temp);

    if (found) {
        // Remplacer l'ancien fichier panier par le nouveau fichier
        remove("cart.txt");
        rename("temp_cart.txt", "cart.txt");

        system("cls");
        textcolor(15);
        box();
        gotoxy(20, 8);
        textcolor(2);
        printf("Medicine successfully removed from the cart.\n");
        sleep(4);
        menuBasket();
    } else {
        // Si aucun élément n'a été trouvé avec l'ID ou le nom donné
        remove("temp_cart.txt");
        system("cls");
        textcolor(15);
        box();
        gotoxy(20, 8);
        textcolor(2);
        printf("Medicine not found in the cart.\n");
        sleep(4);
        menuBasket();
    }
}
 void menuBasket() {
    int choice;

    do {
        system("cls");
        textcolor(15);
        box();
        gotoxy(40, 7);
        textcolor(2);
        printf("   --- Basket Menu ---");
        gotoxy(40, 11);
        textcolor(15);
        printf("1. View basket contents\n");
        gotoxy(40, 12);
        textcolor(15);
        printf("2. Remove a medication from the basket\n");
        gotoxy(40, 13);
        textcolor(15);
        printf("3. Confirm the order\n");
        gotoxy(40, 14);
        textcolor(15);
        printf("4. Return to the main menu\n");
        gotoxy(20, 16);
        textcolor(1);
        printf("\tEnter your choice: ");
         choice=toupper(getche());

        switch (choice) {
            case 1:
                displayCart();
                gotoxy(40,18);
                textcolor(15);
                system("pause");
                break;
            case 2:
                removeFromCart();
                break;
            case 3:
                makeOrder();
                break;
            case 4:
               menu_client();
                break;
            default:
                system("cls");
                textcolor(15);
                box();
                gotoxy(40, 8);
                textcolor(2);
                printf("Invalid choice. Please try again.\n");
                sleep(4);
                menuBasket();
                break;
        }
    } while (choice != 4);
}
#endif

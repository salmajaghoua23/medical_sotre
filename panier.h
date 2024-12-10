
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
//-------------------------------------
void menuBasket();
void add_to_cart(medical *mede);
void add_to_cart(medical *mede);

void add_to_cart(medical *mede) {
    FILE *carte = fopen("cart5.txt", "a+");
    if (carte == NULL) {
        system("cls");
        textcolor(15);
        box();
        gotoxy(20, 8);
        textcolor(2);
        printf("Error: Unable to open the cart file.\n");
        sleep(10);
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
    sleep(10);
}

void displayCart() { // aficher panier
    FILE *carte = fopen("cart5.txt", "r");
    if (carte == NULL) {
        system("cls");
        textcolor(15);
        box();
        gotoxy(20, 8);
        textcolor(2);
        printf("Error: Unable to open the cart file.\n");
        Sleep(2222);
        return;
    }

    system("cls");
    textcolor(15);
    box();
    gotoxy(20, 5);
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
            gotoxy(20, 8 + line_count);
            textcolor(15);
            printf("ID: %s, Name: %s, Cost: %.2f\n", id, name, cost);
        }

    }
Sleep(2222);
    if (line_count == 0) {
        gotoxy(20, 8);
        textcolor(15);
        printf("Your cart is empty.\n");
             Sleep(2222);
    }

    fclose(carte);
}

void removeFromCart() {
    char search_value[50];
    int choice;

    // Demande du critère de recherche
    system("cls");
    textcolor(15);
    box();
    gotoxy(20, 8);
    textcolor(6);

    printf("Choose the type of search to remove from cart:\n\n");
    gotoxy(20, 10);
    textcolor(15);
    printf("1. By Name\n");
    gotoxy(20, 11);
    printf("2. By ID\n");
    gotoxy(10, 25);
    textcolor(2);
    printf("Your choice: ");
    scanf("%d", &choice);

    // Demande de l'ID ou du nom du médicament
    if (choice == 1) {
        system("cls");
        textcolor(15);
        box();
        gotoxy(20, 8);
        textcolor(6);
        printf("Enter the name of the medicine to remove: ");
        scanf("%s", search_value);
    } else if (choice == 2) {
        system("cls");
        textcolor(15);
        box();
        gotoxy(20, 8);   
        textcolor(6);
        printf("Enter the ID of the medicine to remove: ");
        scanf("%s", search_value);
    } else {
        system("cls");
        textcolor(15);
        box();
        gotoxy(20, 8);
        textcolor(8);
        printf("Invalid choice. Please try again.\n");
        return;
    }

    // Ouvrir le fichier du panier pour la suppression
    FILE *cart = fopen("cart.txt", "r");
    if (cart == NULL) {
        system("cls");
        textcolor(15);
        box();
        gotoxy(20, 8);
        textcolor(2);
        printf("Error: Unable to open the cart file.\n");
        return;
    }

    FILE *temp = fopen("temp_cart.txt", "w");
    if (temp == NULL) {
        fclose(cart);
        system("cls");
        textcolor(15);
        box();
        gotoxy(20, 8);
        textcolor(2);
        printf("Error: Unable to create a temporary file.\n");
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
    } else {
        // Si aucun élément n'a été trouvé avec l'ID ou le nom donné
        remove("temp_cart.txt");

        system("cls");
        textcolor(15);
        box();
        gotoxy(20, 8);
        textcolor(2);
        printf("Medicine not found in the cart.\n");
    }
}
 void menuBasket() {
    int choice;

    do {
        system("cls");
        textcolor(15);
        box();
        gotoxy(20, 7);
        textcolor(2);
        printf("   --- Basket Menu ---");
        gotoxy(20, 11);
        textcolor(15);
        printf("1. View basket contents\n");
        gotoxy(20, 12);
        textcolor(15);
        printf("2. Remove a medication from the basket\n");
        gotoxy(20, 13);
        textcolor(15);
        printf("3. Confirm the order\n");
        gotoxy(20, 14);
        textcolor(15);
        printf("4. Return to the main menu\n");
        gotoxy(10, 25);
        textcolor(15);
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayCart();
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
                gotoxy(20, 8);
                textcolor(2);
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
}
#endif
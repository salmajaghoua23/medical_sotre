#ifndef HISTORIQUE_H_INCLUDED
#define HISTORIQUE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// Ensure these functions are properly defined somewhere
void gotoxy(int x, int y); // Positioning the cursor
void box(); // Displaying a box for the user interface
void main_historique();
void enregistrerCommande(char clientID[]) {
    char customerFileName[20];
    sprintf(customerFileName, "%s_commandes.txt", clientID);
    FILE *customerFile = fopen(customerFileName, "a");
    if (customerFile != NULL) {
        fprintf(customerFile, "History for Customer ID: %s\n", clientID);
        fclose(customerFile);
    }

    char date[20], medicaments[100];
    double total;

    gotoxy(40, 5);
    printf("----------- RECORD A NEW ORDER -----------");
    gotoxy(20, 8);
    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", date);
    getchar(); // Consume the remaining '\n' character

    gotoxy(20, 10);
    printf("Enter medications (e.g., Paracetamol x2, Ibuprofen x1): ");
    fgets(medicaments, sizeof(medicaments), stdin);
    medicaments[strcspn(medicaments, "\n")] = '\0'; // Remove the '\n'

    gotoxy(20, 12);
    printf("Enter the total amount: ");
    scanf("%lf", &total);

    FILE *file = fopen(customerFileName, "a");
    if (file != NULL) {
        fprintf(file, "Date: %s\n", date);
        fprintf(file, "Medications: %s\n", medicaments);
        fprintf(file, "Total: %.2f\n", total);
        fprintf(file, "-----------------------------\n");
        fclose(file);
        gotoxy(20, 15);
        printf("Order successfully recorded in %s.\n", customerFileName);
    } else {
        gotoxy(20, 15);
        printf("Error: Unable to open the file for recording.\n");
    }
}

void affichage_historique(char clientID[]) {
    char filename[30];
    sprintf(filename, "%s_commandes.txt", clientID); // Constructing the filename

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: No history found for client %s.\n", clientID);
        return;
    }
    gotoxy(30, 5);
    textcolor(2);
    printf("----------- ORDER HISTORY -----------\n");
    textcolor(15);
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("\t\t\t\t%s", line);
    }
    fclose(file);
    gotoxy(30, 23);
    textcolor(2);
    printf("----------- END OF HISTORY -----------\n");
    printf("\n\n\n\n");
}

void main_historique() {
    char clientID[20];
    int choix;

    while (1) {
        system("cls");
        box();
        gotoxy(40, 6);
        textcolor(2);
        printf("---- Client Connection ----");
        gotoxy(30, 10);
        textcolor(15);
        printf("Enter your client ID: ");
        scanf("%s", clientID);

        textcolor(2);
        gotoxy(30, 14);
        printf("\t\t\t------ Menu ------");
        textcolor(15);
        gotoxy(30, 16);
        printf("1. Add an order");
        gotoxy(30, 18);
        printf("2. Display order history");
        gotoxy(30, 20);
        printf("3. Exit");
        gotoxy(30, 22);
        textcolor(1);
        printf("Your choice: ");
        choix=toupper(getche());

        switch (choix) {
            case '1':
                system("cls");
                box();
                enregistrerCommande(clientID);
                break;
            case '2':
                system("cls");
                box();
                affichage_historique(clientID);
                system("pause");
                break;
            case '3':
                printf("Thank you for your visit. Goodbye!\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
                system("pause");
        }
    }
}

#endif

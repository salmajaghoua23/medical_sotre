
#ifndef CLIENT_INFO_H_INCLUDED
#define CLIENT_INFO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include"interface.h"
#include"menu_adm.h"
#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>
#include <unistd.h>
// client_info.h
void afficherTousLesAbonnes();
void clientiinfo();
void menuprincipale();

#define MAX_NAME_LENGTH 20
#define MAX_PHONE_LENGTH 11
#define MAX_CARD_LENGTH 17
#define MAX_EMAIL_LENGTH 50
#define MAX_ADDRESS_LENGTH 100

typedef struct {
        int cust_age;
        int id;
        char firstName[20];
        char lastName[20];
        char telephone[10];
        char cardNumber[17];
        char expirationDate[6];
        char cvv[4];
        char address[100];
        char city[20];
        char recovery_code[15];
        char email[50];
        char password[30];
    } clientinfo;

// Fonction pour valider un numéro de téléphone (10 chiffres)
bool validatePhoneNumber(const char *phone) {
    if (strlen(phone) != 10) return false;
    for (int i = 0; i < 10; i++) {
        if (!isdigit(phone[i])) return false;
    }
    return true;
}

// Fonction pour valider un numéro de carte bancaire (16 chiffres)
bool validateCardNumber(const char *cardNumber) {
    if (strlen(cardNumber) != 16) return false;
    for (int i = 0; i < 16; i++) {
        if (!isdigit(cardNumber[i])) return false;
    }
    return true;
}

// Fonction pour valider un email
bool validateEmail(const char *email) {
    const char *at = strchr(email, '@'); // Vérifier la présence de '@'
    const char *dot = strrchr(email, '.'); // Vérifier la présence d'un '.' après '@'
    if (!at || !dot || at > dot) return false; // '@' doit précéder '.'
    if (at == email || *(dot + 1) == '\0') return false; // Pas de caractères avant '@' ou après '.'
    return true;
}

// Fonction pour effacer la ligne
void clearLine(int x, int y) {
    gotoxy(x, y);
    printf("                                                  ");
    gotoxy(x, y);
}

// Fonction pour saisir et valider les informations du client
void clientiinfo() {
    clientinfo client;

    system("cls");
    textcolor(15);
    box();
    gotoxy(40, 3);
    printf("===============================================");
    gotoxy(40, 4);
    printf("        Please Enter Your Personal Details     ");
    gotoxy(40, 5);
    printf("===============================================\n");

    // First Name
    gotoxy(40, 7);
    printf("First Name: ");
    scanf(" %19s", client.firstName);

    // Last Name
    gotoxy(40, 8);
    printf("Last Name: ");
    scanf(" %19s", client.lastName);

    // Phone Number
    do {
        clearLine(40, 9);
        printf("Phone Number (10 digits): ");
        scanf(" %10s", client.telephone);
        if (!validatePhoneNumber(client.telephone)) {
            gotoxy(40, 10);
            textcolor(12);
            printf("Error: Phone number must contain exactly 10 digits.\n");
            textcolor(15);
        } else {
            clearLine(40, 10);
        }
    } while (!validatePhoneNumber(client.telephone));

    // Card Number
    do {
        clearLine(40, 11);
        printf("Credit Card Number (16 digits): ");
        scanf(" %16s", client.cardNumber);
        if (!validateCardNumber(client.cardNumber)) {
            gotoxy(40, 12);
            textcolor(12);
            printf("Error: Card number must contain exactly 16 digits.\n");
            textcolor(15);
        } else {
            clearLine(40, 12);
        }
    } while (!validateCardNumber(client.cardNumber));

    // Expiration Date
    gotoxy(40, 13);
    printf("Expiration Date (MM/YY): ");
    scanf(" %5s", client.expirationDate);

    // CVV
    gotoxy(40, 14);
    printf("CVV (3 digits): ");
    scanf(" %3s", client.cvv);

    // Address
    gotoxy(40, 15);
    printf("Address: ");
    scanf(" %[^\n]", client.address);

    // Email
    do {
        clearLine(40, 16);
        printf("Email Address: ");
        scanf(" %49s", client.email);
        if (!validateEmail(client.email)) {
            gotoxy(40, 17);
            textcolor(12);
            printf("Error: Invalid email format. Expected: name@domain.com\n");
            textcolor(15);
        } else {
            clearLine(40, 17);
        }
    } while (!validateEmail(client.email));

    // Confirmation
    gotoxy(40, 19);
    textcolor(10);
    printf("Thank you, %s %s! Your information has been successfully saved.", client.firstName, client.lastName);
    gotoxy(40, 21);
    textcolor(15);
    printf("Press any key to continue...");
    getch();
}

// Fonction pour afficher tous les abonnés
void afficherTousLesAbonnes() {
    FILE *file = fopen("customers.txt", "r");
    char ch;
    if (file == NULL) {
        printf("Error: Unable to open the subscribers file.\n");
        return;
    }

    system("cls");
    gotoxy(30, 5);
    textcolor(5);
    printf("----------- LIST OF SUBSCRIBERS -----------\n");
    textcolor(7);

    clientinfo newCustomer;
    while (fscanf(file, "%d %s %s %s %s %s %s\n", &newCustomer.id, newCustomer.firstName, newCustomer.lastName,
                   newCustomer.telephone, newCustomer.email, newCustomer.password, newCustomer.recovery_code) == 7) {
        printf("\t\t\tID: %d\n", newCustomer.id);
        printf("\t\t\tName: %s %s\n", newCustomer.firstName, newCustomer.lastName);
        printf("\t\t\tTelephone: %s\n", newCustomer.telephone);
        printf("\t\t\tEmail: %s\n", newCustomer.email);
        printf("\t\t\t---------------------------------------\n");
    }

    fclose(file);
    textcolor(5);
    gotoxy(40, 23);
    printf("----------- END OF LIST -----------\n");
    gotoxy(30, 24);
    textcolor(9);
    printf("Do you want to return to the menu ??\t");
    ch = getch();
    if (ch == 'y') {
        // Appel de la fonction pour revenir au menu principal (à définir ailleurs dans le code)
        main_menu();
    }
    system("pause");
}


#endif
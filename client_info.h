
#ifndef CLIENT_INFO_H_INCLUDED
#define CLIENT_INFO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include"interface.h"

typedef struct {
    char firstName[20];
    char lastName[20];
    char telephone[10];
    char cardNumber[17];  // 16 digits + 1 for null-terminator
    char expirationDate[6]; // MM/YY format
    char cvv[4];
    char address[100];  // Assuming address is longer
} clientinfo;

void clientiinfo() {
    textcolor(14); // Highlighted text color
    clientinfo client;
     system("cls");
            textcolor(15);
            box();
textcolor(2);
    gotoxy(20, 7);
    printf("Please enter your personal information.\n");

    textcolor(15); // Regular text color
    gotoxy(20, 8);
    printf("First Name: ");
    scanf(" %s", client.firstName);

    gotoxy(20, 9);
    printf("Last Name: ");
    scanf(" %s", client.lastName);

    gotoxy(20, 10);
    printf("Phone Number: ");
    scanf(" %s", client.telephone);

    gotoxy(20, 11);
    printf("Credit Card Number: ");
    scanf(" %s", client.cardNumber);

    gotoxy(20, 12);
    printf("Card Expiry Date (MM/YY): ");
    scanf(" %s", client.expirationDate);

    gotoxy(20, 13);
    printf("CVV: ");
    scanf(" %s", client.cvv);

    gotoxy(20, 14);
    printf("Address: ");
    scanf(" %s", client.address);
}



#endif
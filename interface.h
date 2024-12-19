#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
#include <unistd.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<direct.h>
#include<time.h>
#include<ctype.h>
#include <unistd.h> // Pour sleep() et usleep()

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m" // Réinitialisation des couleurs
#include"menu login.h"
void menuprincipale();  
void drawPharmacyLogo3();
void gotoxy(int x, int y);
void setTextColor(int color);
void gotoxy1(int x, int y);
void textcolor(int color);
void box();
// Function to set cursor position
void gotoxy1(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void textcolor(int color) ;
void textcolor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Function to set text color
void setTextColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void box2() {
    gotoxy1(2, 2);
    printf("%c", 201);
    gotoxy1(78, 2);
    printf("%c", 187);
    gotoxy1(2, 24);
    printf("%c", 200);
    gotoxy1(78, 24);
    printf("%c", 188);
    for (int i = 3; i < 78; i++) {
        gotoxy1(i, 2);
        printf("%c", 205);
        gotoxy1(i, 24);
        printf("%c", 205);
    }
    for (int i = 3; i < 24; i++) {
        gotoxy1(2, i);
        printf("%c", 186);
        gotoxy1(78, i);
        printf("%c", 186);
    }
}
void box(){
system("cls");

    textcolor(14);
    for (int i = 3; i <= 25; i++) {
        gotoxy(20, i); printf("║");
        gotoxy(90, i); printf("║");
    }
    for (int i = 20; i <= 90; i++) {
        gotoxy(i, 3); printf("═");
        gotoxy(i, 25); printf("═");
    }
    gotoxy(20, 3); printf("╔");
    gotoxy(90, 3); printf("╗");
    gotoxy(20, 25); printf("╚");
    gotoxy(90, 25); printf("╝");
}


void displayAnimation() {
     drawPharmacyLogo3();
    char *colors[] = {GREEN, YELLOW, BLUE}; // 4 couleurs
    int colorCount = sizeof(colors) / sizeof(colors[0]); // Nombre de couleurs
    int i, j;
     box();
     gotoxy(30,6);
    for (j = 0; j < colorCount; j++) { // Boucle pour les 4 couleurs
        printf("\n\n");
        gotoxy(30,12);
        printf("%s", colors[j]); // Applique la couleur actuelle
        gotoxy(30,8);
        printf("	   Loading the Pharmacy Management Application...\n");
        gotoxy(30,12);
        printf("	   --------------------------------------------\n");
        gotoxy(30,14);
        printf("       ["); // Début de la barre animée

        // Animation de la barre de progression
        for (i = 0; i <= 30; i++) {
            printf("=");        // Affiche la barre qui avance
            fflush(stdout);     // Affiche immédiatement
            sleep(0);      // Pause rapide (0.05 seconde)
        }
        printf("] 100%%\n");    // Fin de la barre
        gotoxy(30,16);
        printf("	   --------------------------------------------\n");

        sleep(1); // Pause de 0.5 seconde pour voir la couleur
    }
    
    system("clear"); // Efface l'écran final avant d'afficher le menu
    printf(RESET);  
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");  // Réinitialise la couleur du texte
    menuprincipale(); // Appelle la page menu principale
}

// Définir les couleurs pour le terminal
#define GREEN "\033[1;32m"  // Code pour la couleur verte
#define WHITE "\033[1;37m"  // Code pour la couleur blanche
#define RESET "\033[0m"     // Code pour réinitialiser les couleurs


// Fonction pour définir la couleur du texte
void setColor(const char* color) {
    printf("%s", color);
}


// Fonction pour dessiner le texte "WELCOME" dans un style
void drawWelcome() {
    system("cls");
    box();
    // Définir la couleur verte
    setColor(GREEN);  
    gotoxy(35, 6);    
    printf("██    ██ ███████╗██╗     ███████╗███████╗███████╗\n");
    gotoxy(35, 7);
    printf("██    ██ ██╔════╝██║     ██╔════╝██╔════╝██╔════╝\n");
    gotoxy(35, 8);
    printf("██    ██ █████╗  ██║     █████╗  ███████╗███████╗\n");
    gotoxy(35, 9);
    printf("██    ██ ██╔══╝  ██║     ██╔══╝  ╚════██║╚════██║\n");
    gotoxy(35, 10);
    printf("███████╗███████╗███████╗███████╗███████║███████║\n");
    gotoxy(35, 11);
    printf("╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝╚══════╝\n");

    // Passer à la ligne suivante et changer la couleur pour "WELCOME"
    setColor(WHITE); // Appliquer la couleur blanche
    gotoxy(35, 12);
    printf("                WELCOME\n");
    sleep(3);
    // Réinitialiser la couleur après l'affichage
    setColor(RESET);
}


// Fonction pour dessiner un logo stylisé avec "WELCOME"
void drawPharmacyLogo3() {
    system("cls"); // Effacer l'écran
    box(); // Si une bordure est nécessaire, elle sera appelée ici

    // Couleur verte pour tout le logo
    setColor(GREEN);

    // Afficher "WELCOME" avec un style ASCII
    gotoxy(25, 11);
    printf("██     ██ ███████ ██       ██████   ██████  ███    ███ ███████");
    gotoxy(25, 12);
    printf("██     ██ ██      ██      ██    ██ ██    ██ ████  ████ ██     ");
    gotoxy(25, 13);
    printf("██  █  ██ █████   ██      ██    ██ ██    ██ ██ ████ ██ █████  ");
    gotoxy(25, 14);
    printf("██ ███ ██ ██      ██      ██    ██ ██    ██ ██  ██  ██ ██     ");
    gotoxy(25, 15);
    printf(" ███ ███  ███████ ███████  ██████   ██████  ██      ██ ███████");

    // Ajouter un message sous "WELCOME"
    setColor(WHITE);
    gotoxy(40, 16);
    printf("TO PHARMACY MANAGEMENT SYSTEM");

    // Réinitialiser les couleurs
    setColor(RESET);
    sleep(3); // Pause pour l'effet visuel
}

#endif
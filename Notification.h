#ifndef NOTIFICATION_H_INCLUDED
#define NOTIFICATION_H_INCLUDED

#include "medical.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> // Pour gotoxy et Sleep
#include "interface.h"
#include "menu_adm.h"
#include "menu login.h"

#define NOM_FICHIER "medicines.txt"
#define SEUIL_MAX 50
#define FICHIER_DAT "stocks.dat"
#define SCRIPT_GNUPLOT "plot_stock.gp"
typedef struct medical1 {
    char id[6];
    char medi_name[20];
    int quantity;
    int id_prescription;
    int quantity_sold;
    float cost;
    float profit;
    float purchase_price;
    char exp_date[15];
    char supplier_name[30];
} medical1;

// Prototypes de fonctions
void verifierStockMax();
void appelerGnuplot();
void afficherAlerte(const char* nom, int stock, int ligne);
void afficherMessageConforme(int ligne);

void verifierStockMax() {
    FILE *fichier = fopen(NOM_FICHIER, "r");
    if (fichier == NULL) {
        gotoxy(5, 10);
        textcolor(4);
        printf("[Erreur] Impossible d'ouvrir le fichier. Assurez-vous qu'il existe.\n");
        return;
    }

    int alerteDeclenchee = 0;
    int ligne = 5;
    medical1 med;

    system("cls");
    box();
    gotoxy(40, 5);
    textcolor(5);
    printf("======= Vérification des stocks =======");
    FILE *fichierDat = fopen(FICHIER_DAT, "w");
    if (fichierDat == NULL) {
        printf("[Erreur] Impossible de créer le fichier des données pour GNUPLOT.\n");
        fclose(fichier);
        return;
    }
    fprintf(fichierDat, "Médicament\tStock\n");
    gotoxy(30,12);
    while (fscanf(fichier, "%5s %19s %d %d %d %f %f %f %14s %29s",
                  med.id, med.medi_name, &med.quantity, &med.id_prescription,
                  &med.quantity_sold, &med.cost, &med.profit, &med.purchase_price,
                  med.exp_date, med.supplier_name) == 10) {

        fprintf(fichierDat,"le \t%s\t%d\n", med.medi_name, med.quantity);
        if (med.quantity < SEUIL_MAX) {
            afficherAlerte(med.medi_name, med.quantity, ligne);
            alerteDeclenchee = 1;
            ligne++;
        }
    }

    fclose(fichier);
    fclose(fichierDat);

    if (!alerteDeclenchee) {
        afficherMessageConforme(ligne);
    }

    appelerGnuplot(); // Appeler GNUPLOT pour afficher le graphique
    textcolor(15);
    printf("\n\n\n\n\n\n\n\n\n\n\n");
}

void afficherAlerte(const char* nom, int stock, int ligne) {
    gotoxy(20, ligne);
    textcolor(7);
    printf("  \"%s\" (%d unités) a dépassé le seuil maximum de %d unités.\n", nom, stock, SEUIL_MAX);
}

void afficherMessageConforme(int ligne) {
    gotoxy(30, ligne);
    textcolor(10);
    printf("Tous les stocks sont conformes. Aucun dépassement détecté.");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void appelerGnuplot() {
    FILE *script = fopen(SCRIPT_GNUPLOT, "w");
    if (script == NULL) {
        printf("[Erreur] Impossible de créer le script GNUPLOT.\n");
        return;
    }

    fprintf(script,
            "set title 'Stocks des médicaments'\n"
            "set xlabel 'Médicament'\n"
            "set ylabel 'Stock'\n"
            "set grid\n"
            "set style data histograms\n"
            "set style fill solid\n"
            "plot '%s' using 2:xtic(1) title 'Stock'\n", FICHIER_DAT);

    fclose(script);

    // Appeler GNUPLOT avec le script
    system("gnuplot -persist " SCRIPT_GNUPLOT);
}

void notification_menu() {
    char choix;

    do {
        system("cls");
        box();

        textcolor(14);
        gotoxy(40, 5);
        textcolor(2);
        printf("===== Contrôle des Notifications =====\n");
        gotoxy(30, 10);
        textcolor(7);
        printf("1. Vérification des stocks (notification)\n");
        gotoxy(30, 12);
        printf("2. Quitter\n");
        gotoxy(30, 14);
        printf("\tEntrez votre choix : ");
        choix = getch();

        switch (choix) {
            case '1':
                system("cls");
                box();
                verifierStockMax(); 
                system("pause"); // Pause après vérification
                break;
            case '2':
                textcolor(10);
                printf("Fin du programme. Merci !\n");
                break;
            default:
                textcolor(12);
                printf("Choix invalide ....\n");
                Sleep(1000); // Pause d'une seconde
                break;
        }
    } while (choix != '2');
}

#endif

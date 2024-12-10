#ifndef NOTIFICATION_H_INCLUDED
#define NOTIFICATION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> // Pour gotoxy et Sleep
#include"interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> // Pour gotoxy et Sleep
#include"medical.h"
#define NOM_FICHIER "medicines.txt"
#define SEUIL_MAX 50

// Prototypes de fonctions
void verifierStockMax();
void afficherAlerte(const char* nom, int stock, int ligne);
void afficherMessageConforme(int ligne);
void gotoxy(int x, int y);
void textcolor(int color);
void box();
void main_menu();


// Fonction pour vérifier les stocks
void verifierStockMax() {
    FILE *fichier = fopen(NOM_FICHIER, "r");
    if (fichier == NULL) {
        gotoxy(5, 10);
        textcolor(12);
        printf("[Erreur] Impossible d'ouvrir le fichier \"%s\". Assurez-vous qu'il existe.\n", NOM_FICHIER);
        return;
    }

    medical medicament;
    int alerteDeclenchee = 0;
    int ligne = 5;

    system("cls");
    box();
    gotoxy(10, 5);
    textcolor(14);
    printf("======= Vérification des stocks =======");
    // Lire le fichier ligne par ligne
    while (fscanf(fichier, "%5s %19s %d %d %d %f %f %f %f %14s %29s",
                  medicament.id,
                  medicament.medi_name,
                  &medicament.quantity,
                  &medicament.id_prescription,
                  &medicament.quantity_sold,
                  &medicament.cost,
                  &medicament.profit,
                  &medicament.purchase_price,
                  &medicament.sale_price,
                  medicament.exp_date,
                  medicament.supplier_name) == 11) {
        if (medicament.quantity > SEUIL_MAX) {
            afficherAlerte(medicament.medi_name, medicament.quantity, ligne);
            alerteDeclenchee = 1;
            ligne++;
        }
    }

    fclose(fichier);

    if (!alerteDeclenchee) {
        afficherMessageConforme(ligne);
    }

    gotoxy(5, ligne + 2);
    printf("==============================================================");
    textcolor(15);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

// Fonction pour afficher une alerte
void afficherAlerte(const char* nom, int stock, int ligne) {
    gotoxy(5, ligne);
    textcolor(12);
    printf("ALERTE : Le stock de \"%s\" (%d unités) a dépassé le seuil maximum de %d unités.\n",
           nom, stock, SEUIL_MAX);
}

// Fonction pour afficher un message si tout est conforme
void afficherMessageConforme(int ligne) {
    gotoxy(5, ligne);
    textcolor(10);
    printf("Tous les stocks sont conformes. Aucun dépassement détecté.");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
}


#endif

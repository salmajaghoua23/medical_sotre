
#ifndef AFFUCHE_MED_CLI_H_INCLUDED
#define AFFUCHE_MED_CLI_H_INCLUDED
#include"medical.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include"interface.h"
#include <unistd.h>



void afficherInfoMedicament(medical *med) {
    textcolor(14);
    gotoxy(20, 7);
    printf("   Information about the medicine:");
    textcolor(15);
    gotoxy(20, 10);
    // Displaying medication information
    printf("ID: %s", med->id);
    gotoxy(20, 11);
    printf("Name: %s\n", med->medi_name);
    gotoxy(20, 12);
    printf("Price: %.2f\n", med->cost);
    gotoxy(20, 13);
    printf("Expiration Date: %s\n", med->exp_date);
}




#endif
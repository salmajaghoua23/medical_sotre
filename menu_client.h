#ifndef MENU_CLIENT_H_INCLUDED
#define MENU_CLIENT_H_INCLUDED
#include"interface.h"
#include <unistd.h>
#include<ctype.h>
#include<stdlib.h>
#include <windows.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<direct.h>
#include<time.h>
#include<ctype.h>
#include"panier.h"
#include"menu login.h"
#include"searcheByClient.h"
#include"historique.h"
void menuBasket();
void menu_client();
void menuP1() {
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


    textcolor(2);
    gotoxy(30, 4);
    printf("=============================================");


    textcolor(10);
    gotoxy(30, 5);
    printf("      WELCOME TO OUR PHARMACY SYSTEM         ");
    gotoxy(30, 6);
    textcolor(2);
    printf("=============================================");

    textcolor(14);
    gotoxy(40, 10); printf("1.  Search for Medicine   ");
    gotoxy(40, 12); printf("2. menuBasket");
    gotoxy(40, 14); printf("3. Historique");
    gotoxy(40, 16); printf("4. Exit");
    
    textcolor(7);
    gotoxy(28, 18);
   

    textcolor(1);
}
void menu_client(){
    int  choice;
    do {
        system("cls");
        menuP1();
        printf("Your choice-: ");
        choice=toupper(getche());

        switch (choice) {
            case'1':
                search_medicine();
                break;
      case '2':
          menuBasket();
           break;
      case '3' :  
         box();
          main_historique();
          break ;
        case '4':
                system("cls");
                textcolor(15);
                box();
                gotoxy(40,13);
                textcolor(2);
                printf("Thank you for using the Pharmacy Management System.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                sleep(6);
                menuprincipale();
                break;
            default:
                system("cls");
                textcolor(15);
                box();
                gotoxy(40,13);
                textcolor(8);
                printf("Invalid choice.\n");
                sleep(3);
                menu_client();
                break;
        }
    } while (choice != 4);
}
#endif // MENU_CLIENT_H_INCLUDED

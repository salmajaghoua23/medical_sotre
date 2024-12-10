#ifndef MENU_CLIENT_H_INCLUDED
#define MENU_CLIENT_H_INCLUDED
#include"interface.h"
#include<stdlib.h>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<unistd.h>
#include<ctype.h>
#include"panier.h"
#include"searcheByClient.h"
void menuBasket();
void menu_client();
void menu_client(){
    int  choice;
    system("cls");
    box2();
    do {
            
            // box();
            textcolor(15);
            gotoxy(20,5);
            textcolor(2);
            printf("------------------------------------------ \n ");
            gotoxy(20,6);
            printf("   ---Welcome to the Pharmacy--- \n" );
            gotoxy(20,7);
            printf("------------------------------------------  \n\n\n\n\n ");
            textcolor(14);
            gotoxy(20,11);
        printf("1. Search for Medicine");
        gotoxy(20,12);
        printf("2. menuBasket");
        gotoxy(20,13);
        printf("3. Exit\n");
        textcolor(4);
        gotoxy(20,25);
        printf("\t\t Your choice-: ");
         scanf("%d", &choice);
        switch (choice) {
            case 1:
            search_medicine();
            break;
      case 2:
            menuBasket();
           break;
        case 3:
                system("cls");
                textcolor(15);
                box();
                gotoxy(16,13);
                textcolor(2);
                printf("----Thank you for using the Pharmacy Management System.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                sleep(199);
                break;
            default:
                system("cls");
                textcolor(15);
                box();
                gotoxy(20,13);
                textcolor(8);
                printf("Invalid choice.\n");
                sleep(3000);
                break;
        }
    } while (choice != 3);
}


#endif // MENU_CLIENT_H_INCLUDED

#ifndef MENU_CLIENT_H_INCLUDED
#define MENU_CLIENT_H_INCLUDED


#include "interface.h"
 //#include "menu_basket.h"
 //#include "search_medicine.h"
void menu()  {
    int  choice;
    do {
            system("cls");
                     textcolor(15);
                   box();
              gotoxy(20,5);
                 textcolor(2);
                   printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ \n ");
              gotoxy(20,6);
                    printf("   *****Welcome to the Pharmacy ***** \n" );
             gotoxy(20,7);
        printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  \n\n\n\n\n ");
             textcolor(15);
              gotoxy(20,11);

        printf("1. Search for Medicine");
              gotoxy(20,12);
        printf("2. menuBasket");
        gotoxy(20,13);
        printf("3. Exit\n");
         textcolor(2);
           gotoxy(10,25);
        printf("Your choice-: ");
         scanf("%d", &choice);

        switch (choice) {
            case 1:
                //search_medicine();
                break;
      case 2:
          //menubasket();
           break;
        case 3:
                system("cls");
                textcolor(15);
                box();
                gotoxy(16,13);
                textcolor(2);
                printf("Thank you for using the Pharmacy Management System.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                sleep(199);
                break;
            default:
                system("cls");
                         textcolor(15);

                         box();
                gotoxy(20,13);
                textcolor(8);
                printf("Invalid choice.\n");
                sleep(3);
                break;
        }
    } while (choice != 3);
}


#endif // MENU_CLIENT_H_INCLUDED

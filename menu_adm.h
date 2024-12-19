#ifndef MENU_ADM_H_INCLUDED
#define MENU_ADM_H_INCLUDED
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
#include"employer.h"
#include"medical.h"
#include"supplier.h"
#include"interface.h"
#include"Notification.h"
#include"repport.h"
#include"client_info.h"
#include"menu login.h"
#include <unistd.h>
void  main_menu();
 void notification_menu() ;
 void menu_employer();
 void afficherTousLesAbonnes();
 void box();
 void gotoxy(int x,int y);
 void textcolor(int color);
  void gotoxy1(int x,int y);
  void medication_menu();
 void report_menu();
typedef struct medical {
    char id[6];
    char medi_name[20];
    int quantity;
    int id_prescription;
    int quantity_sold;
    float cost;
    float profit;
    float purchase_price;
	 float sale_price; 
    char exp_date[15];
    char supplier_name[30];
} medical;


// Linked list structure
typedef struct node {
    medical data;
    struct node *next;
} med_list;
void menuP2() {
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
    gotoxy(33, 4);
    printf("------------------------------------------------------");
    textcolor(10);
    gotoxy(33, 5);
    printf("      THIS IS THE ADMINISTRATION OF MIDICAL STORE        ");
    gotoxy(33, 6);
    textcolor(2);
    printf("-------------------------------------------------------");

    textcolor(5);
    gotoxy(30, 10); printf("1. Supplier   ");
    gotoxy(55, 10); printf("2. Employer");
    gotoxy(30, 12); printf("3. Medical");
    gotoxy(55, 12); printf("4. Repport_menu ");
	gotoxy(30, 14); printf("5-Notifacation  ");
	gotoxy(55, 14); printf("6-About  ");
    gotoxy(30, 16); printf("7-Desplay_custumors  ");
    gotoxy(55, 16); printf("8-Exit  ");
    textcolor(7);
    gotoxy(30, 22);
    textcolor(7);
}
void  main_menu(){
char ch;
liste l;
liste employes = NULL;
	do{
	system("cls");
    menuP2();
    printf("\n\n\t\t\tPress the correct number  .........?\t");
    gotoxy(30, 40);
	ch=toupper(getche());
		switch(ch)
		{
			case '1':supplier_menu();
				 break;

			case '2':
              menu_employer();
				 break;
			case '3':medication_menu();
				 break;
			case '4':report_menu();
				 break;
		    case '5' : notification_menu();
			     break;
			case '6':
                box();
	            gotoxy(40,4);
	            textcolor(2);
	            printf("---- MEDICAL STORE ----");
	            gotoxy(25,8);
	            textcolor(7);
	            printf("=> This Project Is About Medical Store ...");
	            gotoxy(25,10);
	            printf("=> In This Project we Can Add Medicine ,Customer,Supplier Details");
	            gotoxy(25,12);
	            printf("=> We Can Modifed & Delete Existing Record");
	            gotoxy(25,14);
	            printf("=> We Can Also Search Medicine ,Customer,Supplier Details");
	            gotoxy(25,16);
	            printf("=> It's Helpfull For Display Stock Of Medicine \n\n");
                gotoxy(25,18);
	            printf("=> is located in HOCIEMA ");
				system("pause");
				break;
			case '7' : 
			afficherTousLesAbonnes();
			break;
			case '8' :
			printf("\n\n\n\n\t Do you want to exit now? Y/N :");
			Sleep(1000);
			ch=(getche());
			ch=toupper(ch);
    			if(ch=='Y')
			{
				system("cls");
				textcolor(2);
				gotoxy(35,20);
				printf(" Please wait.....");
				Sleep(2000);
				menuprincipale();
				//exit(0);
			}
			else
			{
				main_menu();
			}
             break;
			default:
			gotoxy(40,34);
			printf("Plaise Enter a number -----");
			getch();
		}
	}while(ch!='8');
}
#endif // MENU_ADM_H_INCLUDED

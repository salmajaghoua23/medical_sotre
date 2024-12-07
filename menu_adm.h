#ifndef MENU_ADM_H_INCLUDED
#define MENU_ADM_H_INCLUDED
#include <conio.h>
#include <string.h>
#include <math.h>
#include <direct.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "employer.h"
#include"medical.h"
#include"supplier.h"
#include"interface.h"
#include"repport.h"
void  main_menu(){
char ch;
liste l;

do{
    system("cls");
box2();
gotoxy(20, 5);
textcolor(2);
 printf("---------------------------------------------\t\t\t\t\n");
 textcolor(2);
 gotoxy(20, 6);
  textcolor(15);
 printf(" THIS IS THE ADMINISTRATION OF MIDICAL STORE \n");
 gotoxy(20, 7);
 textcolor(2);
 printf("---------------------------------------------\t\t\t\t\n");
 textcolor(15);
 gotoxy(12, 9);
 textcolor(14);
 printf("\n\n");
 textcolor(14);
 printf("\t\t 1-SUPPLIER\n\n\t\t 2-EMPLOYER\n\n\t\t 3-MEDICAL\n\n\t\t 4-REPPORT_MENU\n\n\t\t 5-ABOUT\n\n\t\n");
 textcolor(15); gotoxy(15, 12);
 printf("\n\n");
//remainder();
gotoxy(15,40);
printf("\n\n\n\n\n\n\n\n\n\n\n\nPRESS THE NUMBER OF THE OPTION THAT WHAT YOU WANT .........?\n\n");
gotoxy(15, 40);
		ch=toupper(getche());
		switch(ch)
		{
			case '1':supplier_menu();
				 break;
			case '2':menu_employer(l);
				 break;
			case '3':medication_menu();
				 break;
			case '4':report_menu();
				 break;
			case '5':
                box2();
	            gotoxy(28,4);
	            textcolor(2);
	            printf("---- MEDICAL STORE ----");
	            gotoxy(8,8);
	            textcolor(15);
	            printf("=> This Project Is About Medical Store ...");
	            gotoxy(8,10);
	            printf("=> In This Project we Can Add Medicine ,Customer,Supplier Details");
	            gotoxy(8,12);
	            printf("=> We Can Modifed & Delete Existing Record");
	            gotoxy(8,14);
	            printf("=> We Can Also Search Medicine ,Customer,Supplier Details");
	            gotoxy(8,16);
	            printf("=> It's Helpfull For Display Stock Of Medicine \n\n");
                gotoxy(8,18);
	            printf("=> is located in HOCIEMA ");
				break;
			printf("\n\n\n\n\t Do you want to exit now? Y/N :");
			Sleep(100);
			ch=(getche());
			ch=toupper(ch);
    			if(ch=='Y')
			{
				system("cls");
				textcolor(2);
				gotoxy(35,20);
				printf(" Please wait.....");
				Sleep(2000);
				exit(0);
			}
			else
			{
				main_menu();
			}

			default:
			gotoxy(11,34);
			printf("Plaise Enter a number -----^~^");
			getch();
		}
	}while(ch!='E');
}







#endif // MENU_ADM_H_INCLUDED

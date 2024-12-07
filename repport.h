#ifndef REPPORT_H_INCLUDED
#define REPPORT_H_INCLUDED
#include "employer.h"
#include"medical.h"
#include <conio.h>
#include <string.h>
#include <math.h>
#include <direct.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void sale_rpt_daily(med_list *head) {
    char date[15];
    system("cls"); // Clear the screen
    box();         // Draw the box

    gotoxy1(5, 3);
    printf("DAILY SALES REPORT");
    gotoxy1(5, 5);
    printf("Enter the date (YYYY-MM-DD): ");
    gotoxy1(30, 5);
    scanf("%s", date);

    gotoxy1(5, 7);
    printf("Medicine Name\tQuantity Sold\tTotal Revenue");
    gotoxy1(5, 8);
    printf("---------------------------------------------");

    med_list *current = head;
    int total_quantity = 0;
    float total_revenue = 0;
    int line = 9;

    while (current != NULL) {
        if (strcmp(current->data.exp_date, date) == 0) {
            float revenue = current->data.quantity_sold * current->data.sale_price;
            gotoxy1(5, line);
            printf("%s\t\t%d\t\t%.2f",
                   current->data.medi_name, current->data.quantity_sold, revenue);
            total_quantity += current->data.quantity_sold;
            total_revenue += revenue;
            line++;
        }
        current = current->next;
    }

    gotoxy1(5, line + 1);
    printf("---------------------------------------------");
    gotoxy1(5, line + 2);
    printf("Total Sold: %d units", total_quantity);
    gotoxy1(5, line + 3);
    printf("Total Revenue: %.2f", total_revenue);
    printf("\n\n\n\n\n\n\n\n\n");
}
void sale_rpt(med_list *head) {
    med_list *current = head;
    int total_quantity = 0;
    float total_revenue = 0;

    system("cls"); // Clear the screen
    box();         // Draw the box

    gotoxy1(5, 3);
    printf("SALES REPORT");
    gotoxy1(5, 5);
    printf("Medicine Name\tQuantity Sold\tTotal Revenue");
    gotoxy1(5, 6);
    printf("---------------------------------------------");

    int line = 7; // Position for the first row of data
    while (current != NULL) {
        float revenue = current->data.quantity_sold * current->data.sale_price;
        gotoxy1(5, line);
        printf("%s\t\t%d\t\t%.2f",
               current->data.medi_name, current->data.quantity_sold, revenue);
        total_quantity += current->data.quantity_sold;
        total_revenue += revenue;
        current = current->next;
        line++;
    }

    gotoxy1(5, line + 1);
    printf("---------------------------------------------");
    gotoxy1(5, line + 2);
    printf("Total Sales: %d units", total_quantity);
    gotoxy1(5, line + 3);
    printf("Total Revenue: %.2f", total_revenue);
    printf("\n\n\n\n\n\n\n\n\n");
}
void report_menu() {
    int choice;
    med_list * head;
    do {
        system("cls"); // Clear the screen
        box();         // Draw the box using your function
        textcolor(14);
        gotoxy1(20, 5);
        printf("------------------------");
        gotoxy1(20, 6);
        textcolor(2);
        printf("  ----REPORT MENU----");
        gotoxy1(20, 7);
        textcolor(14);
        printf("------------------------");
        gotoxy1(20, 9);
        textcolor(14);
        printf("1. General Sales Report");
        gotoxy1(20, 11);
        printf("2. Daily Sales Report");
        gotoxy1(20, 13);
        printf("3. Profit Report");
        gotoxy1(20, 15);
        printf("4. Purchase Report");
        gotoxy1(20, 17);
        printf("5. Daily Purchase Report");
        gotoxy1(20, 19);
        printf("0. Exit");
        gotoxy1(20, 21);
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                system("cls");
                box();
                sale_rpt(head);
                break;
            case 2:
                system("cls");
                box();
                sale_rpt_daily(head);
                break;
            case 3:
                system("cls");
                box();
                profit_rpt();
                break;
            case 4:
                system("cls");
                box();
                pur_rpt();
                break;
            case 5:
                system("cls");
                box();
                pur_rpt_daily();
                break;
            case 0:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);
}
void profit_rpt(med_list *head) {
    med_list *current = head;
    float total_profit = 0;

    printf("\n--- RAPPORT DES PROFITS ---\n");
    printf("Nom du médicament\tProfit\n");
    printf("----------------------------------\n");

    while (current != NULL) {
        float profit = (current->data.sale_price - current->data.purchase_price) * current->data.quantity_sold;
        printf("%s\t\t%.2f\n", current->data.medi_name, profit);
        total_profit += profit;
        current = current->next;
    }

    printf("----------------------------------\n");
    printf("Profit total : %.2f\n", total_profit);
}
void pur_rpt(med_list *head) {
    med_list *current = head;
    printf("\n--- RAPPORT DES ACHATS ---\n");
    printf("Nom du médicament\tFournisseur\tPrix d'achat\n");
    printf("-------------------------------------------------\n");

    while (current != NULL) {
        printf("%s\t\t%s\t\t%.2f\n",
               current->data.medi_name, current->data.supplier_name, current->data.purchase_price);
        current = current->next;
    }
}
void pur_rpt_daily(med_list *head) {
    char jour[15];
    printf("Entrez la date (YYYY-MM-DD) :\t ");
    scanf("%s", jour);

    med_list *current = head;
    printf("\n--- RAPPORT DES ACHATS POUR %s ---\n", jour);
    printf("Nom du médicament\tFournisseur\tPrix d'achat\n");
    printf("-------------------------------------------------\n");

    while (current != NULL) {
        if (strcmp(current->data.exp_date, jour) == 0) {
            printf("%s\t\t%s\t\t%.2f\n",
                   current->data.medi_name, current->data.supplier_name, current->data.purchase_price);
        }
        current = current->next;
    }
}


#endif // REPPORT_H_INCLUDED

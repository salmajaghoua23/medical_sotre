#ifndef MEDICAMENT_H_INCLUDED
#define MEDICAMENT_H_INCLUDED
#include"interface.h"
#include"medical.h"
#include"menu_adm.h"
#include"employer.h"
#include"panier.h"
#include"commande.h"
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
#include"menu_client.h"
medical med;
void displayMedicines1();
struct customer{
	int cust_id;
	char cust_name[30];
	char city[20];
	char mob_no[11];
	char email[50];

};

struct bill {
    char billno[6];
    char cname[30];
    char mediname[30];
    int medi_qty;
    float medi_rate;
    float total;
    int day;
    int month;
    int year;
};

 struct admin{
	int admin_id;
	char admin_name[25];
    char password[15];

};

struct Ordonnance {
    char doctor_name[50];
    char specialty[30];
    char cabinet_address[100];
    char cabinet_phone[20];
    char signature[50];
    char rpps_number[20];
    char prescription_date[15];
    char validity_period[15];
};


int verifyLoginAdmin() {
    FILE *file = fopen("admins1.txt", "r");
    if (!file) {
        textcolor(4);
        printf("Error opening the administrator file.\n");
        textcolor(7);
        return 0;
    }

    struct admin adminTemp;
    char enteredName[25], enteredPassword[15];
    int attempts = 0, found = 0;

    while (attempts < 3) {
        system("cls");


        textcolor(14);
        int i;
        for (i = 3; i < 28; i++) {
            gotoxy(25, i);
            printf("║");
            gotoxy(110, i);
            printf("║");
        }
        for (i = 25; i < 111; i++) {
            gotoxy(i, 3);
            printf("═");
            gotoxy(i, 28);
            printf("═");
        }
        gotoxy(25, 3);
        printf("╔");
        gotoxy(110, 3);
        printf("╗");
        gotoxy(25, 28);
        printf("╚");
        gotoxy(110, 28);
        printf("╝");

        textcolor(2);
        gotoxy(40, 5);
        printf("=============================================");
        textcolor(10);
        gotoxy(40, 6);
        printf("        WELCOME TO THE LOGIN SYSTEM          ");
        textcolor(2);
        gotoxy(40, 7);
        printf("=============================================");

        textcolor(14);
        gotoxy(40, 10);
        printf("╔══════════════════════════════════════╗");
        gotoxy(40, 11);
        printf("║ Username:                            ║");
        gotoxy(40, 12);
        printf("╚══════════════════════════════════════╝");

        gotoxy(40, 14);
        printf("╔══════════════════════════════════════╗");
        gotoxy(40, 15);
        printf("║ Password:                            ║");
        gotoxy(40, 16);
        printf("╚══════════════════════════════════════╝");


        textcolor(7);
        gotoxy(52, 11);
        scanf("%24s", enteredName);


        gotoxy(52, 15);
        int index = 0;
        char ch;
        while ((ch = getch()) != '\r') {
            if (ch == '\b') {
                if (index > 0) {
                    index--;
                    printf("\b \b");
                }
            } else if (index < 14) {
                enteredPassword[index++] = ch;
                printf("*");
            }
        }
        enteredPassword[index] = '\0';


        rewind(file);
        while (fscanf(file, "%d %24s %14s", &adminTemp.admin_id, adminTemp.admin_name, adminTemp.password) == 3) {
            if (strcmp(adminTemp.admin_name, enteredName) == 0 &&
                strcmp(adminTemp.password, enteredPassword) == 0) {
                found = 1;
                break;
            }
        }

        if (found) {

            textcolor(10);
            gotoxy(40, 20);
            printf("╔══════════════════════════════════════════════════════╗");
            gotoxy(40, 21);
            printf("║  Login successful: Administrator authenticated!      ║");
            gotoxy(40, 22);
            printf("╚══════════════════════════════════════════════════════╝");
            textcolor(7);
            fclose(file);
            return 1;
        } else {

            textcolor(4);
            gotoxy(40, 20);
            printf("╔══════════════════════════════════════════════════════╗");
            gotoxy(40, 21);
            printf("║  Login failed: Please check your credentials.        ║");
            gotoxy(40, 22);
            printf("╚══════════════════════════════════════════════════════╝");
            textcolor(7);
            attempts++;
            gotoxy(40, 24);
            printf("You have %d attempt(s) left.", 3 - attempts);
            getch();
        }
    }

    fclose(file);


    textcolor(4);
    system("cls");
    gotoxy(40, 20);
    printf("╔══════════════════════════════════════════════════════╗");
    gotoxy(40, 21);
    printf("║  Access denied: Maximum attempts exceeded.           ║");
    gotoxy(40, 22);
    printf("╚══════════════════════════════════════════════════════╝");
    textcolor(7);
    return 0;
}


void menuEmploye() {
    int choice;

    do {
        system("cls");


        textcolor(14);
        int i;
        for (i = 3; i < 28; i++) {
            gotoxy(25, i);
            printf("║");
            gotoxy(110, i);
            printf("║");
        }
        for (i = 25; i < 111; i++) {
            gotoxy(i, 3);
            printf("═");
            gotoxy(i, 28);
            printf("═");
        }
        gotoxy(25, 3);
        printf("╔");
        gotoxy(110, 3);
        printf("╗");
        gotoxy(25, 28);
        printf("╚");
        gotoxy(110, 28);
        printf("╝");


        textcolor(2);
        gotoxy(40, 5);
        printf("=============================================");
        textcolor(10);
        gotoxy(40, 6);
        printf("          PHARMACY SYSTEM EMPLOYEE MENU      ");
        textcolor(2);
        gotoxy(40, 7);
        printf("=============================================");

        // Menu options
        textcolor(15); // White
        gotoxy(30, 10);
        printf("1. View Medicine Information");
        gotoxy(30, 12);
        printf("2. Place an Order");
        gotoxy(30, 14);
        printf("3. Cancel an Order");
        gotoxy(30, 16);
        printf("4. Exit");


        textcolor(7);
        gotoxy(30, 19);
        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice) {
            case 1:
               displayMedicines1();
                break;

            case 2:
               // place_order();
                break;

            case 3:
              // removeFromCart() ;
                break;

            case 4:
                textcolor(10);
                gotoxy(30, 22);
                printf("Exiting Employee Menu. Goodbye!");
                textcolor(7);
                break;

            default:
                textcolor(4);
                gotoxy(30, 22);
                printf("Invalid choice! Please try again.");
                textcolor(7);
                getch();
                break;
        }
    } while (choice != 4);
}



int verifyLoginEmployee() {
    FILE *file = fopen("employer.txt", "r");
    if (!file) {
        textcolor(4); // Red for error
        printf("Error opening the employee file.\n");
        textcolor(7); // Reset color
        return 0;
    }

    char enteredName[50], enteredContact[100];
    Employe employeeTemp;
    int found = 0;

    int attempts = 0;
    while (attempts < 3) {
        system("cls");


        textcolor(14);
        int i;
        for (i = 3; i < 28; i++) {
            gotoxy(25, i);
            printf("║");
            gotoxy(110, i);
            printf("║");
        }
        for (i = 25; i < 111; i++) {
            gotoxy(i, 3);
            printf("═");
            gotoxy(i, 28);
            printf("═");
        }
        gotoxy(25, 3);
        printf("╔");
        gotoxy(110, 3);
        printf("╗");
        gotoxy(25, 28);
        printf("╚");
        gotoxy(110, 28);
        printf("╝");


        textcolor(2);
        gotoxy(40, 5);
        printf("=============================================");
        textcolor(10);
        gotoxy(40, 6);
        printf("          EMPLOYER LOGIN SYSTEM              ");
        textcolor(2);
        gotoxy(40, 7);
        printf("=============================================");


        textcolor(14);
        gotoxy(40, 11);
        printf("╔══════════════════════════════════════╗");
        gotoxy(40, 12);
        printf("║ Employer Name:                       ║");
        gotoxy(40, 13);
        printf("╚══════════════════════════════════════╝");

        gotoxy(40, 15);
        printf("╔══════════════════════════════════════╗");
        gotoxy(40, 16);
        printf("║ Contact (Password):                  ║");
        gotoxy(40, 17);
        printf("╚══════════════════════════════════════╝");

        textcolor(7);
        gotoxy(60, 12);
        scanf("%49s", enteredName);


        gotoxy(61, 16);
        int index = 0;
        char ch;
        while (1) {
            ch = getch();
            if (ch == 13) {
                enteredContact[index] = '\0';
                break;
            } else if (ch == 8) {
                if (index > 0) {
                    index--;
                    printf("\b \b");
                }
            } else if (index < 99) {
                enteredContact[index++] = ch;
                printf("*");
            }
        }


        rewind(file);
        while (fscanf(file, "%d %49s %49s %99s %f",
                      &employeeTemp.employeID,
                      employeeTemp.nom,
                      employeeTemp.role,
                      employeeTemp.contact,
                      &employeeTemp.salaire) == 5) {
            if (strcmp(employeeTemp.nom, enteredName) == 0 && strcmp(employeeTemp.contact, enteredContact) == 0) {
                found = 1;
                break;
            }
        }

        if (found) {

            textcolor(10);
            gotoxy(40, 20);
            printf("╔══════════════════════════════════════════════════════╗");
            gotoxy(40, 21);
            printf("║  Login successful: Employee authenticated.           ║");
            gotoxy(40, 22);
            printf("╚══════════════════════════════════════════════════════╝");
            textcolor(7);
            fclose(file);
            return 1;
        } else {

            textcolor(4);
            gotoxy(40, 20);
            printf("╔══════════════════════════════════════════════════════╗");
            gotoxy(40, 21);
            printf("║  Login failed: Incorrect credentials.                ║");
            gotoxy(40, 22);
            printf("╚══════════════════════════════════════════════════════╝");
            textcolor(7);
            attempts++;
            gotoxy(40, 24);
            printf("You have %d attempt(s) remaining.", 3 - attempts);
            getch();
        }
    }

    fclose(file);


    textcolor(4);
    system("cls");
    gotoxy(40, 20);
    printf("╔══════════════════════════════════════════════════════╗");
    gotoxy(40, 21);
    printf("║  Access denied: Too many failed login attempts.      ║");
    gotoxy(40, 22);
    printf("╚══════════════════════════════════════════════════════╝");
    textcolor(7);
    return 0;
}


 /*void menuBasket() {
    int i;

    textcolor(2);
    for (i = 3; i < 28; i++) {
        gotoxy(25, i);
        printf("║");
        gotoxy(110, i);
        printf("║");
    }

    for (i = 26; i < 111; i++) {
        gotoxy(i, 28);
        printf("═");
    }

    for (i = 26; i < 110; i++) {
        gotoxy(i, 3);
        printf("═");
    }

    gotoxy(25, 3);
    printf("╔");
    gotoxy(110, 3);
    printf("╗");
    gotoxy(25, 28);
    printf("╚");
    gotoxy(110, 28);
    printf("╝");


    textcolor(10);
    gotoxy(53, 2);
    printf("╔══════════════════════════════╗");
    gotoxy(53, 3);
    printf("║       PHARMACY SYSTEM        ║");
    gotoxy(53, 4);
    printf("╚══════════════════════════════╝");


    textcolor(14);
    for (i = 11; i < 25; i++) {
        gotoxy(45, i);
        printf("║");
        gotoxy(90, i);
        printf("║");
    }

    for (i = 46; i < 90; i++) {
        gotoxy(i, 25);
        printf("═");
    }
    gotoxy(45, 25);
    printf("╚");
    gotoxy(90, 25);
    printf("╝");

    for (i = 46; i < 90; i++) {
        gotoxy(i, 10);
        printf("═");
    }
    gotoxy(45, 10);
    printf("╔");
    gotoxy(90, 10);
    printf("╗");

    textcolor(14);
    gotoxy(58, 9);
    printf("╔═════════════════════════╗");
    gotoxy(58, 10);
    printf("║      BASKET CONSULT     ║");
    gotoxy(58, 11);
    printf("╚═════════════════════════╝");

    textcolor(15);
    gotoxy(58, 13);
    printf("1. Show my basket");

    gotoxy(58, 15);
    printf("2. Remove medicine");

    gotoxy(58, 17);
    printf("3. Confirm order");

    gotoxy(58, 19);
    printf("4. Return to menu");

    textcolor(7);
    gotoxy(65, 22);
    printf("╔═══╗");
    gotoxy(65, 23);
    printf("║   ║");
    gotoxy(65, 24);
    printf("╚═══╝");

    textcolor(7);
}*/
struct bill bil;

void bill() {
    time_t td = time(0);
    struct tm *now = localtime(&td);

    FILE *ptrbill;
    char id[6];
    int j = 1, d1, m, y, i;
    float netamt = 0.0;


    d1 = now->tm_mday;
    m = now->tm_mon + 1;
    y = now->tm_year + 1900;

    system("cls");
    ptrbill = fopen("dbbill.dat", "r");
    if (ptrbill == NULL) {
        printf("Error: Unable to open the file 'dbbill.dat'.\n");
        return;
    }

    gotoxy(13, 4);
    printf("Enter bill no: ");
    scanf("%s", id);

    system("cls");
    gotoxy(25, 3);
    textcolor(14);
    printf("** CareWell Medico **");

    gotoxy(7, 7);
    printf("Bill No: %s", id);

    gotoxy(7, 9);
    printf("Customer Name: ");

    gotoxy(50, 7);
    printf("Date: %d-%d-%d", d1, m, y);

    gotoxy(7, 12);
    printf("Sr.No   Medicine Name       Qty          Rate         Total ");
    gotoxy(6, 14);
    printf("-------------------------------------------------------------------------------");

    i = 15;

    while (fscanf(ptrbill, "%s %s %s %d %f %f %d %d %d",
                  bil.billno, bil.cname, bil.mediname,
                  &bil.medi_qty, &bil.medi_rate, &bil.total,
                  &bil.day, &bil.month, &bil.year) != EOF) {
        if (strcmp(id, bil.billno) == 0) { // Comparer les numéros de facture
            gotoxy(7, i);
            printf(" %d", j);
            gotoxy(14, i);
            printf(" %s", bil.mediname);
            gotoxy(22, 9);
            printf(" %s", bil.cname);
            gotoxy(35, i);
            printf(" %d", bil.medi_qty);
            gotoxy(47, i);
            printf(" %.2f", bil.medi_rate);
            gotoxy(60, i);
            printf(" %.2f", bil.total);
            netamt += bil.total;
            i++;
            j++;
        }
    }

    gotoxy(6, 35);
    printf("---------------------------------------------------------------------------");
    gotoxy(50, 37);
    printf("\n\n Net Amount: %.2f", netamt);

    fclose(ptrbill); // Fermer le fichier
    getch(); // Attendre une touche de l'utilisateur
}



// Function to verify ordonnance information entered by a client
void verifyOrdonnance() {
    system("cls");


    textcolor(14);
    int i;
    for (i = 3; i < 28; i++) {
        gotoxy(25, i);
        printf("║");
        gotoxy(110, i);
        printf("║");
    }
    for (i = 25; i < 111; i++) {
        gotoxy(i, 3);
        printf("═");
        gotoxy(i, 28);
        printf("═");
    }
    gotoxy(25, 3);
    printf("╔");
    gotoxy(110, 3);
    printf("╗");
    gotoxy(25, 28);
    printf("╚");
    gotoxy(110, 28);
    printf("╝");


    textcolor(10);
    gotoxy(43, 5);
    printf("===============================================");
    gotoxy(45, 6);
    printf("              VERIFY ORDONNANCE                ");
    gotoxy(43, 7);
    printf("===============================================");


    textcolor(14);
    gotoxy(35, 9);
    printf("╔══════════════════════════════════════════════╗");
    gotoxy(35, 10);
    printf("║                INPUT DETAILS                 ║");
    gotoxy(35, 11);
    printf("╚══════════════════════════════════════════════╝");


    textcolor(7);
    gotoxy(35, 13);
    printf("Doctor's Name: ");
    gotoxy(35, 14);
    printf("Specialty: ");
    gotoxy(35, 15);
    printf("RPPS Number: ");
    gotoxy(35, 16);
    printf("Prescription Date: ");

    struct Ordonnance *inputOrdonnance = malloc(sizeof(struct Ordonnance));
    if (inputOrdonnance == NULL) {
        textcolor(4);
        gotoxy(50, 18);
        printf("Memory allocation error.");
        return;
    }

   gotoxy(55, 13);
fgets(inputOrdonnance->doctor_name, sizeof(inputOrdonnance->doctor_name), stdin);
inputOrdonnance->doctor_name[strcspn(inputOrdonnance->doctor_name, "\n")] = '\0'; // Supprime le caractère '\n'

gotoxy(55, 14);
fgets(inputOrdonnance->specialty, sizeof(inputOrdonnance->specialty), stdin);
inputOrdonnance->specialty[strcspn(inputOrdonnance->specialty, "\n")] = '\0';

gotoxy(55, 15);
fgets(inputOrdonnance->rpps_number, sizeof(inputOrdonnance->rpps_number), stdin);
inputOrdonnance->rpps_number[strcspn(inputOrdonnance->rpps_number, "\n")] = '\0';

gotoxy(55, 16);
fgets(inputOrdonnance->prescription_date, sizeof(inputOrdonnance->prescription_date), stdin);
inputOrdonnance->prescription_date[strcspn(inputOrdonnance->prescription_date, "\n")] = '\0';


    FILE *file = fopen("ordonnances.txt", "r");
    if (file == NULL) {
        textcolor(4);
        gotoxy(50, 18);
        printf("Error opening the file.");
        free(inputOrdonnance);
        return;
    }

    struct Ordonnance fileOrdonnance;
    int found = 0;



    while (fscanf(file, "%49[^|]|%29[^|]|%99[^|]|%19[^|]|%49[^|]|%19[^|]|%14[^|]|%14[^\n]\n",
                  fileOrdonnance.doctor_name, fileOrdonnance.specialty, fileOrdonnance.cabinet_address,
                  fileOrdonnance.cabinet_phone, fileOrdonnance.signature, fileOrdonnance.rpps_number,
                  fileOrdonnance.prescription_date, fileOrdonnance.validity_period) != EOF) {

        if (strcmp(inputOrdonnance->doctor_name, fileOrdonnance.doctor_name) == 0 &&
            strcmp(inputOrdonnance->specialty, fileOrdonnance.specialty) == 0 &&
            strcmp(inputOrdonnance->rpps_number, fileOrdonnance.rpps_number) == 0 &&
            strcmp(inputOrdonnance->prescription_date, fileOrdonnance.prescription_date) == 0) {

            found = 1;


             textcolor(2);
            for (i = 3; i < 28; i++) {
                gotoxy(25, i);
                printf("║");
                gotoxy(110, i);
                printf("║");
            }
            for (i = 25; i < 111; i++) {
                gotoxy(i, 3);
                printf("═");
                gotoxy(i, 28);
                printf("═");
            }
            gotoxy(25, 3);
            printf("╔");
            gotoxy(110, 3);
            printf("╗");
            gotoxy(25, 28);
            printf("╚");
            gotoxy(110, 28);
            printf("╝");

            textcolor(10);
            gotoxy(50, 5);
            printf("===============================================");
            gotoxy(50, 6);
            printf("            ORDONNANCE VERIFIED                ");
            gotoxy(50, 7);
            printf("===============================================");

            textcolor(7);
            gotoxy(30, 10);
            printf("Doctor's Name: %s", fileOrdonnance.doctor_name);
            gotoxy(30, 11);
            printf("Specialty: %s", fileOrdonnance.specialty);
            gotoxy(30, 12);
            printf("Cabinet Address: %s", fileOrdonnance.cabinet_address);
            gotoxy(30, 13);
            printf("Cabinet Phone: %s", fileOrdonnance.cabinet_phone);
            gotoxy(30, 14);
            printf("Signature: %s", fileOrdonnance.signature);
            gotoxy(30, 15);
            printf("RPPS Number: %s", fileOrdonnance.rpps_number);
            gotoxy(30, 16);
            printf("Prescription Date: %s", fileOrdonnance.prescription_date);
            gotoxy(30, 17);
            printf("Validity Period: %s", fileOrdonnance.validity_period);

            break;
        }
    }

    if (!found) {
        textcolor(4);
        gotoxy(40, 22);
        printf("No matching ordonnance found.");
        textcolor(7);
    }

    fclose(file);
    free(inputOrdonnance);


    gotoxy(40, 25);
    textcolor(7);
    printf("\n\n\n\n\n\n\n\n\n\n Press any key to return...");
    getch();
}

void displayMedicines1() {
    FILE *file = fopen("medicenes.txt", "r");
    if (file == NULL) {
        textcolor(12);
        printf("File 'medicenes.txt' not found . .\n");
        getch();
        return;
    }

    system("cls");


    textcolor(14);
    gotoxy(25, 2);
    printf("╔═════════════════════════════════════════════════════════════════════════╗");
    gotoxy(25, 3);
    textcolor(10);
    printf("║                           PHARMACY SYSTEM                               ║");
    textcolor(14);
    gotoxy(25, 4);
    printf("╚═════════════════════════════════════════════════════════════════════════╝");

    textcolor(14);
    gotoxy(25, 6);
    printf("╔═══════╦══════════════════════╦══════════╦══════════╦════════════════════╗");
    gotoxy(25, 7);
    printf("║  ID   ║    Medicine Name     ║ Quantity ║   Cost   ║   Expiration Date  ║");
    gotoxy(25, 8);
    printf("╠═══════╬══════════════════════╬══════════╬══════════╬════════════════════╣");

    int row = 9;


    while (fscanf(file, "%5s %19s %d %d %d %f %f %f %14s %29s",
                  med.id, med.medi_name, &med.quantity, &med.id_prescription,
                  &med.quantity_sold, &med.cost, &med.profit, &med.purchase_price,
                  med.exp_date, med.supplier_name) == 10) {
        textcolor(7);
        gotoxy(25, row);
        printf("║ %-5s ║ %-20s ║ %-8d ║ %-8.2f ║ %-18s ║",
               med.id, med.medi_name, med.quantity, med.cost, med.exp_date);

        row++;


        if ((row - 9) % 5 == 0) {
            textcolor(14);
            gotoxy(25, row);
            printf("╟───────┼──────────────────────┼──────────┼──────────┼────────────────────╢");
            row++;
        }
    }

    textcolor(14);
    gotoxy(25, row);
    printf("╚═══════╩══════════════════════╩══════════╩══════════╩════════════════════╝");

    fclose(file);


    textcolor(10);
    gotoxy(40, row + 2);
    printf("Press any key to return to the menu...");
    textcolor(7);
    getch();
}


void createAdmin() {
    system("cls");

    textcolor(14);
    int i;


    for (i = 3; i < 28; i++) {
        gotoxy(25, i); printf("║");
        gotoxy(110, i); printf("║");
    }
    for (i = 25; i < 111; i++) {
        gotoxy(i, 3); printf("═");
        gotoxy(i, 28); printf("═");
    }
    gotoxy(25, 3); printf("╔");
    gotoxy(110, 3); printf("╗");
    gotoxy(25, 28); printf("╚");
    gotoxy(110, 28); printf("╝");

    textcolor(2);
    gotoxy(40, 5);
    printf("=============================================");
    textcolor(10);
    gotoxy(40, 6);
    printf("        WELCOME TO OUR PHARMACY SYSTEM       ");
    textcolor(2);
    gotoxy(40, 7);
    printf("=============================================");


    textcolor(13);
    gotoxy(35, 9);
    printf("No administrator found in the system. Please create one.");
    textcolor(14);
    gotoxy(40, 12);
    printf("╔══════════════════════════════════════╗");
    gotoxy(40, 13);
    printf("║ Admin ID:                            ║");
    gotoxy(40, 14);
    printf("╚══════════════════════════════════════╝");

    gotoxy(40, 16);
    printf("╔══════════════════════════════════════╗");
    gotoxy(40, 17);
    printf("║ Name:                                ║");
    gotoxy(40, 18);
    printf("╚══════════════════════════════════════╝");

    gotoxy(40, 20);
    printf("╔══════════════════════════════════════╗");
    gotoxy(40, 21);
    printf("║ Password:                            ║");
    gotoxy(40, 22);
    printf("╚══════════════════════════════════════╝");


    struct admin newAdmin;
    newAdmin.admin_id = 1;

    textcolor(7);
    gotoxy(53, 13);
    printf("%d", newAdmin.admin_id);
    gotoxy(48, 17);
    fgets(newAdmin.admin_name, 20, stdin);
    newAdmin.admin_name[strcspn(newAdmin.admin_name, "\n")] = 0;

    gotoxy(52, 21);
    fgets(newAdmin.password, 20, stdin);
    newAdmin.password[strcspn(newAdmin.password, "\n")] = 0;

    // Enregistrement des données dans le fichier
    FILE *file = fopen("admins1.txt", "a");
    if (file != NULL) {
        fprintf(file, "%d %s %s\n", newAdmin.admin_id, newAdmin.admin_name, newAdmin.password);
        fclose(file);
    }

    // Confirmation de la création de l'admin
    textcolor(10);
    gotoxy(40, 25);
    printf("╔══════════════════════════════════════════════╗");
    gotoxy(40, 26);
    printf("║  Pharmacy administrator created successfully! ║");
    gotoxy(40, 27);
    printf("╚══════════════════════════════════════════════╝");


    textcolor(7);
}

void createCustomerAccount() {
    printf("\033[1;36m");
    int i;
    for (i = 3; i < 28; i++) {
        gotoxy(25, i);
        printf("*");
        gotoxy(110, i);
        printf("*");
    }
    for (i = 25; i < 111; i++) {
        gotoxy(i, 28);
        printf("*");
    }
    for (i = 25; i < 52; i++) {
        gotoxy(i, 3);
        printf("*");
    }
    for (i = 80; i < 110; i++) {
        gotoxy(i, 3);
        printf("*");
    }
    gotoxy(53, 1); printf("*");
    gotoxy(53, 2); printf("*                             *");
    gotoxy(53, 3); printf("*     Pharmacy System         *");
    gotoxy(53, 5); printf("*");
    printf("\033[0m");

    struct customer newCustomer;

    printf("\033[1;36m");
    gotoxy(35, 10);
    printf("No customer found in the system, please create one.\n");
    printf("\033[0m");

    printf("\033[1;35m");
    gotoxy(45, 12);
    printf("--------------------------------------------");
    gotoxy(45, 13); printf("|                                            |");
    gotoxy(45, 14); printf("|                                            |");
    gotoxy(45, 15); printf("|                                            |");
    gotoxy(45, 16); printf("|                                            |");
    gotoxy(45, 17); printf("|                                            |");
    gotoxy(45, 18); printf("|                                            |");
    gotoxy(45, 19); printf("|                                            |");
    gotoxy(45, 20); printf("|                                            |");
    gotoxy(45, 21); printf("|                                            |");
    gotoxy(45, 22); printf("|                                            |");
    gotoxy(45, 23); printf("|                                            |");
    gotoxy(45, 24); printf("--------------------------------------------");

    // Prompt user to enter customer details
    gotoxy(55, 13); printf("Customer ID: ");
    gotoxy(65, 13); scanf("%d", &newCustomer.cust_id);

    gotoxy(55, 15); printf("Name: ");
    gotoxy(65, 15); getchar(); // Clear newline from previous input
    fgets(newCustomer.cust_name, 30, stdin);
    newCustomer.cust_name[strcspn(newCustomer.cust_name, "\n")] = 0;

    gotoxy(55, 17); printf("City: ");
    gotoxy(65, 17); fgets(newCustomer.city, 20, stdin);
    newCustomer.city[strcspn(newCustomer.city, "\n")] = 0;

    gotoxy(55, 19); printf("Mobile No: ");
    gotoxy(65, 19); fgets(newCustomer.mob_no, 11, stdin);
    newCustomer.mob_no[strcspn(newCustomer.mob_no, "\n")] = 0;

    gotoxy(55, 21); printf("Email: ");
    gotoxy(65, 21); fgets(newCustomer.email, 50, stdin);
    newCustomer.email[strcspn(newCustomer.email, "\n")] = 0;

    printf("\033[0m");

    // Save to file
    FILE *file = fopen("pharmacy_customers.txt", "a");
    if (file != NULL) {
        fprintf(file, "Customer ID: %d\n", newCustomer.cust_id);
        fprintf(file, "Name: %s\n", newCustomer.cust_name);
        fprintf(file, "City: %s\n", newCustomer.city);
        fprintf(file, "Mobile: %s\n", newCustomer.mob_no);
        fprintf(file, "Email: %s\n\n", newCustomer.email);
        fclose(file);
        gotoxy(50, 25);
        printf("Customer account has been created successfully.\n\n\n\n");
    } else {
        gotoxy(50, 25);
        printf("Failed to open file for saving customer details.\n\n\n\n");
    }
}

int verifyCustomerLogin(int customerId, char *mobileNo) {
    struct customer storedCustomer;
    FILE *file = fopen("pharmacy_customers.txt", "r+");

    if (!file) {
        printf("Error: Unable to open customer file.\n");
        return 0;
    }

    int authenticated = 0;
    int attempts = 0;
    const int maxAttempts = 3;

    while (!authenticated && attempts < maxAttempts) {
        // Display the login screen
        printf("\033[1;36m");
        for (int i = 3; i < 28; i++) {
            gotoxy(25, i);
            printf("*");
            gotoxy(110, i);
            printf("*");
        }
        for (int i = 25; i < 111; i++) {
            gotoxy(i, 28);
            printf("*");
        }
        gotoxy(53, 1); printf("*");
        gotoxy(53, 2); printf("*                             *");
        gotoxy(53, 3); printf("*       Customer Login        *");
        gotoxy(53, 4); printf("*                             *");
        gotoxy(53, 5); printf("*");
        printf("\033[0m");

        printf("\033[1;35m");
        gotoxy(51, 10);
        printf("----------------------------");
        gotoxy(51, 11); printf("|      Enter Login Details   |");
        printf("\033[0m");

        printf("\033[1;35m");
        gotoxy(45, 12);
        printf("--------------------------------------------");
        gotoxy(45, 13); printf("|                                            |");
        gotoxy(45, 14); printf("|                                            |");
        gotoxy(45, 15); printf("|                                            |");
        gotoxy(45, 16); printf("|                                            |");
        gotoxy(45, 17); printf("|                                            |");
        gotoxy(45, 18); printf("|                                            |");
        gotoxy(45, 19); printf("|                                            |");
        gotoxy(45, 20); printf("|                                            |");
        gotoxy(45, 21); printf("|                                            |");
        gotoxy(45, 22); printf("|                                            |");
        gotoxy(45, 23); printf("|                                            |");
        gotoxy(45, 24); printf("--------------------------------------------");

        gotoxy(60, 14);
        printf("Customer ID ");
        gotoxy(61, 19);
        printf("Mobile Number ");
        printf("\033[0m");

        gotoxy(54, 15); printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ");
        gotoxy(54, 16); printf("³                          ³ ");
        gotoxy(54, 17); printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
        gotoxy(54, 20); printf("ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ");
        gotoxy(54, 21); printf("³                          ³ ");
        gotoxy(54, 22); printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");

        // Collect login information
        gotoxy(56, 16);
        scanf("%d", &customerId);
        gotoxy(56, 21);
        scanf("%10s", mobileNo);

        // Reset file pointer to beginning for each attempt
        fseek(file, 0, SEEK_SET);
        authenticated = 0;

        // Check credentials in file
        while (fscanf(file, "Customer ID: %d\nName: %29[^\n]\nCity: %19[^\n]\nMobile: %10s\nEmail: %49[^\n]\n",
                      &storedCustomer.cust_id, storedCustomer.cust_name, storedCustomer.city,
                      storedCustomer.mob_no, storedCustomer.email) == 5) {
            if (storedCustomer.cust_id == customerId && strcmp(storedCustomer.mob_no, mobileNo) == 0) {
                authenticated = 1;
                break;
            }
        }

        if (!authenticated) {
            attempts++;
            printf("\033[1;31m");
            gotoxy(39, 25);
            printf("Incorrect Customer ID or mobile number! Please try again.\n");
            printf("\033[0m");

            if (attempts < maxAttempts) {
                printf("\033[1;33m");
                gotoxy(39, 26);
                printf("You have %d attempt(s) left.\n", maxAttempts - attempts);
                printf("\033[0m");
            }
        }
    }

    fclose(file);

    if (!authenticated) {
        printf("\033[1;31m");
        printf("Maximum attempts reached. Access Denied.\n");
        printf("\033[0m");
    }

    return authenticated;

}
void menuP() {
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
    gotoxy(40, 10); printf("1. ADMIN   ");
    gotoxy(40, 12); printf("2. EMPLOYEE");
    gotoxy(40, 14); printf("3. CUSTOMER");
    gotoxy(40, 16); printf("4. EXIT    ");


    textcolor(7);
    gotoxy(28, 22);
    printf("\n\n\n\n\n\n\n\n\n\n\n\nPRESS THE NUMBER OF THE OPTION THAT WHAT YOU WANT .........?\n\n");


    textcolor(7);
}
void menuprincipale() {
    int choix = 0;
    FILE *file = fopen("admins1.txt", "r");

    // Si le fichier administrateur n'existe pas, on crée un administrateur
    if (file == NULL) {
        createAdmin();
        return;
    }
    fclose(file);

    // Affichage du menu principal
    menuP();

    while (choix != 4) {
        gotoxy(67, 23);
        char c = getch();
        choix = c - '0';
        system("cls");

        switch (choix) {
            case 1:
                if(verifyLoginAdmin()==1){
                    system("cls");
                    main_menu();
                }else{
                    system("cls");
                     menuP();
                      textcolor(12);
                      gotoxy(43, 27);
                      printf("Login échoué. Retour au menu principal.");
                     textcolor(7);
                 }

                break;

            case 2:
    if (verifyLoginEmployee() == 1) {
        system("cls");
        menuEmploye();
    } else {
        system("cls");
        menuP();
        textcolor(12);
        gotoxy(43, 27);
        printf("Login échoué. Retour au menu principal.");
        textcolor(7);
    }
                break;

            case 3:
              // menu_client();
                break;
            case 4:
                system("cls");
                textcolor(10);
                gotoxy(53, 10);
                printf("╔════════════════════════════════╗");
                gotoxy(53, 11);
                printf("║           THANK YOU!           ║");
                gotoxy(53, 12);
                printf("║      FOR STOPPING BY :)        ║");
                gotoxy(53, 13);
                printf("╚════════════════════════════════╝");
                textcolor(7);
                break;

            default:
                menuP();
                textcolor(12);
                gotoxy(43, 27);
                printf("Invalid option. Please choose a valid option.");
                textcolor(7);
        }
    }
}

#endif // MEDICAMENT_H_INCLUDED

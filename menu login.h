#ifndef MEDICAMENT_H_INCLUDED
#define MEDICAMENT_H_INCLUDED
#include"interface.h"
#include"medical.h"
#include<stdlib.h>
#include <windows.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<dos.h>
#include<time.h>
#include<ctype.h>
#include"employer.h"

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
    FILE *file = fopen("admins.txt", "r");
    if (!file) {
        textcolor(4); // Rouge
        printf("Erreur lors de l'ouverture du fichier administrateurs.\n");
        textcolor(7); // Réinitialisation
        return 0;
    }

    struct admin adminTemp;
    char enteredName[25], enteredPassword[15];
    int attempts = 0, found = 0;

    while (attempts < 3) {
        system("cls"); // Effacer l'écran

        // Design principal
        textcolor(2); // Vert
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
        gotoxy(45, 2);
        printf("╔════════════════════════════════════╗");
        gotoxy(45, 3);
        printf("║      SYSTEME DE GESTION D'ADMIN    ║");
        gotoxy(45, 4);
        printf("╚════════════════════════════════════╝");

        // Formulaire de saisie
        textcolor(14);
        gotoxy(40, 10);
        printf("╔══════════════════════════════════════╗");
        gotoxy(40, 11);
        printf("║ Nom d'utilisateur :                  ║");
        gotoxy(40, 12);
        printf("╚══════════════════════════════════════╝");

        gotoxy(40, 14);
        printf("╔══════════════════════════════════════╗");
        gotoxy(40, 15);
        printf("║ Mot de passe :                       ║");
        gotoxy(40, 16);
        printf("╚══════════════════════════════════════╝");

        textcolor(7); // Blanc
        gotoxy(65, 11);
        scanf("%24s", enteredName);

        gotoxy(65, 15);
        scanf("%14s", enteredPassword);

        // Vérification dans le fichier
        rewind(file); // Revenir au début du fichier
        while (fscanf(file, "%d %24s %14s", &adminTemp.admin_id, adminTemp.admin_name, adminTemp.password) == 3) {
            printf( "%d %24s %14s", adminTemp.admin_id, adminTemp.admin_name, adminTemp.password);

            if (strcmp(adminTemp.admin_name, enteredName) == 0 &&
                strcmp(adminTemp.password, enteredPassword) == 0) {
                found = 1;
               break;
            }
        }

        if (found) {
            // Login réussi
            textcolor(10); // Vert
            gotoxy(40, 20);
            printf("╔══════════════════════════════════════════════════════╗");
            gotoxy(40, 21);
            printf("║  Login réussi : L'administrateur est authentifié.    ║");
            gotoxy(40, 22);
            printf("╚══════════════════════════════════════════════════════╝");
            textcolor(7); // Réinitialisation
            fclose(file);
            return 1;
        } else {
            // Login échoué
            textcolor(4); // Rouge
            gotoxy(40, 20);
            printf("╔══════════════════════════════════════════════════════╗");
            gotoxy(40, 21);
            printf("║  Login échoué : Vérifiez vos identifiants.           ║");
            gotoxy(40, 22);
            printf("╚══════════════════════════════════════════════════════╝");
            textcolor(7); // Réinitialisation
            attempts++;
            gotoxy(40, 24);
            printf("Il vous reste %d essais.", 3 - attempts);
            getch(); // Attendre une touche pour continuer
        }
    }

    fclose(file);

    // Échec après 3 essais
    textcolor(4); // Rouge
    system("cls");
    gotoxy(40, 20);
    printf("╔══════════════════════════════════════════════════════╗");
    gotoxy(40, 21);
    printf("║  Accès refusé : Nombre d'essais dépassé.             ║");
    gotoxy(40, 22);
    printf("╚══════════════════════════════════════════════════════╝");
    textcolor(7); // Réinitialisation
    return 0;
}
void menuEmploye() {
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

    for (i = 26; i < 52; i++) {
        gotoxy(i, 3);
        printf("═");
    }

    for (i = 80; i < 110; i++) {
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
    printf("╔════════════════╗");
    gotoxy(58, 10);
    printf("║      MENU      ║");
    gotoxy(58, 11);
    printf("╚════════════════╝");


    textcolor(15);
    gotoxy(58, 14);
    printf("1. about  medecine ");

    gotoxy(58, 16);
    printf("2. pass order      ");

    gotoxy(58, 18);
    printf("3. Cancel order    ");

    gotoxy(58, 20);
    printf("4.exit             ");


    textcolor(7);
    gotoxy(65, 22);
    printf("╔═══╗");
    gotoxy(65, 23);
    printf("║   ║");
    gotoxy(65, 24);
    printf("╚═══╝");


    textcolor(7);
}

int verifierLoginEmploye() {
    FILE *file = fopen("employerr.txt", "r");
    if (!file) {
        textcolor(4); // Rouge
        printf("Erreur lors de l'ouverture du fichier employés.\n");
        textcolor(7);
        return 0;
    }

    char nomEntree[50], contactEntree[100];
    Employe employeTemp;
    int found = 0;

    textcolor(2);
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
    gotoxy(45, 2);
    printf("╔════════════════════════════════════╗");
    gotoxy(45, 3);
    printf("║     SYSTEME DE GESTION D'EMPLOYES  ║");
    gotoxy(45, 4);
    printf("╚════════════════════════════════════╝");


    textcolor(14);
    gotoxy(40, 10);
    printf("╔══════════════════════════════════════╗");
    gotoxy(40, 11);
    printf("║ Nom de l'employé:                    ║");
    gotoxy(40, 12);
    printf("╚══════════════════════════════════════╝");

    gotoxy(40, 14);
    printf("╔══════════════════════════════════════╗");
    gotoxy(40, 15);
    printf("║ Contact de l'employé:                ║");
    gotoxy(40, 16);
    printf("╚══════════════════════════════════════╝");


    textcolor(7);
    gotoxy(65, 11);
    scanf("%49s", nomEntree);

    gotoxy(65, 15);
    scanf("%99s", contactEntree);

    // Lecture des données dans le fichier et vérification
    while (fscanf(file, "%d %49s %49s %99s %f",
                  &employeTemp.employeID,
                  employeTemp.nom,
                  employeTemp.role,
                  employeTemp.contact,
                  &employeTemp.salaire) == 5) {
        if (strcmp(employeTemp.nom, nomEntree) == 0 && strcmp(employeTemp.contact, contactEntree) == 0) {
            found = 1; // Correspondance trouvée
            break;
        }
    }

    fclose(file);

    // Résultat affiché avec le design
    if (found) {
        textcolor(10); // Vert pour succès
        gotoxy(40, 20);
        printf("╔══════════════════════════════════════════════════════╗");
        gotoxy(40, 21);
        printf("║  Login réussi : L'employé existe dans le système.    ║");
        gotoxy(40, 22);
        printf("╚══════════════════════════════════════════════════════╝");
        textcolor(7); // Réinitialisation
        return 1; // Succès
    } else {
        textcolor(4); // Rouge pour erreur
        gotoxy(40, 20);
        printf("╔══════════════════════════════════════════════════════╗");
        gotoxy(40, 21);
        printf("║  Login échoué : Aucun employé trouvé.                ║");
        gotoxy(40, 22);
        printf("╚══════════════════════════════════════════════════════╝");
        textcolor(7); // Réinitialisation
        return 0; // Échec
    }
}


 void menuBasket() {
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
}
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

void createOrdonnancesFile() {
    FILE *file = fopen("ordonnances.txt", "w");
    if (file == NULL) {
        printf("Error: unable to create the file.\n");
        return;
    }

    // Writing sample ordonnances data to the file
    fprintf(file, "Dr. Sophie Martin|Cardiologue|123 Rue de la Santé, 75015 Paris|+33 1 45 67 89 10|Signature_Sophie|12345678901|2024-11-14|2025-02-14\n");
    fprintf(file, "Dr. Jean Dupont|Dermatologue|98 Avenue Beaumarchais, 75011 Paris|+33 1 55 23 45 67|Signature_Jean|98765432101|2024-10-01|2025-04-01\n");
    fprintf(file, "Dr. Claire Lefevre|Généraliste|27 Rue de la Liberté, 59000 Lille|+33 3 20 55 88 99|Signature_Claire|11223344556|2024-09-20|2025-09-20\n");

    printf("File 'ordonnances.txt' has been created with sample data.\n");
    fclose(file);
}


// Function to verify ordonnance information entered by a client
void verifyOrdonnance() {
    printf("\033[1;36m");
    gotoxy(53,1); printf("*                             * ");
    gotoxy(53,2); printf("*        PHARMACY SYSTEM      * ");
    gotoxy(53,3); printf("*                             * ");
    gotoxy(53,4); printf("*******************************  ");

    struct Ordonnance *inputOrdonnance = malloc(sizeof(struct Ordonnance));
    if (inputOrdonnance == NULL) {
        printf("Memory allocation error.");
        return;
    }

    FILE *file = fopen("ordonnances.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.");
        free(inputOrdonnance);
        return;
    }

    // Design for user input section
    printf("\033[1;33m\n\n\n");
    int i;
    for (i = 11; i < 20; i++) {
        gotoxy(48, i); printf("³");
        gotoxy(92, i); printf("³");
    }
    for (i = 50; i < 91; i++) {
        gotoxy(i, 20); printf("Ä");
    }
    gotoxy(48, 11); printf("*");
    gotoxy(92, 11); printf("*");
    gotoxy(48, 20); printf("*");
    gotoxy(92, 20); printf("*");

    gotoxy(50, 10); printf("         ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ");
    gotoxy(50, 11); printf("ÄÄÄÄÄÄÄÄÄ´   Ordonnance Input  ÃÄÄÄÄÄÄÄÄÄ");
    gotoxy(50, 12); printf("         ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");

    printf("\033[1;31m");
    gotoxy(55, 15); printf("Doctor's Name: ");
    gotoxy(55, 16); printf("Specialty: ");
    gotoxy(55, 17); printf("RPPS Number: ");
    gotoxy(55, 18); printf("Prescription Date: ");
    printf("\033[0m");

    gotoxy(72, 15); scanf("%49s", inputOrdonnance->doctor_name);
    gotoxy(72, 16); scanf("%29s", inputOrdonnance->specialty);
    gotoxy(72, 17); scanf("%19s", inputOrdonnance->rpps_number);
    gotoxy(72, 18); scanf("%14s", inputOrdonnance->prescription_date);

    // Read through each line in the file and compare
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

            system("cls"); // Clear screen
            printf("\033[1;36m");
            gotoxy(53,1); printf("*                             * ");
            gotoxy(53,2); printf("*        PHARMACY SYSTEM      * ");
            gotoxy(53,3); printf("*                             * ");
            gotoxy(53,4); printf("*******************************  ");
            printf("\033[0;35m");
            printf("\n\n\n\n\t\t\t\t\t\t   | Verified Ordonnance |\n");
            printf("\t\t\t\t\t\t    ---------------------\n");
            printf("\033[0m");

            printf("\tDoctor's Name: %s\n", fileOrdonnance.doctor_name);
            printf("\tSpecialty: %s\n", fileOrdonnance.specialty);
            printf("\tCabinet Address: %s\n", fileOrdonnance.cabinet_address);
            printf("\tCabinet Phone: %s\n", fileOrdonnance.cabinet_phone);
            printf("\tSignature: %s\n", fileOrdonnance.signature);
            printf("\tRPPS Number: %s\n", fileOrdonnance.rpps_number);
            printf("\tPrescription Date: %s\n", fileOrdonnance.prescription_date);
            printf("\tValidity Period: %s\n", fileOrdonnance.validity_period);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No matching ordonnance found.\n");
    }

    fclose(file);
    free(inputOrdonnance);
}

void displayMedicines() {
   FILE *file = fopen("medicaments1.txt", "r");
    if (file == NULL) {
        textcolor(12); // Rouge pour les erreurs
        printf("File 'medicaments1.txt' not found . .\n");


    }

    system("cls"); // Clear the screen

    // Title box
    textcolor(2); // Green for borders
    gotoxy(25, 2);
    printf("╔═════════════════════════════════════════════════════════════════════════╗");
    gotoxy(25, 3);
    printf("║                           PHARMACY SYSTEM                               ║");
    gotoxy(25, 4);
    printf("╚═════════════════════════════════════════════════════════════════════════╝");

    // Table header
    textcolor(14); // Yellow for header
    gotoxy(25, 6);
    printf("╔═══════╦══════════════════════╦══════════╦══════════╦════════════════════╗");
    gotoxy(25, 7);
    printf("║  ID   ║    Medicine Name     ║ Quantity ║   Cost   ║   Expiration Date  ║");
    gotoxy(25, 8);
    printf("╠═══════╬══════════════════════╬══════════╬══════════╬════════════════════╣");

    // Variables for table positioning
    int row = 9; // Start displaying data from row 9

    struct medical med;

    // Read and display selected information for each medicine
    textcolor(7); // White for table content
    while (fscanf(file, "%5s %19s %d %f %14s",
                  med.id, med.medi_name, &med.quantity, &med.cost, med.exp_date) == 5) {
        gotoxy(25, row);
        printf("║ %-5s ║ %-20s ║ %-8d ║ %-8.2f ║ %-18s ║",
               med.id, med.medi_name, med.quantity, med.cost, med.exp_date);

        row++; // Move to the next row

        // Add horizontal line after every 5 rows for better readability
        if ((row - 9) % 5 == 0) {
            gotoxy(25, row);
            printf("╟───────┼──────────────────────┼──────────┼──────────┼────────────────────╢");
            row++;
        }
    }

    // Add table bottom border
    gotoxy(25, row);
    printf("╚═══════╩══════════════════════╩══════════╩══════════╩════════════════════╝");

    fclose(file);

    // Prompt to return to the menu
    textcolor(10); // Green for success
    gotoxy(40, row + 2);
    printf("Press any key to return to the menu...");
    textcolor(7); // Reset to default
    getch(); // Wait for a key press
}

//fonction pour creer un administrateur //
void createAdmin() {

    textcolor(2);
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
    gotoxy(40, 2);
    printf("╔════════════════════════════════════════════╗");
    gotoxy(40, 3);
    printf("║          WELCOME TO PHARMACY SYSTEM        ║");
    gotoxy(40, 4);
    printf("╚════════════════════════════════════════════╝");


    textcolor(13);
    gotoxy(35, 6);
    printf("No administrator found in the system. Please create one.");


    textcolor(14);
    gotoxy(40, 10);
    printf("╔══════════════════════════════════════╗");
    gotoxy(40, 11);
    printf("║ Admin ID:                            ║");
    gotoxy(40, 12);
    printf("╚══════════════════════════════════════╝");

    textcolor(14);
    gotoxy(40, 14);
    printf("╔══════════════════════════════════════╗");
    gotoxy(40, 15);
    printf("║ Name:                                ║");
    gotoxy(40, 16);
    printf("╚══════════════════════════════════════╝");


    textcolor(14);
    gotoxy(40, 18);
    printf("╔══════════════════════════════════════╗");
    gotoxy(40, 19);
    printf("║ Password:                            ║");
    gotoxy(40, 20);
    printf("╚══════════════════════════════════════╝");


    struct admin newAdmin;
    newAdmin.admin_id = 1;


    textcolor(7);
    gotoxy(53, 11);
    printf("%d", newAdmin.admin_id);


    gotoxy(48, 15);
    fgets(newAdmin.admin_name, 20, stdin);
    newAdmin.admin_name[strcspn(newAdmin.admin_name, "\n")] = 0;


    gotoxy(52, 19);
    fgets(newAdmin.password, 20, stdin);
    newAdmin.password[strcspn(newAdmin.password, "\n")] = 0;


    FILE *file = fopen("admins.txt", "a");
    if (file != NULL) {
        fprintf(file, "Admin ID: %d\n", newAdmin.admin_id);
        fprintf(file, "Name: %s\n", newAdmin.admin_name);
        fprintf(file, "Password: %s\n", newAdmin.password);
        fclose(file);
    }


    textcolor(10);
    gotoxy(40, 23);
    printf("╔══════════════════════════════════════════════╗");
    gotoxy(40, 24);
    printf("║  Pharmacy administrator created successfully! ║");
    gotoxy(40, 25);
    printf("╚══════════════════════════════════════════════╝");
    printf("\n\n\n\n\n\n\n\n\n");

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
    FILE *file = fopen("pharmacy_customers.txt", "r");

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

    for (i = 26; i < 52; i++) {
        gotoxy(i, 3);
        printf("═");
    }

    for (i = 80; i < 110; i++) {
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
    printf("╔════════════════╗");
    gotoxy(58, 10);
    printf("║      MENU      ║");
    gotoxy(58, 11);
    printf("╚════════════════╝");


    textcolor(15);
    gotoxy(58, 14);
    printf("1. Admin");

    gotoxy(58, 16);
    printf("2. Employee");

    gotoxy(58, 18);
    printf("3. Customer");

    gotoxy(58, 20);
    printf("4. Exit");


    textcolor(7);
    gotoxy(65, 22);
    printf("╔═══╗");
    gotoxy(65, 23);
    printf("║   ║");
    gotoxy(65, 24);
    printf("╚═══╝");


    textcolor(7);
}
void menuprincipale() {
    int choix = 0;
    FILE *file = fopen("admins.txt", "r");

    // Si le fichier administrateur n'existe pas, on crée un administrateur
    if (file == NULL) {
        createAdmin(); // Fonction à implémenter ailleurs
        return;
    }
    fclose(file);

    // Affichage du menu principal stylisé
    menuP(); // Fonction du menu principal (cadre)

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
    if (verifierLoginEmploye() == 1) {
        system("cls");
        menuEmploye();
    } else {
        system("cls");
        menuEmploye();
        textcolor(12);
        gotoxy(43, 27);
        printf("Login échoué. Retour au menu principal.");
        textcolor(7);
    }
                break;

            case 3:
               menu();
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

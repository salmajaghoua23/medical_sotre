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
#include"client_info.h"
#include"menu_client.h"
typedef struct {
    char doctor_name[50];
    char specialty[30];
    char cabinet_address[100];
    char cabinet_phone[20];
    char signature[50];
    char rpps_number[20];
    char prescription_date[15];
    char validity_period[15];
    char code_barre[30];
} Ordonnance;
void menuprincipale();
int customerLogin();
void menuinscription();
void menuprincipale();
void displayMedicines1();
// Prototypes
void saveOrdonnanceToFile(const Ordonnance *ordonnance, const char *filename);
void fillOrdonnance(Ordonnance *ordonnance);
int verifyOrdonnance();
int isOrdonnanceValid(const char* prescription_date, const char* validity_period);
void createCustomerAccount();
void notification_menu();
typedef struct {
    int customerID;
    char firstName[20];  // Adjusted size based on typical name lengths
    char lastName[20];
    char telephone[11];  // 10 digits + null terminator
    char email[50];      // Increased size to accommodate emails
    int cust_age;
    char password_cust[16];  // Adjusted size for password
    char recovery_code[16];  // Adjusted size for recovery code
} Customer;

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

struct admin {
    int admin_id;             // Identifiant unique de l'admin
    char admin_name[25];       // Prénom de l'admin
    char lastName_ad[25];        // Nom de l'admin
    char phone_ad[11];           // Numéro de téléphone (10 chiffres)
    char email_ad[50];           // Adresse email
    char password[15];        // Mot de passe
    char recovery_code[15];   // Code de récupération
};
int verifyLoginAdmin() {
    FILE *file = fopen("admins.txt", "r");
    if (!file) {
        textcolor(4);
        printf("Error opening the administrator file.\n");
        textcolor(7);
        return 0;
    }

    struct admin adminTemp;
    char enteredName[25], enteredLastName[25], enteredPassword[15], enteredRecoveryCode[15];
    int attempts = 0, found = 0;

    while (attempts < 3) {
        system("cls");

        // Dessiner l'interface graphique
        textcolor(14);
        int i;
        for (i = 3; i < 30; i++) {
            gotoxy(25, i);
            printf("║");
            gotoxy(110, i);
            printf("║");
        }
        for (i = 25; i < 111; i++) {
            gotoxy(i, 3);
            printf("═");
            gotoxy(i, 30);
            printf("═");
        }
        gotoxy(25, 3);
        printf("╔");
        gotoxy(110, 3);
        printf("╗");
        gotoxy(25, 30);
        printf("╚");
        gotoxy(110, 30);
        printf("╝");

        // Titre
        textcolor(2);
        gotoxy(40, 5);
        printf("=============================================");
        textcolor(10);
        gotoxy(40, 6);
        printf("        WELCOME TO THE ADMIN LOGIN SYSTEM     ");
        textcolor(2);
        gotoxy(40, 7);
        printf("=============================================");

        // Champs de saisie
        textcolor(14);
        gotoxy(40, 10);
        printf("╔══════════════════════════════════════╗");
        gotoxy(40, 11);
        printf("║ First Name:                          ║");
        gotoxy(40, 12);
        printf("╚══════════════════════════════════════╝");

        gotoxy(40, 14);
        printf("╔══════════════════════════════════════╗");
        gotoxy(40, 15);
        printf("║ Last Name:                           ║");
        gotoxy(40, 16);
        printf("╚══════════════════════════════════════╝");

        gotoxy(40, 18);
        printf("╔══════════════════════════════════════╗");
        gotoxy(40, 19);
        printf("║ Password:                            ║");
        gotoxy(40, 20);
        printf("╚══════════════════════════════════════╝");

        // Entrer les informations
        textcolor(7);
        gotoxy(55, 11);
        scanf("%24s", enteredName);

        gotoxy(55, 15);
        scanf("%24s", enteredLastName);

        // Entrer le mot de passe (affichage masqué avec *)
        gotoxy(55, 19);
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

        // Vérification des informations
        rewind(file);
        while (fscanf(file, "%d %24s %24s %10s %49s %14s %14s",
                      &adminTemp.admin_id,
                      adminTemp.admin_name,
                      adminTemp.lastName_ad,
                      adminTemp.phone_ad,
                      adminTemp.email_ad,
                      adminTemp.password,
                      adminTemp.recovery_code) == 7) {

            if (strcmp(adminTemp.admin_name, enteredName) == 0 &&
                strcmp(adminTemp.lastName_ad, enteredLastName) == 0) {

                // Vérifier si le mot de passe est correct
                if (strcmp(adminTemp.password, enteredPassword) == 0) {
                    found = 1;
                    break;
                }
            }
        }

        if (found) {
            // Succès de la connexion
            textcolor(10);
            gotoxy(40, 25);
            printf("Login successful: Administrator authenticated!");
            textcolor(7);
            fclose(file);
            return 1;
        } else {
            // Échec de la tentative
            textcolor(4);
            gotoxy(40, 22);
            printf("Login failed: Invalid password. Please try again.");
            textcolor(7);
            attempts++;
            gotoxy(40, 24);
            printf("You have %d attempt(s) left.", 3 - attempts);
            getch();
        }
    }

    // Échec après 3 tentatives, demander le recovery code
    system("cls");
    textcolor(14);
    gotoxy(40, 10);
    printf("╔══════════════════════════════════════════════════════════════╗");
    gotoxy(40, 11);
    printf("║ You have exceeded the maximum attempts.                      ║");
    gotoxy(40, 12);
    printf("║ Please enter your recovery code to authenticate.             ║");
    gotoxy(40, 13);
    printf("╚══════════════════════════════════════════════════════════════╝");

    // Cadre pour le recovery code
    gotoxy(40, 16);
    printf("╔══════════════════════════════════════╗");
    gotoxy(40, 17);
    printf("║ Recovery Code:                       ║");
    gotoxy(40, 18);
    printf("╚══════════════════════════════════════╝");

    textcolor(7);
    gotoxy(57, 17);
    scanf("%14s", enteredRecoveryCode);

    // Vérifier le recovery code
    rewind(file);
    while (fscanf(file, "%d %24s %24s %10s %49s %14s %14s",
                  &adminTemp.admin_id,
                  adminTemp.admin_name,
                  adminTemp.lastName_ad,
                  adminTemp.phone_ad,
                  adminTemp.email_ad,
                  adminTemp.password,
                  adminTemp.recovery_code) == 7) {

        if (strcmp(adminTemp.admin_name, enteredName) == 0 &&
            strcmp(adminTemp.lastName_ad, enteredLastName) == 0 &&
            strcmp(adminTemp.recovery_code, enteredRecoveryCode) == 0) {

            // Authentification réussie avec le recovery code
            textcolor(10);
            gotoxy(40, 20);
            printf("Recovery successful: Administrator authenticated!");
            textcolor(7);
            fclose(file);
            return 1;
        }
    }

    // Échec d'authentification
    textcolor(4);
    gotoxy(40, 22);
    printf("Authentication failed: Recovery code invalid.");
    textcolor(7);
    fclose(file);
    return 0;
}
void menuEmploye() {
    int choice;
    Ordonnance ordonnance;
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
        gotoxy(40, 10);
        printf("1. View Medicine Information");
        gotoxy(40, 12);
        printf("2. Update_Order ");
        gotoxy(40, 14);
        printf("4. Update_Order");
        gotoxy(40, 16);
        printf("5. Exit");


       textcolor(5);
        gotoxy(30, 19);
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
               displayMedicines1();
                break;

            case 2:
               fillOrdonnance(&ordonnance);
               saveOrdonnanceToFile(&ordonnance, "ordonnance.txt");
                break;
            case 3:
        
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
    } while (choice != 3);
}

int verifyLoginEmployee() {
    FILE *file = fopen("employerr.txt", "r");
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

void displayBox(const char *title, const char *message) {
    int boxWidth = 60;  // Largeur du box ajustée à 60 caractères
    int titleLength = strlen(title);
    int messageLength = strlen(message);
    int titlePadding = (boxWidth - titleLength - 2) / 2; // Calcul de l'alignement du titre

    // Dessin du cadre
    gotoxy(30, 6);  // Positionnement du cadre
    printf("╔");
    for (int i = 0; i < boxWidth - 2; i++) {
        printf("═");
    }
    printf("╗");

    // Titre centré
    gotoxy(30, 7);
    printf("║");
    for (int i = 0; i < titlePadding; i++) {
        printf(" ");
    }
    printf("%s", title);
    for (int i = 0; i < (boxWidth - titleLength - titlePadding - 2); i++) {
        printf(" ");
    }
    printf("║");

    // Message centré
    gotoxy(30, 8);
    printf("║");
    printf("  %s", message); // Message avec un peu d'espace à gauche
    for (int i = 0; i < (boxWidth - messageLength - 2); i++) {
        printf(" ");
    }
    printf("║");

    // Ligne inférieure du cadre
    gotoxy(30, 9);
    printf("╚");
    for (int i = 0; i < boxWidth - 2; i++) {
        printf("═");
    }
    printf("╝");
}



// Fonction pour saisir les informations d'une ordonnance
void fillOrdonnance(Ordonnance *ordonnance) {
    printf("Enter doctor's name: ");
    fgets(ordonnance->doctor_name, sizeof(ordonnance->doctor_name), stdin);
    ordonnance->doctor_name[strcspn(ordonnance->doctor_name, "\n")] = '\0'; // Remove newline

    printf("Enter doctor's specialty: ");
    fgets(ordonnance->specialty, sizeof(ordonnance->specialty), stdin);
    ordonnance->specialty[strcspn(ordonnance->specialty, "\n")] = '\0'; // Remove newline

    printf("Enter cabinet address: ");
    fgets(ordonnance->cabinet_address, sizeof(ordonnance->cabinet_address), stdin);
    ordonnance->cabinet_address[strcspn(ordonnance->cabinet_address, "\n")] = '\0'; // Remove newline

    printf("Enter cabinet phone number: ");
    fgets(ordonnance->cabinet_phone, sizeof(ordonnance->cabinet_phone), stdin);
    ordonnance->cabinet_phone[strcspn(ordonnance->cabinet_phone, "\n")] = '\0'; // Remove newline

    printf("Enter doctor's signature: ");
    fgets(ordonnance->signature, sizeof(ordonnance->signature), stdin);
    ordonnance->signature[strcspn(ordonnance->signature, "\n")] = '\0'; // Remove newline

    printf("Enter RPPS number: ");
    fgets(ordonnance->rpps_number, sizeof(ordonnance->rpps_number), stdin);
    ordonnance->rpps_number[strcspn(ordonnance->rpps_number, "\n")] = '\0'; // Remove newline

    printf("Enter prescription date (DD/MM/YYYY): ");
    fgets(ordonnance->prescription_date, sizeof(ordonnance->prescription_date), stdin);
    ordonnance->prescription_date[strcspn(ordonnance->prescription_date, "\n")] = '\0'; // Remove newline

    printf("Enter validity period (in days): ");
    fgets(ordonnance->validity_period, sizeof(ordonnance->validity_period), stdin);
    ordonnance->validity_period[strcspn(ordonnance->validity_period, "\n")] = '\0'; // Remove newline

    printf("Enter barcode code: ");
    fgets(ordonnance->code_barre, sizeof(ordonnance->code_barre), stdin);
    ordonnance->code_barre[strcspn(ordonnance->code_barre, "\n")] = '\0'; // Remove newline
}

// Fonction pour enregistrer l'ordonnance dans un fichier
void saveOrdonnanceToFile(const Ordonnance *ordonnance, const char *filename) {
    FILE *file = fopen(filename, "a"); // Ouvrir en mode ajout
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    // Écrire les informations de l'ordonnance dans le fichier
    fprintf(file, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n", 
            ordonnance->doctor_name,
            ordonnance->specialty,
            ordonnance->cabinet_address,
            ordonnance->cabinet_phone,
            ordonnance->signature,
            ordonnance->rpps_number,
            ordonnance->prescription_date,
            ordonnance->validity_period,
            ordonnance->code_barre);

    fclose(file);
    printf("Prescription has been successfully saved.\n");
}


// Fonction pour vérifier une ordonnance par code-barre
int verifyOrdonnance() {
    char code_barre[30];
    system("cls");

    // Affichage de la boîte avec titre et message
    box();
    displayBox("VERIFY ORDONNANCE", "Enter the Code Barre");

    // Saisie du code-barre
    gotoxy(35, 10);  // Positionner à l'endroit approprié
    printf("Code Barre: ");
    scanf("%s", code_barre);
    
    // Lecture du fichier des ordonnances
    FILE *file = fopen("ordonnances.txt", "r");
    if (file == NULL) {
        displayBox("ERROR", "Unable to open 'ordonnances.txt'.");
        return 0;
    }

    Ordonnance ord;
    int found = 0;

    // Parcourir le fichier pour trouver le code-barre
    while (fscanf(file, 
                  "%49[^\n]\n%29[^\n]\n%99[^\n]\n%19[^\n]\n%49[^\n]\n%19[^\n]\n%14[^\n]\n%14[^\n]\n%29[^\n]\n",
                  ord.doctor_name, ord.specialty, ord.cabinet_address, ord.cabinet_phone,
                  ord.signature, ord.rpps_number, ord.prescription_date, ord.validity_period, ord.code_barre) == 9) {

        // Nettoyer les sauts de ligne résiduels
        ord.code_barre[strcspn(ord.code_barre, "\n")] = '\0';

        // Comparaison du code-barre
        if (strcmp(code_barre, ord.code_barre) == 0) {
            found = 1;

            // Affichage des détails de l'ordonnance
            box();
            if (isOrdonnanceValid(ord.prescription_date, ord.validity_period)) {
                textcolor(1);
                displayBox("ORDONNANCE VALID", "The ordonnance is VALID.");
                gotoxy(35, 12);
                printf("Doctor Name: %s\nSpecialty: %s\nAddress: %s\nPhone: %s\n",
                       ord.doctor_name, ord.specialty, ord.cabinet_address, ord.cabinet_phone);
                gotoxy(35, 16);
                printf("Prescription Date: %s\nValidity Period: %s\nCode Barre: %s\n",
                       ord.prescription_date, ord.validity_period, ord.code_barre);
            } else {
                textcolor(4);
                displayBox("ORDONNANCE EXPIRED", "The ordonnance is EXPIRED.\n");
                printf("\n\n\n\n\n\n\n\n");
            }
            system("pause");
            fclose(file);
            return 1;
        }
    }

    // Si l'ordonnance n'est pas trouvée
    if (!found) {
        system("cls");
        box();
        gotoxy(30,10);
        displayBox("NOT FOUND", "Ordonnance not found.");
        system("pause");
    }

    fclose(file);
    return 0;
}
// Fonction pour vérifier la validité de l'ordonnance
int isOrdonnanceValid(const char* prescription_date, const char* validity_period) {
    time_t current_time;
    time(&current_time);

    struct tm prescription_tm = {0};
    if (sscanf(prescription_date, "%d/%d/%d",
               &prescription_tm.tm_mday,
               &prescription_tm.tm_mon,
               &prescription_tm.tm_year) != 3) {
        return 0;
    }

    prescription_tm.tm_year -= 1900;
    prescription_tm.tm_mon -= 1;

    time_t prescription_time = mktime(&prescription_tm);
    if (prescription_time == -1) {
        return 0;
    }

    int validity_days = atoi(validity_period);
    time_t expiry_time = prescription_time + (validity_days * 24 * 60 * 60);
    system("pause");
    return difftime(expiry_time, current_time) >= 0;
}
//lmohim haya l fonction li katverifie l'ordonnance rah 0aditha   w rah hta structure modifitha
// Function to verify ordonnance information entered by a client
void displayMedicines1() {
    FILE *file = fopen("medicines.txt", "r");
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
    medical med;

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
void createCustomerAccount() { 
    system("cls");
    textcolor(14);

    // Draw UI
    for (int i = 3; i < 40; i++) {
        gotoxy(25, i); printf("║");
        gotoxy(110, i); printf("║");
    }
    for (int i = 25; i < 111; i++) {
        gotoxy(i, 3); printf("═");
        gotoxy(i, 39); printf("═");
    }
    gotoxy(25, 3); printf("╔");
    gotoxy(110, 3); printf("╗");
    gotoxy(25, 39); printf("╚");
    gotoxy(110, 39); printf("╝");

    textcolor(2);
    gotoxy(40, 5); printf("=============================================");
    textcolor(10);
    gotoxy(40, 6); printf("        WELCOME TO OUR PHARMACY SYSTEM       ");
    textcolor(2);
    gotoxy(40, 7); printf("=============================================");

    // Instructions
    textcolor(13);
    gotoxy(35, 9); printf("Please create a customer account.");

    // Input fields
    Customer newCustomer;
    textcolor(14);
    gotoxy(40, 12); printf("First Name: ");
    gotoxy(40, 14); printf("Last Name : ");
    gotoxy(40, 16); printf("Phone     : ");
    gotoxy(40, 18); printf("Email     : ");
    gotoxy(40, 20); printf("Age       : ");
    gotoxy(40, 22); printf("Password  : ");
    gotoxy(40, 24); printf("RCODE     : ");
    textcolor(7);

    // Input customer data
    gotoxy(53, 12);
    fgets(newCustomer.firstName, sizeof(newCustomer.firstName), stdin);
    newCustomer.firstName[strcspn(newCustomer.firstName, "\n")] = 0;

    gotoxy(53, 14);
    fgets(newCustomer.lastName, sizeof(newCustomer.lastName), stdin);
    newCustomer.lastName[strcspn(newCustomer.lastName, "\n")] = 0;

    do {
        gotoxy(53, 16);
        printf("            ");
        gotoxy(53, 16);
        fgets(newCustomer.telephone, sizeof(newCustomer.telephone), stdin);
        newCustomer.telephone[strcspn(newCustomer.telephone, "\n")] = 0;
        if (strlen(newCustomer.telephone) != 10 || strspn(newCustomer.telephone, "0123456789") != 10) {
            textcolor(12);
            gotoxy(40, 17); printf("Error: Invalid phone number! Must be 10 digits.");
            textcolor(7);
        } else {
            break;
        }
    } while (1);

    do {
        gotoxy(53, 18);
        printf("                        ");
        gotoxy(53, 18);
        fgets(newCustomer.email, sizeof(newCustomer.email), stdin);
        newCustomer.email[strcspn(newCustomer.email, "\n")] = 0;
        char *at = strchr(newCustomer.email, '@');
        char *dot = strrchr(newCustomer.email, '.');
        if (!at || !dot || at > dot || at == newCustomer.email || dot - at < 2 || dot[1] == '\0') {
            textcolor(12);
            gotoxy(40, 19); printf("Error: Invalid email format! Use example@domain.com.");
            textcolor(7);
        } else {
            break;
        }
    } while (1);

    do {
        gotoxy(53, 20);
        printf("            ");
        gotoxy(53, 20);
        char ageInput[5];
        fgets(ageInput, sizeof(ageInput), stdin);
        ageInput[strcspn(ageInput, "\n")] = 0;
        newCustomer.cust_age = atoi(ageInput);
        if (newCustomer.cust_age < 1 || newCustomer.cust_age > 120) {
            textcolor(12);
            gotoxy(40, 21); printf("Error: Invalid age! Must be between 1 and 120.");
            textcolor(7);
        } else {
            break;
        }
    } while (1);

    gotoxy(53, 22);
    fgets(newCustomer.password_cust, sizeof(newCustomer.password_cust), stdin);
    newCustomer.password_cust[strcspn(newCustomer.password_cust, "\n")] = 0;

    gotoxy(53, 24);
    fgets(newCustomer.recovery_code, sizeof(newCustomer.recovery_code), stdin);
    newCustomer.recovery_code[strcspn(newCustomer.recovery_code, "\n")] = 0;

    // Generate unique customer ID
    int customerID = 0;
    FILE *idFile = fopen("id_counter.txt", "r");
    if (idFile == NULL) {
        idFile = fopen("id_counter.txt", "w");
        if (idFile == NULL) {
            perror("Error creating id_counter.txt");
            return;
        }
        fprintf(idFile, "%d", 0); // Initialize to 0
        fclose(idFile);
        idFile = fopen("id_counter.txt", "r");
    }
    if (idFile != NULL) {
        fscanf(idFile, "%d", &customerID);
        fclose(idFile);
    }
    customerID++;

    idFile = fopen("id_counter.txt", "w");
    if (idFile != NULL) {
        fprintf(idFile, "%d", customerID);
        fclose(idFile);
    }

    char customerIDStr[10];
    sprintf(customerIDStr, "%03d", customerID);

    // Save customer data in binary file
    char filename[100];
//"C:\\hnaya diro path dyal folder\\login%s.bin"
    sprintf(filename, "%s_commandes.txt", customerIDStr);

    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error opening binary file");
        return;
    }
    if (fwrite(&newCustomer, sizeof(Customer), 1, file) != 1) {
        perror("Error writing to binary file");
        fclose(file);
        return;
    }
    fclose(file);

    // Append to centralized text file
    FILE *textFile = fopen("customers.txt", "a");
    if (textFile == NULL) {
        perror("Error opening customers.txt");
        return;
    }
    fprintf(textFile, "%s %s %s %s %s %d %s %s\n",
            customerIDStr,
            newCustomer.firstName,
            newCustomer.lastName,
            newCustomer.telephone,
            newCustomer.email,
            newCustomer.cust_age,
            newCustomer.password_cust,
            newCustomer.recovery_code);
    fclose(textFile);

    // Confirmation message
    textcolor(10);
    gotoxy(40, 26); printf("╔════════════════════════════════════════════╗");
    gotoxy(40, 27); printf("║ Customer account created successfully!     ║");
    gotoxy(40, 28); printf("║ Your Customer ID is: %s                   ║", customerIDStr);
    gotoxy(40, 29); printf("╚════════════════════════════════════════════╝");

    textcolor(7);
    gotoxy(40, 31);
    printf("Press [1] for Client Menu, or [2] for Registration Menu.");

    char choice;
    do {
        choice = getch();
        if (choice == '1') menu_client();
        else if (choice == '2') exit(0);
    } while (1);
}
void menuinscription() {
    int choice;

    while (1) {
        system("cls");
        textcolor(14);

        // Dessiner la bordure principale
        int i;
        for (i = 3; i < 20; i++) {
            gotoxy(25, i); printf("║");
            gotoxy(110, i); printf("║");
        }
        for (i = 25; i < 111; i++) {
            gotoxy(i, 3); printf("═");
            gotoxy(i, 19); printf("═");
        }
        gotoxy(25, 3); printf("╔");
        gotoxy(110, 3); printf("╗");
        gotoxy(25, 19); printf("╚");
        gotoxy(110, 19); printf("╝");

        // Titre
        textcolor(2);
        gotoxy(40, 5);
        printf("=============================================");
        textcolor(10);
        gotoxy(40, 6);
        printf("            WELCOME TO OUR SYSTEM            ");
        textcolor(2);
        gotoxy(40, 7);
        printf("=============================================");

        // Options du menu
        textcolor(14);
        gotoxy(40, 9);
        printf("1. Create an Account");
        gotoxy(40, 10);
        printf("2. Login");
        gotoxy(40, 11);
        printf("3. Exit");

        textcolor(7);
        gotoxy(40, 13);
        textcolor(5);
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consommer le retour à la ligne

        switch (choice) {
            case 1:
                createCustomerAccount();
                break;

            case 2:
                if (customerLogin() == 1) {
                    menu_client();
                } else {
                    gotoxy(40, 15);
                    textcolor(12);
                    printf("Returning to main menu...");
                    textcolor(7);
                    sleep(2);
                }
                break;

            case 3:
                system("cls");
                textcolor(10);
                gotoxy(40, 10);
                printf("Thank you for using our system. Goodbye!");
                textcolor(7);
                exit(0);

            default:
                textcolor(12);
                gotoxy(40, 15);
                printf("Invalid choice! Please try again.");
                textcolor(7);
                sleep(2);
        }
    }
    system("pause");
}

int customerLogin() {
    char enteredEmail[50], enteredPassword[30], enteredRecoveryCode[15];
    int attempts = 0, found = 0;
    box();
    // Login attempts loop
    while (attempts < 3) {
        system("cls");

        // Input: Email
        textcolor(14);
        gotoxy(30,8);
        printf("╔══════════════════════════════════════════╗\n");
        gotoxy(30,9);
        printf("║               CUSTOMER LOGIN             ║\n");
        gotoxy(30,10);
        printf("╚══════════════════════════════════════════╝\n\n");
        gotoxy(30,12);
        textcolor(7);
        printf("Enter your email: ");
        fgets(enteredEmail, sizeof(enteredEmail), stdin);
        enteredEmail[strcspn(enteredEmail, "\n")] = 0; // Remove newline
       gotoxy(30,13);
        // Input: Password (Masked)
        printf("Enter your password: ");
        int index = 0;
        char ch;
        while ((ch = getch()) != '\r') {
            if (ch == '\b') { // Handle backspace
                if (index > 0) {
                    index--;
                    printf("\b \b");
                }
            } else if (index < sizeof(enteredPassword) - 1) {
                enteredPassword[index++] = ch;
                printf("*");
            }
        }
        enteredPassword[index] = '\0';
        printf("\n");

        // Search directory for matching email
        char directory[] = "C:\\Users\\hp\\Desktop\\programme\\testdisplaymedecine\\db_login\\*";
        WIN32_FIND_DATA findFileData;
        HANDLE hFind = FindFirstFile(directory, &findFileData);

        if (hFind == INVALID_HANDLE_VALUE) {
            printf("\nError: Unable to access directory.\n");
            return 0;
        }

        // Iterate over files in the directory
        do {
            if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                // Build the full file path
                char filePath[200];
                sprintf(filePath, "C:\\Users\\hp\\Desktop\\programme\\testdisplaymedecine\\db_login\\%s", findFileData.cFileName);

                // Open the file
                FILE *file = fopen(filePath, "rb");
                if (file != NULL) {
                    Customer customerTemp;
                    if (fread(&customerTemp, sizeof(Customer), 1, file) == 1) {
                        // Check if the email matches
                        if (strcmp(customerTemp.email, enteredEmail) == 0) {
                            found = 1;

                            // Validate password
                            if (strcmp(customerTemp.password_cust, enteredPassword) == 0) {
                                printf("\nLogin successful! Welcome, %s %s.\n", customerTemp.firstName, customerTemp.lastName);
                                fclose(file);
                                FindClose(hFind);
                                return 1; // Login successful
                            } else {
                                printf("\nInvalid password. Try again.\n");
                                fclose(file);
                                attempts++;
                                break; // Retry login
                            }
                        }
                    }
                    fclose(file);
                }
            }
        } while (FindNextFile(hFind, &findFileData) != 0);

        FindClose(hFind);

        if (!found) {
            printf("\nNo account found with the entered email.\n");
            attempts++;
        }

        if (attempts < 3) {
            printf("\nYou have %d attempt(s) left.\n", 3 - attempts);
            system("pause");
        }
    }

    // After 3 failed attempts, ask for the recovery code
    if (!found) {
        printf("\nLogin failed after 3 attempts. Please enter your recovery code to authenticate.\n");

        // Input: Recovery Code
        printf("Enter your recovery code: ");
        fgets(enteredRecoveryCode, sizeof(enteredRecoveryCode), stdin);
        enteredRecoveryCode[strcspn(enteredRecoveryCode, "\n")] = 0;

        // Search directory for matching email and recovery code
        char directory[] = "C:\\Users\\hp\\Desktop\\programme\\testdisplaymedecine\\db_login\\*";
        WIN32_FIND_DATA findFileData;
        HANDLE hFind = FindFirstFile(directory, &findFileData);

        if (hFind == INVALID_HANDLE_VALUE) {
            printf("\nError: Unable to access directory.\n");
            return 0;
        }

        // Iterate over files again to find recovery code
        do {
            if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                // Build the full file path
                char filePath[200];
                sprintf(filePath, "C:\\Users\\hp\\Desktop\\programme\\testdisplaymedecine\\db_login\\%s", findFileData.cFileName);

                // Open the file
                FILE *file = fopen(filePath, "rb");
                if (file != NULL) {
                    Customer customerTemp;
                    if (fread(&customerTemp, sizeof(Customer), 1, file) == 1) {
                        // Check if the email and recovery code match
                        if (strcmp(customerTemp.email, enteredEmail) == 0 &&
                            strcmp(customerTemp.recovery_code, enteredRecoveryCode) == 0) {
                            printf("\nRecovery successful! Welcome, %s %s.\n", customerTemp.firstName, customerTemp.lastName);
                            fclose(file);
                            FindClose(hFind);
                            return 1; // Recovery successful
                        }
                    }
                    fclose(file);
                }
            }
        } while (FindNextFile(hFind, &findFileData) != 0);

        FindClose(hFind);

        // If no match is found
        printf("\nAuthentication failed. Invalid recovery code or email.\n");
    }

    return 0; // Login failed
}
void createAdmin() {
    system("cls");
    textcolor(14);
    int i;

    // Dessiner le cadre
    for (i = 3; i < 40; i++) {
        gotoxy(25, i); printf("║");
        gotoxy(110, i); printf("║");
    }
    for (i = 25; i < 111; i++) {
        gotoxy(i, 3); printf("═");
        gotoxy(i, 39); printf("═");
    }
    gotoxy(25, 3); printf("╔");
    gotoxy(110, 3); printf("╗");
    gotoxy(25, 39); printf("╚");
    gotoxy(110, 39); printf("╝");

    // Titre
    textcolor(2);
    gotoxy(40, 5); printf("=============================================");
    textcolor(10);
    gotoxy(40, 6); printf("           ADMIN ACCOUNT CREATION            ");
    textcolor(2);
    gotoxy(40, 7); printf("=============================================");

    // Instructions
    textcolor(13);
    gotoxy(35, 9); printf("Please fill the following details to create an admin account.");

    // Champs de saisie
    textcolor(14);
    gotoxy(40, 12); printf("First Name   : ");
    gotoxy(40, 14); printf("Last Name    : ");
    gotoxy(40, 16); printf("Phone        : ");
    gotoxy(40, 18); printf("Email        : ");
    gotoxy(40, 20); printf("Password     : ");
    gotoxy(40, 22); printf("Recovery Code: ");

    // Saisie des données
    struct admin newAdmin;
    textcolor(7);

    // Saisie du prénom
    gotoxy(55, 12);
    fgets(newAdmin.admin_name, 25, stdin);
    newAdmin.admin_name[strcspn(newAdmin.admin_name, "\n")] = 0;

    // Saisie du nom
    gotoxy(55, 14);
    fgets(newAdmin.lastName_ad, 25, stdin);
    newAdmin.lastName_ad[strcspn(newAdmin.lastName_ad, "\n")] = 0;

    fflush(stdin);

    // Validation du numéro de téléphone
    do {
        gotoxy(55, 16); printf("            "); // Effacer l'ancien input
        gotoxy(55, 16);
        fgets(newAdmin.phone_ad, 11, stdin);
        newAdmin.phone_ad[strcspn(newAdmin.phone_ad, "\n")] = 0;

        if (strlen(newAdmin.phone_ad) != 10 || strspn(newAdmin.phone_ad, "0123456789") != 10) {
            textcolor(12);
            gotoxy(40, 17); printf("Error: Invalid phone number! Must be 10 digits.");
            textcolor(7);
        } else {
            gotoxy(40, 17); printf("                                           "); // Effacer le message d'erreur
            break;
        }
        fflush(stdin);
    } while (1);

    // Validation de l'adresse e-mail
    // Validation de l'adresse e-mail
do {
    gotoxy(55, 18);
    printf("                        "); // Effacer l'ancien input
    gotoxy(55, 18);

    fflush(stdin); // Nettoyer le buffer avant la saisie
    fgets(newAdmin.email_ad, 50, stdin);
    newAdmin.email_ad[strcspn(newAdmin.email_ad, "\n")] = 0;

    char *at = strchr(newAdmin.email_ad, '@');
    char *dot = strrchr(newAdmin.email_ad, '.');

    if (!at || !dot || at > dot || at == newAdmin.email_ad || dot - at < 2 || dot[1] == '\0') {
        textcolor(12);
        gotoxy(40, 19);
        printf("Error: Invalid email format! Use example@domain.com.");
        textcolor(7);
    } else {
        gotoxy(40, 19);
        printf("                                               "); // Effacer le message d'erreur
        break;
    }
} while (1);


    // Saisie du mot de passe
    gotoxy(55, 20);
    fgets(newAdmin.password, 15, stdin);
    newAdmin.password[strcspn(newAdmin.password, "\n")] = 0;

    fflush(stdin);

    // Saisie du code de récupération
    gotoxy(55, 22);
    fgets(newAdmin.recovery_code, 15, stdin);
    newAdmin.recovery_code[strcspn(newAdmin.recovery_code, "\n")] = 0;

    fflush(stdin);

    // Affectation de l'ID admin par défaut
    newAdmin.admin_id = 1;

    // Enregistrement dans le fichier
    FILE *file = fopen("admins.txt", "w");
    if (file != NULL) {
        fprintf(file, "%d %s %s %s %s %s %s\n",
                newAdmin.admin_id,
                newAdmin.admin_name,
                newAdmin.lastName_ad,
                newAdmin.phone_ad,
                newAdmin.email_ad,
                newAdmin.password,
                newAdmin.recovery_code);
        fclose(file);
    }

    // Confirmation d'inscription
    textcolor(10);
    gotoxy(40, 26); printf("╔════════════════════════════════════════════╗");
    gotoxy(40, 27); printf("║ Admin account created successfully!        ║");
    gotoxy(40, 28); printf("║ Your Admin ID is: 1                        ║");
    gotoxy(40, 29); printf("╚════════════════════════════════════════════╝");

    // Navigation
    textcolor(7);
    gotoxy(40, 31);
    printf("Press [1] for Main Menu, or [2] to Exit.");

    char choice;
    do {
        choice = getch();
        if (choice == '1') {
           main_menu(); // Appelez la fonction appropriée ici
            break;
        } else if (choice == '2') {
            exit(0);
        }
    } while (1);
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
    gotoxy(35, 4);
    printf("-----------------------------------------------");
    textcolor(2);
    gotoxy(35, 5);
    printf("      WELCOME TO OUR PHARMACY SYSTEM         ");
    gotoxy(35, 6);
    textcolor(2);
    printf("-----------------------------------------------");


    textcolor(14);
    gotoxy(40, 10); printf("1. ADMIN   ");
    gotoxy(40, 13); printf("2. EMPLOYEE");
    gotoxy(40, 16); printf("3. CUSTOMER");
    gotoxy(40, 19); printf("4. EXIT    ");
    textcolor(7);
    gotoxy(28, 22);
    printf("\n\t\t\t\tPress a number  .........?");
    textcolor(7);
}
void menuprincipale() {
    int choix ;
    FILE *file = fopen("admins1.txt", "r");
    // Si le fichier administrateur n'existe pas, on crée un administrateur
    if (file == NULL) {
        createAdmin();
    }
    fclose(file);
    // Affichage du menu principal
    menuP();
    gotoxy(28, 22);
    printf("\n\t\t\t\tPress a number  .........?");
    textcolor(7);
         choix = getch();  

    while (choix != 4) {
        switch (choix) {
            case '1':
              //system("cls");
                if(verifyLoginAdmin() == 1){
                    main_menu();
                     system("pause");
                } else {
                    system("cls");
                    menuprincipale();
                    textcolor(12);
                    gotoxy(43, 27);
                    printf("Login échoué. Retour au menu principal.");
                    textcolor(7);
                }
                break;

            case '2':
                if (verifyLoginEmployee() == 1) {
                    system("cls");
                    menuEmploye();
                     system("pause");
                } else {
                    system("cls");
                    menuP();
                    textcolor(12);
                    gotoxy(43, 27);
                    printf("Login échoué. Retour au menu principal.");
                    textcolor(7);
                }
                break;

            case '3':
               menuinscription();
               system("pause");
                break;

            case '4':
                system("cls");
                textcolor(10);
                gotoxy(53, 10);
                printf("╔════════════════════════════════╗\n");
                gotoxy(53, 11);
                printf("║           THANK YOU!           ║\n");
                gotoxy(53, 12);
                printf("║      FOR STOPPING BY :)        ║\n");
                gotoxy(53, 13);
                printf("╚════════════════════════════════╝\n");
                textcolor(7);
                break;

            default:
                menuprincipale();
                textcolor(12);
                gotoxy(43, 27);
                printf("Invalid option. Please choose a valid option.");
                textcolor(7);
        }
    }
}

#endif

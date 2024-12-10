#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
#include<stdlib.h>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<unistd.h>
#include<ctype.h>
// Function to set cursor position
void gotoxy1(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void textcolor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Function to set text color
void setTextColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Box for display
void box() {

    gotoxy1(2, 2);
    printf("%c", 201);
    gotoxy1(78, 2);
    printf("%c", 187);
    gotoxy1(2, 24);
    printf("%c", 200);
    gotoxy1(78, 24);
    printf("%c", 188);
    for (int i = 3; i < 78; i++) {
        gotoxy1(i, 2);
        printf("%c", 205);
        gotoxy1(i, 24);
        printf("%c", 205);
    }
    for (int i = 3; i < 24; i++) {
        gotoxy1(2, i);
        printf("%c", 186);
        gotoxy1(78, i);
        printf("%c", 186);
    }
}
// Box for display
void box2() {
    gotoxy1(2, 2);
    printf("%c", 201);
    gotoxy1(78, 2);
    printf("%c", 187);
    gotoxy1(2, 24);
    printf("%c", 200);
    gotoxy1(78, 24);
    printf("%c", 188);
    for (int i = 3; i < 78; i++) {
        gotoxy1(i, 2);
        printf("%c", 205);
        gotoxy1(i, 24);
        printf("%c", 205);
    }
    for (int i = 3; i < 24; i++) {
        gotoxy1(2, i);
        printf("%c", 186);
        gotoxy1(78, i);
        printf("%c", 186);
    }
}

void welcome()
{
 system("cls");

	  box();

        gotoxy(35,20);
		printf("WELCOME");

		gotoxy(38,22);
		printf("TO");

		gotoxy(28,24);
		printf("MEDICAL");
		gotoxy(36,24);
		printf("STORE");

		gotoxy(42,24);
		printf("SYSTEM");
		gotoxy(52,45);

		printf("Loading......");
		Sleep(40);


}

#endif
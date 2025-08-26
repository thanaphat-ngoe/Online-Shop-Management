#include <stdio.h>
#include <stdlib.h>
#include "login.c"
#include "mainmenuselection.c"
#include "inventorysystem.c"
#include "accountingsystem.c"
#include "possystem.c"

int mainmenuselection();
int inventorysystem();
int accountingsystem();
int possystem();
int login();

int main() {
    printf("|-----------------------------------------------|\n");
    printf("|CPE100 Module 3 : Online Shop Management System|\n");
    printf("|-----------------------------------------------|\n");
    printf("|                 Group Members                 |\n");
    printf("|-----------------------------------------------|\n");
    printf("|         65070503449 Thanaphat Ngoennet        |\n");
    printf("|         65070503450 Thanakorn Soonjaw         |\n");
    printf("|         65070503456 Parunchai Kochseni        |\n");
    printf("|         65070503459 Phakalpol Maneesopa       |\n");
    printf("|         65070503475 Kanchai Lerdsrisakulrat   |\n");
    printf("|-----------------------------------------------|\n");
    printf("|          Press 1 to enter the program         |\n");
    printf("|          Press 0 to exit the program          |\n");
    printf("|-----------------------------------------------|\n");
    printf("\nChoice --> ");
    int main_menu;
    scanf("%d", &main_menu);
    switch(main_menu) {
        case 1:
            system("cls");
            login();
            break;
        case 0:
            exit(1);
            break;
        default:
            system("cls");
            printf("     Your choice was wrong please try again!!\n\n\n");
            main();
            break;
    }
    getch();
    return 0;
}

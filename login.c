#include <string.h>

int mainmenuselection();
int inventorysystem();
int accountingsystem();
int possystem();
int login();
void admin_log();
int clientmainmenuselection();

void previouslogin() {
    int choice;
    printf("Press 1 to try again / Press 2 to back to login menu: ");
    scanf("%d", &choice);
    switch(choice) {
    case 1:
        system("cls");
        admin_log();
        break;
    case 2:
        system("cls");
        login();
        break;
    default:
        system("cls");
        printf("Your choice was wrong please try again!!\n");
        previouslogin();
        break;
    }
}

void admin_log() {
    char adminusername[100] = "admin";
    char adminpassword[100] = "cpe";
    char inputuser[100];
    char inputpassword[100];
    printf("|-----------------------------------------------|\n");
    printf("|              Login as administrator           |\n");
    printf("|-----------------------------------------------|\n");
    printf("\nEnter username: ");
    scanf("%s", &inputuser);
    printf("\nEnter password: ");
    scanf("%s", &inputpassword);
    if((strcmp(adminusername, inputuser)) == 0 && (strcmp(adminpassword, inputpassword)) == 0) {
        system("cls");
        mainmenuselection();
    }else {
        printf("\nInvalid username or password\n");
        previouslogin();
    }
}

int login() {
    printf("|-----------------------------------------------|\n");
    printf("|                     LOGIN                     |\n");
    printf("|-----------------------------------------------|\n");
    printf("|         Press 1 to login as client            |\n");
    printf("|         Press 2 to login as administrator     |\n");
    printf("|         Press 0 to exit the program           |\n");
    printf("|-----------------------------------------------|\n");
    printf("\nChoice --> ");
    int choice;
    scanf("%d", &choice);
    switch(choice) {
        case 1: 
            system("cls");
            clientmainmenuselection();
            break;
        case 2:
            system("cls");
            admin_log();
            break;
        case 0:
            exit(1);
            break;
        default:
            system("cls");
            printf("     Your choice was wrong please try again!!\n\n");
            login();
            break;
    }
}
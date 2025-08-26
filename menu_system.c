int inventorysystem();
int accountingsystem();
int possystem();
void previousweeklyadmin();
void previousdailyadmin();
void daily();
void weekly();
int login();
void admin_log();
void adminweekly();
void admindaily();

int mainmenuselection() {
    printf("|-----------------------------------------------|\n");
    printf("|                   MAIN MENU                   |\n");
    printf("|-----------------------------------------------|\n");
    printf("|       Press 1 to enter inventory system       |\n");
    printf("|       Press 2 to enter accounting system      |\n");
    printf("|       Press 3 to enter daily summary          |\n");
    printf("|       Press 4 to enter weekly summary         |\n");
    printf("|       Press 5 to back to Login menu           |\n");
    printf("|       Press 0 to exit the program             |\n");
    printf("|-----------------------------------------------|\n");
    printf("\nChoice --> ");
    int button;
    scanf("%d", &button);
    switch(button) {
        case 1: 
            system("cls");
            inventorysystem();
            break;
        case 2:
            system("cls");
            accountingsystem();
            break;
        case 3:
            system("cls");
            admindaily();
            previousdailyadmin();
            break;
        case 4:
            system("cls");
            adminweekly();
            previousweeklyadmin();
            break;
        case 5:
            system("cls");
            login();
            break;
        case 0:
            exit(1);
            break;
        default:
            system("cls");
            printf("     Your choice was wrong please try again!!\n\n\n");
            mainmenuselection();
            break;
    }
}

int clientmainmenuselection() {
    printf("|-----------------------------------------------|\n");
    printf("|                   MAIN MENU                   |\n");
    printf("|-----------------------------------------------|\n");
    printf("|       Press 1 to enter POS system             |\n");
    printf("|       Press 2 to enter login menu             |\n");
    printf("|       Press 0 to exit the program             |\n");
    printf("|-----------------------------------------------|\n");
    printf("\nChoice --> ");
    int button;
    scanf("%d", &button);
    switch(button) {
        case 1:
            system("cls");
            possystem();
            break;
        case 2:
            system("cls");
            login();
            break;
        case 0:
            system("cls");
            exit(1);
            break;
        default:
            system("cls");
            printf("     Your choice was wrong please try again!!\n\n\n");
            clientmainmenuselection();
            break;
    }
}
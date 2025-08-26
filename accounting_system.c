#include <stdio.h>
#include <string.h>
#include <stdlib.h>	
#include <time.h>
#define true 0 
#define false 1 

int accountingsystem();
int possystem();
int mainmenuselection();
int IDChecker(int i, int j);
int checkID(int id);
int inventorysystem();
int readposFile();
int writeposFile();

void previousacc() {
    int choice;
        printf("Press 1 to back to accounting menu / Press 0 to exit the program : ");
        scanf("%d", &choice);
        switch(choice) {
        case 1:
            system("cls");
            accountingsystem(); 
            break;
        case 0:
            system("cls");
		 	exit(1);
			break;
        default:
            printf("Your choice was wrong please try again!!\n\n");
            previousacc();
            break;
        }
}

int purchasedlists() {
    int i, j;
    float total = 0;
    float profit = 0;
    float princsum = 0;
    count = readFile();
    countpos = readposFile();
    if(countpos < 0) {
        puts("cannot open file");
    }
        printf("|----------------------------------------------------------------------------------------------------------------|\n");
	    printf("|                                               Bought List                                                      |\n");
        printf("|----------------------------------------------------------------------------------------------------------------|\n");
        printf("|      NAME      |    PROD ID    |    QUANTITY    |    PRICE    |    PRINCIPLE    |            TIME              |\n");
        printf("|----------------------------------------------------------------------------------------------------------------|\n");
        for(i = 0; i < countpos; i++) { 
            total = total + (buy[i].price * buy[i].quantity);
            princsum = princsum + (buy[i].principle * buy[i].quantity);
        printf("|    %-8s             %-10d     %-6d       %-10.2f       %-6.2f          %-13s  |\n", buy[i].name, buy[i].id, buy[i].quantity, buy[i].price * buy[i].quantity, buy[i].principle* buy[i].quantity, buy[i].timestp);
	    }
        profit = total - princsum;
        printf("|----------------------------------------------------------------------------------------------------------------|\n");
        printf("|                  TOTAL : %-6.2f                   |                     PROFIT : %-6.2f                        |\n", total, profit);
        printf("|----------------------------------------------------------------------------------------------------------------|\n\n\n");
        writeFile();
        previousacc();
}

int accountingsystem() {
    printf("|------------------------------------------------|\n");
    printf("|                   Accounting                   |\n");
    printf("|------------------------------------------------|\n");
    printf("|         Press 1 to display purchased lists     |\n");
    printf("|         Press 2 to back to main menu           |\n");
    printf("|         Press 0 to exit the program            |\n");
    printf("|------------------------------------------------|\n");
    printf("\nChoice --> ");
    int button;
    scanf("%d", &button);
    switch(button) {
        case 1:
            system("cls");
            purchasedlists(); 
            break;
        case 2:
            system("cls");
            mainmenuselection();
            break;
        case 0:
            system("cls");
		 	exit(1);
			break;
        default:
            system("cls");
            printf("Your choice was wrong please try again!!\n");
            accountingsystem();
            break;
    }
}

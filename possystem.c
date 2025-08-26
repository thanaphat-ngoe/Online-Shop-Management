#include <stdio.h>
#include <string.h>
#include <stdlib.h>	
#include <time.h>
#define true 0 
#define false 1

int accountingsystem();
int mainmenuselection();
int inventorysystem();
int IDChecker(int i, int j);
int checkID(int id);
int readFile();
int writeFile();
void purchaseproduct();
void viewproduct();
void daily();
void weekly();
void adminweekly();
void admindaily();

FILE *p;

int writeposFile() {
    int i;
    p = fopen("pos.txt", "w");  
    if(p == NULL) {
        return -1;
    }			
    fprintf(p, "%d\n", countpos);
    for(i = 0; i < countpos; ++i) {
        fprintf(p, "%d\n", buy[i].id);
        fputs(buy[i].name, p);
        fprintf(p, "\n");
        fprintf(p, "%d\n", buy[i].quantity);
        fprintf(p, "%f\n", buy[i].price);
        fprintf(p, "%f\n", buy[i].principle);
        fputs(buy[i].timestp, p);
        fprintf(p, "\n");
        fprintf(p, "%d\n", buy[i].time);
    }
    fclose(p);
    return 0;
}

int readposFile() {
    int n = 0;
    int i;
    p = fopen("pos.txt", "r");
    if(p == NULL) {
        return -1;
    }
    fscanf(p, "%d\n", &n);
    for(i = 0; i < n; ++i) {
        fscanf(p, "%d\n", &buy[i].id);
        fgets(buy[i].name, 20,p);
        buy[i].name[strlen(buy[i].name) - 1] = 0; 
        fscanf(p, "%d\n", &buy[i].quantity);
        fscanf(p, "%f\n", &buy[i].price);
        fscanf(p, "%f\n", &buy[i].principle);
        fgets(buy[i].timestp, 30,p);
        buy[i].timestp[strlen(buy[i].timestp) - 1] = 0;
        fscanf(p, "%d\n", &buy[i].time);
    }
    fclose(p);
    return n;
}

void previousPOS() {
    int choice;
    printf("Press 0 to back to POS system: ");
    scanf("%d", &choice);
    switch(choice) {
        case 0:
            system("cls");
            possystem();
            break;
        default:
            system("cls");
            viewproduct();
            break;
    }
}

void previousdailyadmin() {
    int choice;
    printf("\nPress 1 to back to mainmenu / Press 0 to exit the program : ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            system("cls");
            mainmenuselection();
            break;
        case 0:
            exit(1);
            break;
        default:
            printf("\nYour choice was wrong please try again!!\n");
            previousdailyadmin();
            break;
    }
}
void previousweeklyadmin() {
    int choice;
    printf("\nPress 1 to back to mainmenu / Press 0 to exit the program : ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            system("cls");
            mainmenuselection();
            break;
        case 0:
            exit(1);
            break;
        default:
            printf("\nYour choice was wrong please try again!!\n");
            previousweeklyadmin();
            break;
    }
}

void previousdaily() {
    int choice;
    printf("\nPress 1 to back to POS menu / Press 0 to exit the program : ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            system("cls");
            possystem();
            break;
        case 0:
            exit(1);
            break;
        default:
            printf("\nYour choice was wrong please try again!!\n");
            previousdaily();
            break;
    }
}

void previousweekly() {
    int choice;
    printf("\nPress 1 to back to POS menu / Press 0 to exit the program : ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            system("cls");
            possystem();
            break;
        case 0:
            exit(1);
            break;
        default:
            printf("\nYour choice was wrong please try again!!\n");
            previousweekly();
            break;
    }
}

void IDPurchaseCorrection() {
    int choice; 
    printf("Press 1 to try again / Press 2 to back to POS menu: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            system("cls");
            purchaseproduct();
            break;
        case 2:
            system("cls");
            possystem();
            break;
        default:
            printf("\nYour choice was wrong please try again!!\n\n");
            IDPurchaseCorrection();
            break;
    }
}

void successfulpurchase() {
    int choice;
    printf("Press 1 to purchase another product / Press 2 to back to POS menu: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            system("cls");
            purchaseproduct();
            break;
        case 2:
            system("cls");
            possystem();
            break;
        default:
            printf("\nYour choice was wrong please try again!!\n\n");
            successfulpurchase();
            break;
    }
}

void insufficientQuant() {
    int choice;
    printf("Press 1 to try again / Press 2 to back to POS menu: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            system("cls");
            purchaseproduct();
            break;
        case 2:
            system("cls");
            possystem();
            break; 
        default:
            printf("\nYour choice was wrong please try again!!\n\n");
            insufficientQuant();
            break;
    }
}

void wrongminimumQuant() {
    int choice;
    printf("Press 1 to try again / Press 2 to back to POS menu: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            system("cls");
            purchaseproduct();
            break;
        case 2:
            system("cls");
            possystem();
            break;
        default:
            printf("\nYour choice was wrong please try again!!\n\n");
            wrongminimumQuant();
            break;
    }
}

void viewproduct() {
    int i;
    count = readFile();
    if(count < 0) {
        puts("cannot open file");
    }
    printf("|-----------------------------------------------------------------------------------|\n");
	printf("|                                      INVENTORY                                    |\n");
    printf("|-----------------------------------------------------------------------------------|\n");
    printf("|      NAME      |    PROD ID    |    QUANTITY   |  MINNIMUM QUANTITY |    PRICE    |\n");
    printf("|-----------------------------------------------------------------------------------|\n");
    for(i = 0; i < count; i++) { 
        printf("|    %-13s      %-11d    %-10d          %-8d        %-8.2f |\n", product[i].name, product[i].id, product[i].quantity, product[i].min_quan, product[i].price);
	}
    printf("|-----------------------------------------------------------------------------------|\n\n\n");
}

void viewproductforpurchase() {
    int choice;
    printf("Are you sure to buy the product ?\n");
    printf("Yes I'm sure press 1 / No and back to POS system press 0\n");
    printf("Choice --> ");
    scanf("%d", &choice);
    switch(choice) {
    case 1:
        system("cls");
        purchaseproduct();
        break;
    case 0:
        system("cls");
        possystem();
        break;
    default:
        system("cls");
        possystem();
        break;
    }
}

int cartviewproductforpurchase(int id) {
    system("cls");
    int i, j;
    count = readFile();
    for(i = 0; i < count; i++) {
        if(id == product[i].id) {
            j = i;
            break;
        }else {
            continue;
        }
    }
    if(count < 0) {
        puts("cannot open file");
    }
        printf("|-----------------------------------------------------------------------------------|\n");
	    printf("|                                      INVENTORY                                    |\n");
        printf("|-----------------------------------------------------------------------------------|\n");
        printf("|      NAME      |    PROD ID    |    QUANTITY   |  MINNIMUM QUANTITY |    PRICE    |\n");
        printf("|-----------------------------------------------------------------------------------|\n");
        printf("|    %-13s      %-11d    %-10d          %-8d        %-8.2f |\n", product[j].name, product[j].id, product[j].quantity, product[j].min_quan, product[i].price);
        printf("|-----------------------------------------------------------------------------------|\n");
}

void daily() {
    int i = 0, flag = 0, j, choice;
    float total, totalarry[1000];
    countpos = readposFile();
    int temp = countpos;
    if(countpos < 0) {
        puts("Cannot open file");
    }
    printf("|---------------------------------------------------------------------------------------------------|\n");
	printf("|                               DAY SUMMARY (COUNT BY FIRST PRODUCT)                                |\n");
    while(i >= 0) {
        total = 0;
        printf("|---------------------------------------------------------------------------------------------------|\n");
        printf("|  DAY  |      NAME      |    PROD ID    |    QUANTITY    |    PRICE    |          TIME             |\n");
        printf("|---------------------------------------------------------------------------------------------------|\n");
        for(j = 0; j < countpos; j++) {
            if((buy[j].time - buy[0].time) >= i * 86400 && (buy[j].time - buy[0].time) < (i + 1) * 86400) {
                total = total + (buy[j].price * buy[j].quantity);
                printf("|  %-4d   %-11s          %-11d     %-5d       %-9.2f      %-12s  |\n", i + 1, buy[j].name, buy[j].id, buy[j].quantity, buy[j].price * buy[j].quantity, buy[j].timestp);
                temp--;
                flag++;
            }
        }
        totalarry[i] = total;
        printf("|---------------------------------------------------------------------------------------------------|\n");
        printf("|                                     TOTAL OF DAY %d = %-8.2f                                     |\n", i + 1, totalarry[i]);
        printf("|---------------------------------------------------------------------------------------------------|\n\n");
        if(flag == 0) {
            printf("                                         Data not found!!                           \n");
        }
        if(temp == 0) {
            break;
        }
        i++;
    }
}
void admindaily() {
    int i = 0, flag = 0, j, choice;
    float total, totalarry[1000];
    float princsum, profit[1000];
    countpos = readposFile();
    int temp = countpos;
    if(countpos < 0) {
        puts("Cannot open file");
    }
    printf("|-----------------------------------------------------------------------------------------------------------------------|\n");
	printf("|                                         DAY SUMMARY (COUNT BY FIRST PRODUCT)                                          |\n");
    while(i >= 0) {
        total = 0;
        princsum = 0;
        printf("|-----------------------------------------------------------------------------------------------------------------------|\n");
        printf("|  DAY  |      NAME      |    PROD ID    |    QUANTITY    |    PRICE    |    PRINCIPLE    |            TIME             |\n");
        printf("|-----------------------------------------------------------------------------------------------------------------------|\n");
        for(j = 0; j < countpos; j++) {
            if((buy[j].time - buy[0].time) >= i * 86400 && (buy[j].time - buy[0].time) < (i + 1) * 86400) {
                total = total + (buy[j].price * buy[j].quantity);
                princsum = princsum + (buy[j].principle * buy[j].quantity);
                printf("|  %-4d   %-14s          %-11d     %-4d       %-11.2f    %-11.2f      %-12s   |\n", i + 1, buy[j].name, buy[j].id, buy[j].quantity, buy[j].price * buy[j].quantity,buy[j].principle* buy[j].quantity, buy[j].timestp);
                temp--;
                flag++;
            }
        }
        profit[i] = total - princsum;
        totalarry[i] = total;
        printf("|-----------------------------------------------------------------------------------------------------------------------|\n");
        printf("|                     TOTAL OF DAY %d = %-8.2f              |          PROFIT OF DAY %d = %-8.2f                      |\n", i + 1, totalarry[i], i+1, profit[i]);
        printf("|-----------------------------------------------------------------------------------------------------------------------|\n\n");
        if(flag == 0) {
            printf("                                         Data not found!!                                                       \n");
        }
        if(temp == 0) {
            break;
        }
        i++;
    }
}


void adminweekly() {
    int i = 0, flag = 0, j, choice;
    float total, totalarry[1000];
    float princsum, profit[1000];
    countpos = readposFile();
    int temp = countpos;
    if(countpos < 0) {
        puts("Cannot open file");
    }
    printf("|-----------------------------------------------------------------------------------------------------------------------|\n");
	printf("|                                        WEEK SUMMARY (COUNT BY FIRST PRODUCT)                                          |\n");
    while(i >= 0) {
        total = 0;
        princsum = 0;
        printf("|-----------------------------------------------------------------------------------------------------------------------|\n");
        printf("|  WEEK  |      NAME      |    PROD ID    |    QUANTITY    |    PRICE    |    PRINCIPLE    |            TIME            |\n");
        printf("|-----------------------------------------------------------------------------------------------------------------------|\n");
        for(j = 0; j < countpos; j++) {
            if((buy[j].time - buy[0].time) >= i * 604800 && (buy[j].time - buy[0].time) < (i + 1) * 604800) {
                total = total + (buy[j].price * buy[j].quantity);
                princsum = princsum + (buy[j].principle * buy[j].quantity);
                printf("|  %-4d   %-14s          %-11d     %-4d       %-11.2f    %-11.2f      %-12s   |\n", i + 1, buy[j].name, buy[j].id, buy[j].quantity, buy[j].price * buy[j].quantity,buy[j].principle* buy[j].quantity, buy[j].timestp);
                temp--;
                flag++;
            }
        }
        profit[i] = total - princsum;
        totalarry[i] = total;
        printf("|-----------------------------------------------------------------------------------------------------------------------|\n");
        printf("|                     TOTAL OF WEEK %d = %-8.2f              |          PROFIT OF WEEK %d = %-8.2f                    |\n", i + 1, totalarry[i], i+1, profit[i]);
        printf("|-----------------------------------------------------------------------------------------------------------------------|\n\n");
        if(flag == 0) {
            printf("                                         Data not found!!                                                       \n");
        }
        if(temp == 0) {
            break;
        }
        i++;
    }

}

void weekly() {
    int i = 0, flag = 0, j, choice;
    float total, totalarry[1000];
    countpos = readposFile();
    int temp = countpos;
    if(countpos < 0) {
        puts("Cannot open file");
    }
    printf("|---------------------------------------------------------------------------------------------------|\n");
	printf("|                              WEEK SUMMARY (COUNT BY FIRST PRODUCT)                                |\n");
    while(i >= 0) {
        total = 0;
        printf("|---------------------------------------------------------------------------------------------------|\n");
        printf("| Week |      NAME      |    PROD ID    |    QUANTITY    |    PRICE    |          TIME              |\n");
        printf("|---------------------------------------------------------------------------------------------------|\n");
        for(j = 0; j < countpos; j++) {
            if((buy[j].time - buy[0].time) >= i * 604800 && (buy[j].time - buy[0].time) < (i + 1) * 604800) {
                total = total + (buy[j].price * buy[j].quantity);
                printf("|  %-4d   %-11s          %-11d     %-5d       %-9.2f      %-12s  |\n", i + 1, buy[j].name, buy[j].id, buy[j].quantity, buy[j].price * buy[j].quantity, buy[j].timestp);
                temp--;
                flag++;
            }
        }
        totalarry[i] = total;
        printf("|---------------------------------------------------------------------------------------------------|\n");
        printf("|                                     TOTAL OF WEEK %d = %-8.2f                                    |\n", i + 1, totalarry[i]);
        printf("|---------------------------------------------------------------------------------------------------|\n\n");
        if(flag == 0) {
            printf("                                         Data not found!!                           \n");
        }
        if(temp == 0) {
            break;
        }
        i++;
    }

}

void purchaseproduct() {
    viewproduct();
    time_t t = time(NULL);
    char *str_time = ctime(&t);
    int quant, i, id, choice, z = false, temp1 = false, temp2 = false, temp3 = false, c = false;
    count = readFile();
    countpos = readposFile();
	printf("Choose product's ID\n");
    printf("Product ID: ");
    fflush(stdin);
	scanf("%d", &id);
    printf("Are you sure to buy this product?\nSure press 1. \nNot Sure press 0 and choose product.\nChoice --> ");
    scanf("%d", &choice);
    switch (choice){
        case 1:
            break;
        case 0:
            purchaseproduct();
            break;
        default:
            purchaseproduct();
            break;
    }
    for(i = 0; i < count; i++) {
        if(id == product[i].id) {
            z = true;
            printf("\nItem available!\n");
	   	    cartviewproductforpurchase(id);
            printf("Enter the quantity you want to buy: ");
            fflush(stdin);
			scanf("%d", &quant);
            if(quant <= product[i].quantity && quant >= product[i].min_quan) {
                printf("\nSuccessful purchase!\n");
                temp1 = true;
            }
            else if(quant > product[i].quantity) {		
                printf("\nInsufficient quantity please restock!\n");
                temp2 = true;
                break;
			}
            else if(quant < product[i].min_quan) {
                printf("\nSorry, but there are minimum quantities for each item!\n");
                temp3 = true;
                break;
            }
            product[i].quantity -= quant;
            if(countpos > 0) {
  	            countpos = readposFile();
		    }
            buy[countpos].id = product[i].id;
            strcpy(buy[countpos].name, product[i].name);
            buy[countpos].quantity = quant;
            buy[countpos].price = product[i].price;
            buy[countpos].principle = product[i].principle;
            strcpy(buy[countpos].timestp, str_time);
            buy[countpos].time = t;
            ++countpos;
		}
    }
    if(z == false) {	
        printf("Cant find the product id: %d\n\n", id);
        IDPurchaseCorrection();
    }   
    writeFile();
    writeposFile();
    if(temp1 == true) {
        successfulpurchase();
    }
    else if(temp2 == true) {		
        insufficientQuant();
	}
    else if(temp3 == true) {
        wrongminimumQuant();
    }
    previousPOS();
}

int possystem() {
        printf("|-----------------------------------------------|\n");
        printf("|                 Point of sale                 |\n");
        printf("|-----------------------------------------------|\n");
        printf("|        Press 1 to view product                |\n");
        printf("|        Press 2 to purchase product            |\n");
        printf("|        Press 3 to view daily summary          |\n");
        printf("|        Press 4 to view weekly summary         |\n");
        printf("|        Press 5 to back to main menu           |\n");
        printf("|        Press 0 to exit the program            |\n");
        printf("|-----------------------------------------------|\n");
        printf("\nChoice --> ");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                system("cls"); 
                viewproduct();
                previousPOS();
                break;
            case 2:
                system("cls"); 
                purchaseproduct();
                break;
            case 3:
                system("cls"); 
                daily();
                previousdaily();
                break;
            case 4:
                system("cls"); 
                weekly();
                previousweekly();
                break;
            case 5:
                system("cls"); 
                clientmainmenuselection();
                break;
            case 0:
                exit(1);
                break;
            default:
                system("cls"); 
                printf("Your choice was wrong please try again!!\n");
                possystem();
                break;
        }
}
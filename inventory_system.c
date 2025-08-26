#include <stdio.h>
#include <string.h>
#include <stdlib.h>	
#define true 0 
#define false 1

int mainmenuselection();
int accountingsystem();
int possystem();
int IDChecker(int i, int j);
int checkID(int id);
void deleteproduct();
void addproduct();
int modifyproduct();
void displayproduct();
void previous();
int checkIDmodfify();

struct product {
	int id;   
	char name[20]; 
	int quantity; 
	float price;
    float principle;
    int min_quan;
    float total;
};
struct product product[40];
struct bought {
    int id;
    char name[20];
    int quantity; 
	float price;
    float principle;
    char timestp[30];
    int day;
    int time;
};
struct bought buy[30];
struct day {
    int id[100];
    int quantity[100];
    float price[100];
    float total;
};
struct day d[30];
int count = 0;	
int countpos = 0;
int daycounter = 0;
int dcount = 0;
FILE *f;

void previous() {
    int choice;
    printf("Press 0 to back to inventory --> ");
    scanf("%d", &choice);
    switch(choice){
        case(0):
            system("cls");
            inventorysystem();
            break;
    }
}

int writeFile() {
    int i;
    f = fopen("inventory.txt", "w");  
    if(f == NULL) {
        return - 1;
    }			
    fprintf(f, "%d\n", count);
    for(i = 0; i < count; ++i) { 
        fprintf(f, "%d\n", product[i].id);
        fputs(product[i].name, f);
        fprintf(f, "\n");
        fprintf(f, "%d\n", product[i].quantity);
        fprintf(f, "%f\n", product[i].price);
        fprintf(f, "%f\n", product[i].principle);
        fprintf(f, "%d\n", product[i].min_quan);
    }
    fclose(f);
    return 0;
}

int readFile() {
    int n = 0;
    int i;
    f = fopen("inventory.txt", "r");
    if(f == NULL) {
        return -1;
    }
    fscanf(f, "%d\n", &n);
    for(i = 0; i < n; ++i) {
        fscanf(f, "%d\n", &product[i].id); 
        fgets(product[i].name, 20, f);
        product[i].name[strlen(product[i].name) - 1] = 0; 
        fscanf(f, "%d\n", &product[i].quantity);
        fscanf(f, "%f\n", &product[i].price);
        fscanf(f, "%f\n", &product[i].principle);
        fscanf(f, "%d\n", &product[i].min_quan);
    }
    fclose(f);
    return n;
}

int IDChecker(int i, int j)	{
	count = readFile();
    printf("Product ID: ");
    fflush(stdin);
	scanf("%d", &product[count].id);
    if(product[i].id == product[j].id) {
        printf("Product ID number is already taken!!\n");
        return IDChecker(i++, j--);
	}
}



int checkID(int idz) { 
	int i;
    count = readFile();
    readFile();
 	for(i = 0; i < count; i++) {
	    if(idz == product[i].id) { 
            fclose(f);
            return 1;
            break;
		}else{
            continue;
        }
    		
    }
    fclose(f); 
    return 0;
}

void displayaddproduct() {
    int i;
    count = readFile();
    if(count < 0) {
        puts("cannot open file");
    }
        printf("|-------------------------------------------------------------------------------------------------------------|\n");
	    printf("|                                                 INVENTORY                                                   |\n");
        printf("|-------------------------------------------------------------------------------------------------------------|\n");
        printf("|      NAME      |    PROD ID    |    QUANTITY    |   MINIMUM QUANTITIES   |     PRICE    |     PRINCIPLE     |\n");
        printf("|-------------------------------------------------------------------------------------------------------------|\n");
        for(i = 0; i < count; i++) { 
        printf("|  %-11s          %-12d     %-12d       %-10d        %-13.2f      %-11.2f  |\n", product[i].name, product[i].id, product[i].quantity, product[i].min_quan, product[i].price, product[i].principle);
	    }
        printf("|-------------------------------------------------------------------------------------------------------------|\n\n\n");
        addproduct();
}


void addproduct() {	
  	printf("ENTER NEW PRODUCTS\n");
	count = readFile();		
  	    if(count > 0) {
  	        count = readFile();
  		    IDChecker(0, count); 
		}else {
		    printf("\nProduct ID Number: ");
		    fflush(stdin); 
		    scanf("%d",&product[count].id);
		}
		printf("Product name: ");scanf("%s",product[count].name);
		printf("Quantity of the product: ");scanf("%d", &product[count].quantity);
		printf("Price of the product: ");scanf("%f", &product[count].price);
        printf("Principle of the product: ");scanf("%f", &product[count].principle);
        printf("Minimum Order Quantity of the product: ");scanf("%d", &product[count].min_quan);
		++count;
        system("cls");
        printf("Added successufully!!\n"); 
    writeFile();
}

void inventoryformodifyprod(){
    system("cls");
    int i;
    count = readFile();
    if(count < 0) {
        puts("cannot open file");
    }
        printf("|-------------------------------------------------------------------------------------------------------------|\n");
	    printf("|                                                 INVENTORY                                                   |\n");
        printf("|-------------------------------------------------------------------------------------------------------------|\n");
        printf("|      NAME      |    PROD ID    |    QUANTITY    |   MINIMUM QUANTITIES   |     PRICE    |     PRINCIPLE     |\n");
        printf("|-------------------------------------------------------------------------------------------------------------|\n");
        for(i = 0; i < count; i++) { 
        printf("|  %-11s          %-12d     %-12d       %-10d        %-13.2f      %-11.2f  |\n", product[i].name, product[i].id, product[i].quantity,product[i].min_quan, product[i].price, product[i].principle);
	    }
        printf("|-------------------------------------------------------------------------------------------------------------|\n\n\n");
        modifyproduct();
}

int showInveninmodify(int id){
    system("cls");
    int i,j;
    count = readFile();
    for(i=0;i<count;i++){
        if(id == product[i].id){
            j = i;
            break;
        }else{
            continue;
        }
    }

    if(count < 0) {
        puts("cannot open file");
    }
        printf("|-------------------------------------------------------------------------------------------------------------|\n");
	    printf("|                                                 INVENTORY                                                   |\n");
        printf("|-------------------------------------------------------------------------------------------------------------|\n");
        printf("|      NAME      |    PROD ID    |    QUANTITY    |   MINIMUM QUANTITIES   |     PRICE    |     PRINCIPLE     |\n");
        printf("|-------------------------------------------------------------------------------------------------------------|\n");
        printf("|  %-11s          %-12d     %-12d       %-10d        %-13.2f      %-11.2f  |\n", product[j].name, product[j].id, product[j].quantity,product[j].min_quan, product[j].price, product[j].principle);
        printf("|-------------------------------------------------------------------------------------------------------------|\n\n\n");

}

int modifyproduct() {
    int id;
    int test;
    int i,new_number;
	int choice,choice2,choice3;
    printf("EDIT A PRODUCT!");
    printf("\nEnter the id of the product that you want to edit: "); 
	fflush(stdin);
	scanf("%d",&id);
	test = checkID(id);
    // printf("\ntest = %d\n",test);
    if(test == 0) {
        system("cls");
        printf("The id num %d is not found.\n", id);
        printf("Press 0 return to inventorymenu or press 1 to try again --> ");
        scanf("%d",&choice2);
        switch (choice2)
        {
        case 0:
            system("cls");
            inventorysystem();
            break;
        case 1:
            system("cls");
            inventoryformodifyprod();
        default:
            inventorysystem();
            break;
        }

    }else  {
 		readFile();
        {
	        for(i = 0; i < count; i++){
                if(id != product[i].id){
                    writeFile();
                }else {
                    system("cls");
                    showInveninmodify(id);
                    printf("\nPress 1 to update product ID number");
                    printf("\nPress 2 to update product's name");
                    printf("\nPress 3 to update product's quantity");
                    printf("\nPress 4 to update product's price");
                    printf("\nPress 5 to update product's principle");
                    printf("\nPress 6 to Update product's minimum quantity");
                    printf("\nPress 0 to Back to inventory menu\n");
                    printf("\nEnter your choice --> ");
                    fflush(stdin);
                    scanf("%d", &choice);
                    switch(choice) {
                    case 1:
                        system("cls");
                        showInveninmodify(id);
                        printf("Enter new ID: ");
 		                fflush(stdin);
                        scanf("%d",&new_number);
                        product[i].id=new_number;
                        id=new_number;
                    break;
                    case 2:
                        system("cls");
                        showInveninmodify(id);
                        printf("Enter new name: ");
    	                fflush(stdin);
                        gets(product[i].name);
                    break;
                    case 3:
                        system("cls");
                        showInveninmodify(id);
                        printf("Enter new quantity: ");
                        scanf("%d", &product[i].quantity);
                    break;
                    case 4:
                        system("cls");
                        showInveninmodify(id);
                        printf("Enter new price: ");
                        scanf("%f", &product[i].price);
                    break;
                    case 5:
                        system("cls");
                        showInveninmodify(id);
                        printf("Enter new principle: ");
                        scanf("%f", &product[i].principle);
                    break;
                    case 6:
                        system("cls");
                        showInveninmodify(id);
                        printf("Enter the new minimum order quantity: ");
                        scanf("%d", &product[i].min_quan);
                    break;
                    case 0:
                        system("cls");
                        inventorysystem();
                    break;
                    default:
                        printf("Invalid selection");
                    break;
                    }
                    writeFile();
                }
            }
        }
        fclose(f); 
        f = fopen("inventory.txt", "r");
        readFile();
        writeFile();
        fclose(f);
        system("cls");
        showInveninmodify(id);
        printf("Product was updated!!\n");
        printf("Press 1 to edit product again or press 0 to return to inventorymenu --> ");
        scanf("%d",&choice3);
        switch (choice3){
        case 1:
            system("cls");
            inventoryformodifyprod();
            break;
        case 0:
            system("cls");
            inventorysystem();
            break;
        default:
            system("cls");
            inventorysystem();
            break;
        }
    }
}

void showinventoryfordelfun(){
    system("cls");
    int i;
    count = readFile();
    if(count < 0) {
        puts("cannot open file");
    }
        printf("|-------------------------------------------------------------------------------------------------------------|\n");
	    printf("|                                                 INVENTORY                                                   |\n");
        printf("|-------------------------------------------------------------------------------------------------------------|\n");
        printf("|      NAME      |    PROD ID    |    QUANTITY    |   MINIMUM QUANTITIES   |     PRICE    |     PRINCIPLE     |\n");
        printf("|-------------------------------------------------------------------------------------------------------------|\n");
        for(i = 0; i < count; i++) { 
        printf("|  %-11s          %-12d     %-12d       %-10d        %-13.2f      %-11.2f  |\n", product[i].name, product[i].id, product[i].quantity,product[i].min_quan, product[i].price, product[i].principle);
	    }
        printf("|-------------------------------------------------------------------------------------------------------------|\n\n\n");
    deleteproduct();
}

void deleteproduct() { 
    count = readFile();
	int id; 
	int i, j, choice;
	int z = false;
    printf("Enter the product ID that you want to delete -->  "); 
    fflush(stdin);
    scanf("%d", &id);
    for(i = 0; i < count; i++) {		
	    if(product[i].id == id){
            z = true;
	        for(j = i; j < (count - 1); j++) {
		        product[j] = product[j + 1];
		    }
            count--;
            printf("Delete successfully\n");
	    }
    }   
    if(z == false) {    
        printf("Cant find product id: %d.\n", id);
        printf("Press 1 to try again / Press 0 to go back to inventory page --> ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                system("cls");
                showinventoryfordelfun();
                break;
            case 0:
                system("cls");
                inventorysystem();
                break;
            default:
                system("cls");
                inventorysystem();
                break;
        }
    }
    writeFile();
}

void displayproduct() {
    int i;
    count = readFile();
    if(count < 0) {
        puts("cannot open file");
    }
        printf("|-------------------------------------------------------------------------------------------------------------|\n");
	    printf("|                                                 INVENTORY                                                   |\n");
        printf("|-------------------------------------------------------------------------------------------------------------|\n");
        printf("|      NAME      |    PROD ID    |    QUANTITY    |   MINIMUM QUANTITIES   |     PRICE    |     PRINCIPLE     |\n");
        printf("|-------------------------------------------------------------------------------------------------------------|\n");
        for(i = 0; i < count; i++) { 
        printf("|  %-11s          %-12d     %-12d       %-10d        %-13.2f      %-11.2f  |\n", product[i].name, product[i].id, product[i].quantity, product[i].min_quan, product[i].price, product[i].principle);
	    }
        printf("|-------------------------------------------------------------------------------------------------------------|\n\n\n");
        previous();
}

int inventorysystem() {
	int choice;
	count = readFile();
	if(count < 0) 
	    printf("Cannot locate file\n");
    do {
        printf("|-----------------------------------------------|\n");
        printf("|                INVENTORY PROGRAM              |\n");
        printf("|-----------------------------------------------|\n");
        printf("|       Press 1 to add product                  |\n");
        printf("|       Press 2 to modify product               |\n");
        printf("|       Press 3 to delete product               |\n");
        printf("|       Press 4 to display all exiting product  |\n");
        printf("|       Press 5 to back to main menu            |\n");
        printf("|       Press 0 to exit the program             |\n");
        printf("|-----------------------------------------------|\n");
	    printf("\nChoice --> ");
	    scanf("%d", &choice);
	    switch(choice){
            case 1: 
                system("cls");
                displayaddproduct();
                break;
            case 2:
                system("cls");
		    	inventoryformodifyprod();
				break;
            case 3:
                system("cls");
                showinventoryfordelfun();
               	break;
            case 4:
                system("cls");
                displayproduct();
                break;
            case 5:
                system("cls");
	            mainmenuselection(); 
		 	    break;
		    case 0:
                system("cls");
		 	    exit(1);
			    break;
		    default:
                printf("Your choice was wrong please try again");
            break;
        }
    }while(choice != 0);
}
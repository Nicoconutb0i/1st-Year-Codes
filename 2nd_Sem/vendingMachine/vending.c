#include "vending.h"
#include "dispenser.h"

void showSelection() {
    do{
        int selection = 0;
        int index = -1;
        int quantity = 0;

        printf("*** Welcome to Snack Shop ***\n\n");
        printf("To select an item, enter");
        printf("\n1. Candy   [Php 10]");
        printf("\n2. Chips   [Php 15]");
        printf("\n3. Cookies [Php 15]");
        printf("\n4. Soda    [Php 25]");
        printf("\n9. Exit\n\n");

        printf("Enter Choice: ");
        if(scanf("%d", &selection) != 1){
            printf("Error: Invalid Input! Please Try Again.\n\n");
            continue;
        }

        index = selection - 1;

        if(selection >= 1 && selection <= 4){
            printf("How many %s? ", itemInfo[index].name);
            if(scanf("%d", &quantity) != 1 || quantity <= 0){
                printf("Error: Invalid quantity!\n");
                continue;
            }

            sellProduct(index, quantity);
            break;
        } else if(selection == 9){
            printf("Goodbye!\n");
            return;
        } else {
            printf("Error: Invalid Input! Please Try Again.\n\n");
        }
    }while(1);
}

void sellProduct(int index, int stock){
    int quantity = getCount(index);

    if(quantity == 0){
        return;
    }

    if(quantity < stock){
        printf("Not enough stock available!\n");
        return;
    }

    int totalCost = getProductCost(index, stock);
    makeSale(stock, totalCost, index);
}

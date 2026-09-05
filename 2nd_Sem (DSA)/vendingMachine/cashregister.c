#include "vending.h"
#include "cashregister.h"

int currentBalance(int price){
    int tries = 2;
    int deposit = 0;

    while(tries > 0){
        printf("Please deposit %d pesos\n", price);
        if(scanf("%d", &deposit) != 1 || deposit < 0){
            tries--;
            if(tries > 0){
                printf("1 Try Remaining.\n");
            }
            continue;
        }

        if(deposit >= price){
            printf("Here's your change: %d PHP\n", deposit - price);
            return 1;
        }

        tries--;

        if(tries > 0){
            printf("1 Try Remaining.\n");
        }
    }

    printf("Goodbye!\n");
    return 0;
}

void acceptMoney(int index, int quantity){
    printf("Collect your item at the bottom and enjoy.\n");
    itemInfo[index].count = itemInfo[index].count - quantity;
}

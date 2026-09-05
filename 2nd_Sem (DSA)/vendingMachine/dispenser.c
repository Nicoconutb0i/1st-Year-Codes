#include "vending.h"
#include "dispenser.h"
#include "cashregister.h"

int getCount(int index){
    
    if(itemInfo[index].count == 0){
        printf("This product is sold out!\n");
    }
    
    return itemInfo[index].count;
}

int getProductCost(int index, int quantity){
    
    int purchasedCost = itemInfo[index].cost * quantity;
    
    return purchasedCost;
}

void makeSale(int quantity, int totalCost, int index){
    if(currentBalance(totalCost)){
        acceptMoney(index, quantity);
    }
}

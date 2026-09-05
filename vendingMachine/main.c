#include "vending.h"

ITEM itemInfo[4];

int main() {

    strcpy(itemInfo[0].name, "Candy");
    strcpy(itemInfo[1].name, "Chips");
    strcpy(itemInfo[2].name, "Cookies");
    strcpy(itemInfo[3].name, "Soda");

    for(int i = 0; i < 4; i++){
        itemInfo[i].count = 100;
    }

    itemInfo[0].cost = 10;
    itemInfo[1].cost = 15;
    itemInfo[2].cost = 15;
    itemInfo[3].cost = 25;

    showSelection();

    return 0;
}

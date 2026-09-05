#ifndef VENDING_H_INCLUDED
#define VENDING_H_INCLUDED

#include<stdio.h>
#include<string.h>

typedef struct Dispenser {
    char name[10];
    int count;
    int cost;
}ITEM;

extern ITEM itemInfo[4];

void showSelection();
void sellProduct(int, int);

#endif // VENDING_H_INCLUDED

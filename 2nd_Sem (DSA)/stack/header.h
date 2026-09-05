#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char data;
    struct node *next;
}NODE;

typedef struct{
    int count;
    NODE *top;
}STACK;

void decToHex(int, STACK *);
void push(char, STACK *);
void pop(STACK *);

#endif // HEADER_H_INCLUDED

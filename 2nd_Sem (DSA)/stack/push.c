#include "header.h"

void push(char hex, STACK *stack){
    NODE *newNode = malloc(sizeof(NODE));
    newNode->data = hex;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->count++;
}

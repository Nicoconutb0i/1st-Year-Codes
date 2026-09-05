#include "header.h"

void insertRear(LIST *L, int number){
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    if (newNode == NULL) return;

    newNode->data = number;
    newNode->next = NULL;

    if (L->head == NULL) { 
        L->head = newNode;
        L->tail = newNode;
    } else {
        L->tail->next = newNode;
        L->tail = newNode;
    }
    
    (L->count)++;
}
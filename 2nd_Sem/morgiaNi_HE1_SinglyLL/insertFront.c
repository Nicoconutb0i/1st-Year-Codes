#include "header.h"

void insertFront(LIST *L, int number){
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
//    if (newNode == NULL) return;

    newNode->data = number;
    newNode->next = L->head;

    L->head = newNode;

    if (L->tail == NULL) {
        L->tail = newNode;
    }

    (L->count)++;
}
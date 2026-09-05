#include "header.h"

void insertAt(LIST *L, int number, int pos){
    if (pos < 0 || pos > L->count) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 0) {
        insertFront(L, number);
        return;
    }

    if (pos == L->count) {
        insertRear(L, number);
        return;
    }

    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = number;

    NODE *temp = L->head;
    for (int i = 0; i < pos - 1; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    (L->count)++;
}
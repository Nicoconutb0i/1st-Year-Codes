#include "header.h"

int main(){
    LIST *L = (LIST*) malloc(sizeof(LIST));

    L->count = 0;
    L->head = NULL;
    L->tail = NULL;

    insertFront(L, 2);
    displayAll(L);
    insertFront(L, 1);
    displayAll(L);
    insertFront(L, 0);
    displayAll(L);
    insertRear(L, 3);
    displayAll(L);
    insertRear(L, 5);
    displayAll(L);
    insertAt(L, 4, 4);
    displayAll(L);
    deleteFront(L);
    displayAll(L);
    deleteRear(L);
    displayAll(L);
    insertAt(L, 88, 2);
    displayAll(L);
    deleteAt(L, 2);
    displayAll(L);

    return 0;
}
#include"header.h"

void printMirror(LIST *l){
    NODE *temp = l->tail;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}
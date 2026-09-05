#include"header.h"

void removeFront(LIST *l){
    NODE *temp = l->head;

    if(l->head == l->tail){
        l->head = NULL;
        l->tail = NULL;
    }
    else{
        l->head = l->head->next;
        l->head->prev = NULL;
    }

    free(temp);
    l->count--;
}
#include"header.h"

void removeRear(LIST *l){
    NODE *temp = l->tail;

    if(l->head == l->tail){
        l->head = NULL;
        l->tail = NULL;
    }
    else{
        l->tail = l->tail->prev;
        l->tail->next = NULL;
    }

    free(temp);
    l->count--;
}

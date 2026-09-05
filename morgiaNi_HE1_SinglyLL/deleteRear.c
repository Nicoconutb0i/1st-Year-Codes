#include "header.h"

void deleteRear(LIST *L){
    if(L->head == NULL){
        printf("List is empty. Cannot delete from rear.\n");
        return;
    }

    NODE *temp = L->head;
    NODE *prev = NULL;

    if(temp->next == NULL){
        L->head = NULL;
        L->tail = NULL;

        free(temp);
        (L->count)--;

        return;
    }

    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }


    L->tail = prev;
    prev->next = NULL;
    
    free(temp);
    (L->count)--;
}

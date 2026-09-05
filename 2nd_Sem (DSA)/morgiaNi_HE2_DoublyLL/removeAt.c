#include"header.h"

void removeAt(LIST *l, int pos){

    if(pos < 0 || pos >= l->count){
        printf("Error: Invalid position!\n");
        return;
    }

    NODE *temp = l->head;

    for(int i = 0; i < pos; i++){
        temp = temp->next;
    }

    if(temp->prev == NULL){
        l->head = temp->next;
        if(l->head != NULL)
            l->head->prev = NULL;
        else
            l->tail = NULL;
    } else if(temp->next == NULL){
        l->tail = temp->prev;
        l->tail->next = NULL;
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);
    l->count--;
}
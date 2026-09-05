#include"header.h"

void printList(LIST *list){
    NODE *temp = list->head;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
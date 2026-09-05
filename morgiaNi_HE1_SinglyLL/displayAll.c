#include "header.h"

void displayAll(LIST *L){
    NODE *temp = L->head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    while(temp != NULL){
        printf("%d", temp->data);
        if(temp->next){
            printf("->");
        }
        temp = temp->next;
    }
    printf("\n");
}
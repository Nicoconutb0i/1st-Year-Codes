#include "header.h"

void deleteFront(LIST *L){
    if (L->head == NULL) {
        printf("List is empty. Cannot delete from front.\n");
        return;
    }

    NODE *temp = L->head;
    L->head = L->head->next;

    if (L->head == NULL) {
        L->tail = NULL;
    }

    free(temp);
    (L->count)--;
}
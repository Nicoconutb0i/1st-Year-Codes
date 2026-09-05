#include "header.h"

void deleteAt(LIST *L, int pos){
    if (L->head == NULL || pos < 0 || pos >= L->count) {
        printf("Invalid position or empty list.\n");
        return;
    }

    if (pos == 0) {
        deleteFront(L);
        return;
    }

    NODE *prev = L->head;
    for (int i = 0; i < pos - 1; i++) {
        prev = prev->next;
    }

    NODE *toDelete = prev->next;
    prev->next = toDelete->next;

    if (prev->next == NULL) {
        L->tail = prev;
    }

    free(toDelete);
    (L->count)--;
}
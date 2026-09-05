#include"header.h"

int main(){
    LIST *list = malloc(sizeof(LIST));

    list->count = 0;
    list->head = NULL;
    list->tail = NULL;

    insertFront(list, 3);
    printList(list); printf("\n");
    insertFront(list, 2);
    printList(list); printf("\n");
    insertFront(list, 1);
    printList(list); printf("\n");
    insertRear(list, 5);
    printList(list); printf("\n"); 
    insertRear(list, 6);
    printList(list); printf("\n");
    insertAt(list, 4, 3);
    printList(list); printf("\n");
    insertAt(list, 7, 6);
    printList(list); printf("\n");
    insertAt(list, 0, 0);
    printList(list); printf("\n");
    removeFront(list);
    printList(list); printf("\n");
    removeRear(list);
    printList(list); printf("\n");
    removeRear(list);
    printList(list); printf("\n");
    insertAt(list, 8, 2); 
    printList(list); printf("\n");
    removeAt(list, 2);
    printList(list); printf("\n");
    printMirror(list);

    return 0;
}
#include"header.h"

void insertFront(LIST *l, int data){
    NODE *newNode = malloc(sizeof(NODE));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = l->head;

    if(l->head == NULL){
        l->head = newNode;
        l->tail = newNode;
    }
    else{
        l->head->prev = newNode;
        l->head = newNode;
    }

    l->count++;
}

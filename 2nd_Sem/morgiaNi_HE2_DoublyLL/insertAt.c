#include"header.h"

void insertAt(LIST *l, int data, int pos){
    if(pos < 0 || pos > l->count){
        printf("Error: No position found!");
        return;

    } else if(pos == 0){
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

    } else {
        NODE *newNode = malloc(sizeof(NODE));
        newNode->data = data;

        NODE *temp = l->head;

        for(int i = 0; i < pos - 1; i++){
            temp = temp->next;
        }

        newNode->prev = temp;
        newNode->next = temp->next;

        if(temp->next != NULL){
            temp->next->prev = newNode;
        } else {
            l->tail = newNode;
        }

        temp->next = newNode;
        l->count++;
    }
}
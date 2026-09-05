#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "sort.h"

void bubbleSort(LIST *L){
	for(int i = 0; i < L->count - 1; i++){
        NODE *current = L->head;

        while(current->n != NULL){
            if(current->x > current->n->x){
                int temp = current->x;
                current->x = current->n->x;
                current->n->x = temp;
            }
            current = current->n;
        }

        displayList(L->head);
    }
}

void selectionSort(LIST *L){
    NODE *temp = L->head;

    while(temp){
        NODE *min = temp;
        NODE *r = temp->n;

        while(r){
            if(min->x > r->x){
                min = r;
            }
            r = r->n;
        }

        int swap = temp->x;
        temp->x = min->x;
        min->x = swap;

        displayList(L->head);
        temp = temp->n;
    }
}

void insertionSort(LIST *L){
	NODE *i = L->head->n;

    while(i != NULL){
        int key = i->x;
        NODE *j = i->p;

        while(j != NULL && j->x > key){
            j->n->x = j->x;
            j = j->p;
        }

        if(j == NULL){
            L->head->x = key;
        }else{
            j->n->x = key;
        }

        displayList(L->head);
        i = i->n;
    }
}
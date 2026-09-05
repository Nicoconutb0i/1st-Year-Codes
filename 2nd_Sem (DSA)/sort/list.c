#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

void createList(LIST *L, int x){
	time_t t;
	srand((unsigned) time(&t));
	
	if(L->count){
		destroyList(L);
	}
	
	for(int i = 0; i < x; i++){
		int n = rand() % 101;
		insertEnd(L, n);
	}
}

void destroyList(LIST *L){
    while(L->count > 0){
        deleteEnd(L);
    }
}

void insertEnd(LIST *L, int x){
    NODE *newNode = (NODE*)malloc(sizeof(NODE));

    newNode->i = L->count;
    newNode->x = x;
    newNode->p = L->tail;
    newNode->n = NULL;

    if(L->count == 0){
        L->head = newNode;
        L->tail = newNode;
    }else{
        L->tail->n = newNode;
        L->tail = newNode;
    }

    L->count++;
}

void deleteEnd(LIST *L){
    if(L->tail == NULL) return;

    NODE *temp = L->tail;

    if(L->head == L->tail){
        L->head = NULL;
        L->tail = NULL;
    }else{
        L->tail = L->tail->p;
        L->tail->n = NULL;
    }

    free(temp);
    L->count--;
}

void displayList(NODE *head){
	NODE *t;
	t = head;

	while(t!=NULL){
		printf("%5d", t->x);
		t = t->n;
	}

	printf("\n");
}
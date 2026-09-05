#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include "search.h"

void insertRear(int x, LIST *list_ptr, int index){
	NODE *newNode = malloc(sizeof(NODE));

	if(list_ptr->count==0){
		newNode->data = x;
		newNode->index = index;
		newNode->n = NULL;
		newNode->p = NULL;
		list_ptr->head = newNode;
		list_ptr->tail = newNode;
		list_ptr->count++;
	}else{
		newNode->data = x;
		newNode->index = index;
		newNode->n = NULL;
		newNode->p = list_ptr->tail;
		list_ptr->tail->n = newNode;
		list_ptr->tail = newNode;
		list_ptr->count++;
	}	
}

void destroy(LIST *list_ptr){
    NODE *current = list_ptr->head;
    NODE *next;

    while(current != NULL){
        next = current->n;   // save next node
        free(current);       // free current node
        current = next;      // move forward
    }

    list_ptr->head = NULL;
    list_ptr->tail = NULL;
    list_ptr->count = 0;
}

void generate(LIST *list_ptr){
	int i, x; 
	time_t t;
	srand((unsigned) time(&t));
	
	for(i = 0; i < 10; i++){
		x = rand() % 101;
		insertRear(x, list_ptr, i);	
	}
}

point partition(LIST *L, NODE *start, NODE *end){
	NODE *left,*right,*pivot;
	int temp;
	
	pivot = left = start;
	right = end;
	
	while(left->index < right->index){
		while(left->data <= pivot->data && left->index < right->index){
			left = left->n;
		}
		while(right->data > pivot->data){
			right = right->p;
		}
		if(left->index < right->index){
			temp = left->data;
			left->data = right->data;
			right->data = temp;
		}	
	}

	temp = pivot->data;
	pivot->data = right->data;
	right->data = temp;	
	pivot = right;

	return pivot;
}

void qSort(LIST *list_ptr, NODE *start, NODE *end){
    if(start == NULL || end == NULL || start->index >= end->index)
        return;

    point pivot = partition(list_ptr, start, end);

    if(pivot != NULL){
        qSort(list_ptr, start, pivot->p);
        qSort(list_ptr, pivot->n, end);
    }
}

void printSort(LIST *list_ptr){
	int i;
	NODE *num, *index;
	num = list_ptr->head;
	index = list_ptr->head;

	if(num==NULL){
		printf("\n");
		printf("\n\nList is Empty");	
		printf("\nGenerate List First");
	}else{
		printf("\nLOCATION:\n");
		for(i = 0;i < list_ptr->count; i++){
			printf("%3d  ", index->index);
			index = index->n; 
		}
		printf("\nDATA:\n");
		for(i = 0; i < list_ptr->count; i++){
			printf("%3d  ", num->data);
			num = num->n; 
		}
	}
}

bool linearSearch(LIST *list_ptr, int key, int location[], int *j){
	bool value = 0;
	int i = 0;
	NODE *looker;	
	looker = list_ptr->head;

	while(looker != NULL){
		if(key == looker->data){
			location[i] = looker->index;
			value = 1;
			(*j)++;
			i++;
		}	
		
		looker = looker->n;
	}
	return value;	
}

bool binarySearch(LIST *list_ptr, int key, int location[], int *j){
    bool found = 0;
    int i = 0;

    int median = list_ptr->count / 2;
    NODE *mid = list_ptr->head;

    // go to middle
    while(mid != NULL && mid->index != median){
        mid = mid->n;
    }

    if(mid == NULL) return 0;

    // search LEFT side
    NODE *temp = list_ptr->head;
    while(temp != mid){
        if(temp->data == key){
            location[i++] = temp->index;
            (*j)++;
            found = 1;
        }
        temp = temp->n;
    }

    // check middle
    if(mid->data == key){
        location[i++] = mid->index;
        (*j)++;
        found = 1;
    }

    // search RIGHT side
    temp = mid->n;
    while(temp != NULL){
        if(temp->data == key){
            location[i++] = temp->index;
            (*j)++;
            found = 1;
        }
        temp = temp->n;
    }

    return found;
}

void menu(){
	printf("\n[1] Create List\n");
	printf("[2] Display List\n");
	printf("[3] Binary Search\n");
	printf("[4] Linear Search\n");
	printf("[5] Exit\n");
	printf("\nNOTE: If you generate a list after generating one, the previous list will be deleted.\n\n\n");
	printf("Enter: ");
}

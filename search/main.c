#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include "search.h"

int main(){
	int x, positions[10], j, i, num;	
	bool f = 1, key = 0;
	int ch;

	LIST *L = (LIST*) malloc(sizeof(LIST));
	L->head = NULL;
	L->tail = NULL;
	L->count = 0;
	int n = 0;

	while(f){
		printf("\n");
		menu();
		if(scanf("%d", &ch) != 1){
			printf("\nInvalid Input");
			
			int c;
        	while((c = getchar()) != '\n' && c != EOF);
			
			continue;
		}

		switch(ch){
		case 1:
		if(n==0){
			n = 1;
			generate(L);
			printf("\n List Generated");
		} else {
			destroy(L);
			generate(L);
			printf("\n Previous List Deleted");
			printf("\n New List Generated");
		}

		NODE *start = L->head;
		NODE *end = L->tail;
		qSort(L, start, end);
		break;

		case 2:
		printSort(L);
		break;
		
		case 3:
		if(n == 0){
			printf("\nGenerate List First");
			break;	
		}

		j = 0;
		printSort(L);
		printf("\n---Binary Search---\n");

		printf("\nEnter Number to Search: ");
		if(scanf("%d", &num) != 1){
			printf("\nInvalid Input");
			int c;
			while((c = getchar()) != '\n' && c != EOF);
			break;
		}

		key = binarySearch(L, num, positions, &j);
		if(!key){
			printf("\nData: %d Was Not Found", num);
		} else {
			for(i = 0; i < j; i++){
				printf("\nData: %d Found in Location %d", num, positions[i]);
			}
		}
		break;			    

		case 4:
		if(n == 0){
			printf("\nGenerate List First");
			break;	
		}

		j = 0;
		printSort(L);
		printf("\n\n---Linear Search---\n");

		printf("\nEnter Number to Search: ");
		if(scanf("%d", &num) != 1){
			printf("\nInvalid Input");
			int c;
			while((c = getchar()) != '\n' && c != EOF);
			break;
		}

		key = linearSearch(L, num, positions, &j);
		if(!key){
			printf("\nData: %d Not Found", num);
		} else {
			for(i = 0; i < j; i++){
				printf("\nData: %d Found in Location %d", num, positions[i]);
			}
		}
		break;
		
		case 5:
		f = 0;
		printf("\nGoodbye!");
		break;

		default:
		printf("\nInvalid Input");
		}
	}
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include "sort.h"
#include "list.h"

#define FALSE 0
#define TRUE  1

void menu();

int main(){
    int x, ch;
    int valid = 0;
    bool start = FALSE;

    LIST *L = (LIST*) malloc(sizeof(LIST));
    L->count = 0;
    L->head = NULL;
    L->tail = NULL;

    do{
        do{
            menu();

            if(scanf("%d", &ch) != 1){
                printf("Invalid input. Please enter a number 1-6.\n");
                while(getchar() != '\n');
            } else if(ch < 1 || ch > 6){
                printf("Invalid choice. Please enter a number 1-6.\n");
                while(getchar() != '\n');
            } else {
                while(getchar() != '\n');
                valid = 1;
            }
    
        }while(!valid);

        printf("\n\n");

        switch(ch){
            case 1:
                printf("Enter number of elements [10 MAX]: ");
                scanf("%d", &x);

                if(x > 1 && x <= 10){
                    createList(L, x);
                    printf("List Creation done...\n");
                    displayList(L->head);
                    start = TRUE;
                }else{
                    printf("Invalid input...\n");
                }
                break;

            case 2:
                if(start == TRUE){
                    displayList(L->head);
                }else{
                    printf("\nCreate List first...\n");
                }
                break;

            case 3:
                if(start == TRUE){
                    displayList(L->head);
                    printf("\nBUBBLE SORT\n");
                    bubbleSort(L);
                    displayList(L->head);
                }else{
                    printf("\nCreate List first...\n");
                }
                break;

            case 4:
                if(start == TRUE){
                    displayList(L->head);
                    printf("\nSELECTION SORT\n");
                    selectionSort(L);
                    displayList(L->head);
                }else{
                    printf("\nCreate List first...\n");
                }
                break;

            case 5:
                if(start == TRUE){
                    displayList(L->head);
                    printf("\nINSERTION SORT\n");
                    insertionSort(L);
                    displayList(L->head);
                }else{
                    printf("\nCreate List first...\n");
                }            
                break;

            case 6:
                printf("Goodbye...\n");
                break;

            default:
                printf("\nInvalid choice...\n");
                break;
        }

        getch();

    }while(ch != 6);

    free(L);

    return 0;
}

void menu(){
    printf("\nSORTING ALGORITHM\n");
    printf("[1] Create List\n");
    printf("[2] Display List\n");
    printf("[3] Bubble Sort\n");
    printf("[4] Selection Sort\n");
    printf("[5] Insertion Sort\n");
    printf("[6] Exit\n");
    printf("\nChoice: ");
}
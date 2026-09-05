#include "header.h"

int main(){
    STACK *stack = malloc(sizeof(STACK));
    stack->top = NULL;
    stack->count = 0;
    int num;

    printf("Enter an integer: ");
    
    if(scanf("%d", &num) != 1){
        printf("Invalid input. Please enter an integer.\n");
        free(stack);
        return 1;
    }

    if(num < 0){
        printf("Negative numbers are not supported.\n");
        free(stack);
        return 1;
    }

    decToHex(num, stack);

    free(stack);
    return 0;
}

#include "header.h"

void pop(STACK *stack){
    if(stack->count == 0){
        printf("Stack is empty.\n");
        return;
    }

    printf("%c", stack->top->data);
    stack->top = stack->top->next;
    stack->count--;
}

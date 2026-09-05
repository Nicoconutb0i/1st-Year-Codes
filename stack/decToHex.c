#include "header.h"

void decToHex(int num, STACK *stack){
    char hexChars[] = "0123456789ABCDEF";

    if(num == 0){
        printf("Hexadecimal of 0: 0\n");
        return;
    }

    int temp = num;

    while(temp > 0){
        int remainder = temp % 16;
        push(hexChars[remainder], stack);
        temp /= 16;
    }

    printf("Hexadecimal of %d: ", num);
    
    while(stack->count > 0){
        pop(stack);
    }

    printf("\n");
}

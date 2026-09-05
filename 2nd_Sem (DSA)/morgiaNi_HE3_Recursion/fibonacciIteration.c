#include "header.h"

void fibonacciIteration(int n){
    int a = 1, b = 1;

    printf("Fibonacci series using non-recursive function.\n\t");

    if(n == 0){
        printf("0\n");
        return;
    } else if(n < 0){
        printf("Error: Less than 0!\n");
        return;
    }

    for(int i = 1; i <= n; i++){
        printf("%d ", a);

        int next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

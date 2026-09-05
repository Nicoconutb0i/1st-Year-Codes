#include "header.h"

void factorialIteration(int n){
    int factorial = 1;
    printf("Factorial series using non-recursive function.\n\t");
    
    if(n == 0){
        printf("1\n");
        return;
    }

    for(int i = 1; i <= n; i++){
        factorial *= i;
        printf("%d ", factorial);
    }
    printf("\n");
}
#include "header.h"

int main(){
    int n;

    printf("Enter a value of n: ");
    scanf("%d", &n);

    if(n < 0){
        printf("Error: Less than 0!\n");
        return -1;
    }

    factorialIteration(n);
    printf("Factorial series using recursive function.\n\t");
    printf("%d ", factorialRecursive(n));
    printf("\n");
    fibonacciIteration(n);
    printf("Fibonacci series using recursive function.\n\t");
    
    if(n == 0){
        printf("0\n");
    }else{
        for (int i = 1; i <= n; i++) {
            printf("%d ", fibonacciRecursive(i));
        }
        printf("\n");
    }

    sumIteration(n);
    printf("Sum series using recursive function.\n\t");
    sumRecursive(n);
    printf("\n");
    
    return 0;
}
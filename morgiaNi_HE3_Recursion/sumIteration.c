#include"header.h"

void sumIteration(int n){
    int sum = 0;
    printf("Sum series using non-recursive function.\n\t");

    if(n == 0){
        printf("0\n");
        return;
    }

    for(int i = 1; i <= n; i++){
        sum += i;
        printf("%d ", sum);
    }
    printf("\n");
}
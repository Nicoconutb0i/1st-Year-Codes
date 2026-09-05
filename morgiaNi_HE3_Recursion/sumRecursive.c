#include"header.h"

int sumRecursive(int n){
    if(n == 0){
        printf("0 ");
        return 0;
    } else if(n == 1){
        printf("1 ");
        return 1;
    }

    int sum = n + sumRecursive(n - 1);
    printf("%d ", sum);

    return sum;
}
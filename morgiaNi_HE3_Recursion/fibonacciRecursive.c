#include "header.h"

int fibonacciRecursive(int n){
    if(n == 0){
        return 0;
    } else if(n == 1 || n == 2){
        return 1;
    }

    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}
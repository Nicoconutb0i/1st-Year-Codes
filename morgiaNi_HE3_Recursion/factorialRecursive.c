#include "header.h"

int factorialRecursive(int n){
    if(n == 0){
        return 1;
    }

    int result = n * factorialRecursive(n-1);

    return result;
}
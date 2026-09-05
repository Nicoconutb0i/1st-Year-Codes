/*
============================================================================
FILE : hashFunction.c
AUTHOR : Nicolas Paul T. Morgia
DESCRIPTION : Hash Function Implementation
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
============================================================================
FUNCTION : calcHSIZE
DESCRIPTION : Calculates the next prime number greater than or equal to n
ARGUMENTS : (list all parameters pass in the function)
int n - the number of data to be stored in the hash table
RETURNS : int n - the hsize which is the next prime number greater than or equal to the input n
===========================================================================
*/
int calcHSIZE(int n){
    bool nextprime = 0;
    int factor, i;
    
    while(!nextprime){
        factor = 0;
        n++;
        
        for(i = 1; i <= n; i++){
            if(!(n%i)){
                factor++;
            }
        }

        if(factor<=2){
            nextprime = 1;
        }
    }

    return n;
}

/*
============================================================================
FUNCTION : main
DESCRIPTION : Main function to demonstrate the hash function implementation
ARGUMENTS : None
RETURNS : int - exit status
===========================================================================
*/
int main(){
    int numData;
    printf("Number of Data: ");
    if(scanf("%d", &numData) != 1) return 1;

    int *inputs = malloc(numData * sizeof(int));
    printf("Input values: ");
    
    for(int i = 0; i < numData; i++){
        scanf("%d", &inputs[i]);
    }

    int hsize = calcHSIZE(numData);
    printf("\nHSIZE: %d\n", hsize);

    int *hashTable = malloc(hsize * sizeof(int));
    
    for(int i = 0; i < hsize; i++){
        hashTable[i] = -1; 
    }

    for(int i = 0; i < numData; i++){
        int value = inputs[i];
        int homeIndex = value % hsize;
        int index = homeIndex;

        while(hashTable[index] != -1){
            index = (index + 1) % hsize;
        }
        hashTable[index] = value;
    }

    printf("\nHash Table\n\n");
    printf("%-6s %s\n", "INDEX", "VALUE");

    for(int i = 0; i < hsize; i++){
        if(hashTable[i] != -1){
            printf("%-6d %d\n", i, hashTable[i]);
        }else{
            printf("%-6d\n", i);
        }
    }

    free(inputs);
    free(hashTable);

    return 0;
}
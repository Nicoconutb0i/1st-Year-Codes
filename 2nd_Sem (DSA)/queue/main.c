#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

int main() {
    char input[100];
    QUEUE* q = createQueue();
    char temp;
    int length = 0;

    printf("Enter a string: ");
    if (fgets(input, sizeof(input), stdin)) {
        input[strcspn(input, "\n")] = '\0'; // Clean input

        // Process: Enqueue each character
        for (int i = 0; input[i] != '\0'; i++) {
            if (!enqueue(q, input[i])) {
                printf("Error: Overflow at '%c'\n", input[i]);
                break;
            }
        }

        // Process: Dequeue to count length
        while (!isEmpty(q)) {
            if (dequeue(q, &temp)) {
                length++;
            }
        }

        printf("The string length is: %d\n", length);
    }

    free(q);
    return 0;
}

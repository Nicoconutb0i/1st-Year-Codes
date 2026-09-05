#include <stdio.h>
#include <math.h>

int main() {
    int operation;

    do {
        printf("\n===== MENU =====\n");
        printf("[1] Power Problem Solver\n");
        printf("[2] Factorial Problem Solver\n");
        printf("[3] Quadratic Equation Solver\n");
        printf("[4] Quit\n");
        printf("Choose an operation: ");
        scanf("%d", &operation);

        if (operation == 1) {
            double base, exp;
            printf("Enter base: ");
            scanf("%lf", &base);
            printf("Enter exponent: ");
            scanf("%lf", &exp);

            printf("Answer: %.2lf\n", pow(base, exp));

        } else if (operation == 2) {
            int n, factorial = 1;
            printf("Enter a non-negative integer: ");
            scanf("%d", &n);

            if (n < 0) {
                printf("Factorial is not defined for negative numbers.\n");
            } else {
                for (int i = 1; i <= n; i++) factorial *= i;
                printf("Answer: %d\n", factorial);
            }

        } else if (operation == 3) {
            double a, b, c, discriminant;
            printf("Enter a, b, and c: ");
            scanf("%lf %lf %lf", &a, &b, &c);

            if (a == 0 && b == 0) {
                printf("No solution.\n");
            } else if (a == 0) {
                printf("One root: %.2lf\n", -c / b);
            } else {
                discriminant = b * b - 4 * a * c;
                if (discriminant < 0) {
                    printf("No real roots.\n");
                } else {
                    printf("Roots: %.2lf and %.2lf\n",
                           (-b + sqrt(discriminant)) / (2 * a),
                           (-b - sqrt(discriminant)) / (2 * a));
                }
            }

        } else if (operation != 4) {
            printf("Invalid choice. Try again.\n");
        }

    } while (operation != 4);

    printf("Exiting program.\n");

    return 0;
}

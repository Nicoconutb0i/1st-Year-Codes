#include<stdio.h>
#include<math.h>

void displayMenu();
int powerSolver(int, int);
int factorialSolver(int num);
int quadraticSolver(int a, int b, int c);

double root1, root2;

int main(){

    int result, operation;

    do{
        displayMenu();

        printf("Choose an operation: ");
        scanf("%d", &operation);

        switch(operation){

        case 1:
            int base, exp;

            printf("Enter base: ");
            scanf("%d", &base);
            printf("Enter exponent: ");
            scanf("%d", &exp);

            result = powerSolver(base, exp);
            printf("Answer: %d\n", result);
            break;

        case 2:
            int n;
            printf("Enter a non-negative integer: ");
            scanf("%d", &n);

            if (n < 0) {
                printf("Factorial is not defined for negative numbers.\n");
            } else {
                result = factorialSolver(n);
                printf("Answer: %d\n", result);
            }
            break;

        case 3:
            int a, b, c;
            printf("Enter a, b, and c: ");
            scanf("%d %d %d", &a, &b, &c);

            if (a == 0 && b == 0) {
                printf("No solution.\n");
            } else if(a == 0) {
                printf("One root: %.2f\n", -(float)c / b);
            } else {
                result = quadraticSolver(a, b, c);
                if(result == 0){
                    printf("No Real Roots\n");
                } else {
                    printf("Roots: %.2lf and %.2lf\n", root1, root2);
                }
            }
            break;

        case 4:
            printf("Exiting Program...\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }

    }while(operation != 4);

    return 0;
}

void displayMenu(){
    printf("\n===== MENU =====\n");
    printf("[1] Power Problem Solver\n");
    printf("[2] Factorial Problem Solver\n");
    printf("[3] Quadratic Equation Solver\n");
    printf("[4] Quit\n");
}

int powerSolver(int base, int p){
    return pow(base, p);
}

int factorialSolver(int num){
    int factorial = 1;
    for (int i = 1; i <= num; i++) factorial *= i;
    return factorial;
}

int quadraticSolver(int a,  int b, int c){
    float discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return 0;
    } else {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        return 1;
    }
}

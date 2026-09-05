#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, discriminant, root1, root2;

    printf("Enter a, b and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if(a == 0 && b == 0) {
        printf("No solution.\n");
    } else if(a == 0) {
        double root = -c / b;
        printf("One root: %.2lf", root);
    } else {
        discriminant = b * b - 4 * a * c;

        if(discriminant < 0) {
            printf("No real roots.");
        } else {
            root1 = (-b + sqrt(discriminant)) / (2 * a);
            root2 = (-b - sqrt(discriminant)) / (2 * a);
            printf("Two roots: %.2lf and %.2lf", root1, root2);
        }
    }

    return 0;
}

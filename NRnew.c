#include <stdio.h>
#include <math.h>

#define f(x) (3 * x - cos(x) - 1)
#define g(x) (3 + sin(x))

int main() {
    float x, y, f1, g, e = 0.00001;
    int max_iterations = 100;  // Prevent potential infinite loop

    // Get initial value from user
    printf("Enter the Initial Value: ");
    scanf("%f", &x);

    for (int iteration = 1; iteration <= max_iterations; iteration++) {
        f1 = f(x);
        g = g(x);

        if (g == 0.0) {
            printf("Mathematical Error: g(x) cannot be zero.\n");
            return 1;  // Indicate error
        }

        y = x - (f1 / g);
        x = y;

        printf("For iteration %d, The value of x is %f\n", iteration, x);

        if (fabs(f1) <= e) {
            printf("\nRoot is: %f\n", y);
            return 0;  // Indicate successful convergence
        }
    }

    printf("\nFailed to converge within %d iterations.\n", max_iterations);
    return 1;  // Indicate failure to converge
}

#include <stdio.h>
#include <math.h>

// Define the function f(x) using a proper function definition
float f(float x) {
    return x * log10(x) + pow(e,x)* sin(x) - 2.5;
}

int main() {
    float a, b, x, fa, fb, fx, e;

    up:
    printf("Enter two initial guesses:\n");
    if (scanf("%f%f", &a, &b) != 2) {
        printf("Invalid input. Please enter two numbers.\n");
        goto up;
    }

    printf("Enter tolerable error:\n");
    if (scanf("%f", &e) != 1) {
        printf("Invalid input. Please enter a positive number.\n");
        goto up;
    }

    fa = f(a);
    fb = f(b);

    if (fa * fb > 0) {
        printf("Wrong initial guesses.\n");
        goto up;
    }

    do {
        x = (a * fb - b * fa) / (fb - fa);
        fx = f(x);

        if (fabs(fx) <= e) { // Check for convergence within tolerance
            break;
        }

        if (fa * fx < 0) {
            b = x;
            fb = fx;
        } else {
            a = x;
            fa = fx;
        }

    } while (true); // Replace "while (fabs(fx) > e)" to prevent infinite loop

    printf("\nRoot is: %.5f\n", x);

    return 0;
}

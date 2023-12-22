//#include <stdio.h>
//#include <math.h>
//
//#define f(x) x * sin(x) - 1
//
//int main() {
//    float a, b, x;
//    float fa, fb, fx, e;
//
//    printf("Enter the two guesses: ");
//    scanf("%f%f", &a, &b);
//
//    printf("Enter the error: ");
//    scanf("%f", &e);
//
//    fa = f(a);
//    fb = f(b);
//
//    if (fa * fb > 0) {
//        printf("Invalid initial guess\n");
//        return 1;  // Return an error code
//    }
//
//    do {
//        x = (a + b) / 2;
//        fx = f(x);
//
//        if (fa * fx < 0) {
//            b = x;
//            fb = fx;
//        } else {
//            a = x;
//            fa = fx;
//        }
//
//    } while (fabs(fx) > e);
//
//    printf("\nRoot is: %f\n", x);
//
//    return 0;
//}


#include <stdio.h>
#include <math.h>

#define f(x) x * sin(x) - 1

int main() {
    float a, b, x;
    float fa, fb, fx, e;

    printf("Enter the two guesses: ");
    scanf("%f%f", &a, &b);

    printf("Enter the error: ");
    scanf("%f", &e);

    fa = f(a);
    fb = f(b);

    if (fa * fb > 0) {
        printf("Invalid initial guess\n");
        return 1;  // Return an error code
    }

    printf("\n%-15s%-15s%-15s%-15s\n", "Iteration", "a", "b", "Root");

    int iteration = 1;

    do {
        x = (a + b) / 2;
        fx = f(x);

        printf("%-15d%-15f%-15f%-15f\n", iteration, a, b, x);

        if (fa * fx < 0) {
            b = x;
            fb = fx;
        } else {
            a = x;
            fa = fx;
        }

        iteration++;

    } while (fabs(fx) > e);

    printf("\nRoot is: %f\n", x);

    return 0;
}

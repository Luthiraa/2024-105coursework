#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

double randDouble() {
    return (double)rand() / ((double)RAND_MAX);
}

bool inBounds(double x, double y) {
    return (x * x + y * y) <= 1.0;
}

int main(void) {

    double pi;
    double iterations;
    int numIn = 0; // Initialize numIn to 0
    srand(42);// seed 42
    printf("Number of monte carlo iterations: ");
    scanf("%lf", &iterations);

    for (int i = 0; i < iterations; i++) {
        double x = randDouble();
        double y = randDouble();
        if (inBounds(x, y)) {
            numIn++;
        }
    }

    pi = 4.0 * numIn / iterations; // Ensure at least one operand is a double for accurate division
    printf("Pi: %.4lf\n", pi);

    return 0;
}

// Number of monte carlo iterations: <enter>10<enter>
// Pi: 3.6000

// Number of monte carlo iterations: <enter>100000<enter>
// Pi: 3.1374

// 1. gcc lab4part1.c -o lab4part1
// 2. ~aps105i/public/exercise 4 lab4part1


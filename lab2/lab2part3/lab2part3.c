#include <stdio.h>
#include <math.h>

#define k 8.9875e9

int main(void) {
    char q1[10], q2[10], outUnits[2], q1unit[2], q2unit[2];

    double q1D, q2D, force, d;

    printf("Enter the value of the two charges separated by a space: ");
    scanf("%s %s", q1, q2);
    printf("Enter distance between charges in metres: ");
    scanf("%lf", &d);

    sscanf(q1, "%lf%1s", &q1D, q1unit);
    sscanf(q2, "%lf%1s", &q2D, q2unit);

    // Convert all units to Coulombs
    if (q1unit[0] == 'u' ) {
        q1D *= 1e-6;  // convert micro to C
    } else if (q1unit[0] == 'n') {
        q1D *= 1e-9;  // convert nano to C
    }

    if (q2unit[0] == 'u') {
        q2D *= 1e-6;  // convert micro to C
    } else if (q2unit[0] == 'n') {
        q2D *= 1e-9;  // convert nano to C
    }

    // Calculate the force using Coulomb's Law
    force = k * fabs(q1D * q2D) / (d * d);

    // Output the force with the appropriate units
    if (force < 1e-6) {
        printf("The force between charges is %.2lfnN (less than 1uN)", force * 1e9);
    } else if (force < 1e-3) {
        printf("The force between charges is %.2lfuN (less than 1mN)", force * 1e6);
    } else if (force < 1) {
        printf("The force between charges is %.2lfmN (less than 1N)", force * 1e3);
    } else {
        printf("The force between charges is %.2lfN (1N or greater)", force);
    }

    return 0;
}


// Enter the value of the two charges separated by a space: 2nC 3uC<enter>
// Enter distance between charges in metres: 2<enter>
// The force between charges is 13.48uN (less than 1mN)

// Enter the value of the two charges separated by a space: 3.2nC -7.2nC<enter>
// Enter distance between charges in metres: 13.78<enter>
// The force between charges is 1.09nN (less than 1uN)


// gcc lab2part3.c -o lab2part3 -lm
// 2. ~aps105i/public/exercise 2 lab2part3
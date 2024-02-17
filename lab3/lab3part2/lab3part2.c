#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main(void) {
    int d, H;
    double alpha = 0;
    double radAlpha;
    const int v = 20;
    const double g = 9.81;
    const int l = 2;
    double y, t;
    double degToRad = PI / 180.0;

    do {
        printf("Please enter the horizontal distance from the wall between 3 and 30 m:\n");
        scanf("%d", &d);
    } while (!(d >= 3 && d <= 30));


    do {
        printf("Please enter the target height between 3 and 6 m:\n");
        scanf("%d", &H);
    } while (!(H >= 3 && H <= 6));

    while (alpha <= 90) {
        radAlpha = alpha * degToRad;
        t = d / (v * cos(radAlpha));
        y = l + (v * sin(radAlpha) * t) - (0.5 * g * t * t);

        if (fabs(y - H) <= 0.3) {
            printf("The angle should be %.2lf\n", alpha);
            break;
        }
        alpha++;
    }

    return 0;
}

// Example 1:
// Please enter the horizontal distance from the wall between 3 and 30 m:
// 4<enter>
// Please enter the target height between 3 and 6 m:
// 6<enter>
// The angle should be 46.00

// gcc lab3part2.c -o lab3part2 -lm
// 2. ~aps105i/public/exercise 3 lab3part2

#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define G 6.6726e-11

int main(void) {
    
    float circumference, acceleration, velocity, mass, radius;
    printf("Circumference (km) of planet? ");
    scanf("%f", &circumference);
    printf("Acceleration due to gravity (m/s^2) on planet? ");
    scanf("%f", &acceleration);
    printf("\nCalculating the escape velocity...\n");

    radius = circumference / (2 * PI);
    mass = (acceleration * (radius * radius)) / G;
    velocity = sqrt(2*(G * (((acceleration/1000) * (radius * radius))/ G) ) / radius);

    printf("Planet radius: %0.1f km\n", radius);
    printf("Planet mass: %0.1f x 10^21 kg\n", mass / 1e15);
    printf("Escape velocity: %0.1f km/s\n", velocity);
    return 0;
}


// gcc lab1part3.c -o lab1part3 -lm
// ~aps105i/public/exercise 1 lab1part3
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main(void){
    double sideA, sideB,sideC, angleAlpha, angleBeta, angleGamma,val,degToRad;
    printf("Enter the length of side A: ");
    scanf("%lf", &sideA);
    printf("Enter the length of side B: ");
    scanf("%lf",&sideB);
    printf("Enter the measure of angle alpha in degrees: ");
    scanf("%lf", &angleAlpha);
    printf("\nResults: \n");

    degToRad = PI/180;
    val = 180.0/PI;
    angleBeta = (asin((sideB*sin(angleAlpha * degToRad))/sideA))*val;
    angleGamma = 180 - angleAlpha - angleBeta;
    sideC = (sideA * sin(angleGamma * degToRad))/sin(angleAlpha*degToRad);

    printf("Side A: %0.2f",sideA);
    printf("\nSide B: %0.2f",sideB);
    printf("\nSide C: %0.2f",sideC);
    printf("\nAngle Alpha: %0.2f degrees",angleAlpha);
    printf("\nAngle Beta: %0.2f degrees",angleBeta);
    printf("\nAngle Gamma: %0.2f degrees",angleGamma);

    return 0;
    
}



// . gcc lab2part1.c -o lab2part1 -lm
// 2. ~aps105i/public/exercise 2 lab2part1

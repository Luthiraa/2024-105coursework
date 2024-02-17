#include <stdio.h>

int main(void){
    double FTemp,CTemp,diff22;
    printf("Enter the thermostat temperature: ");
    scanf("%lf", &FTemp);
    CTemp = (FTemp - 32)/1.8;
    printf("The temperature in Celsius is: %0.1lf\n",CTemp);
    diff22 = ((CTemp - 22)*1.8); // +32????
    printf("You are %0.1lf degrees Fahrenheit away from a nice 22 degrees Celsius.",diff22);
    return 0;
}
// 1. gcc lab1part2.c -o lab1part2
// 2. ~aps105i/public/exercise 1 lab1part2


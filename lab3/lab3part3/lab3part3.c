#include <stdio.h>
#include <math.h>

double function(double x) {
    return exp(-pow(x,2));
}
// midpoint approximation !!!!!!!!!!!!!!!!!
int main (void){
    int n; 
    double a,b;
    printf("Please enter the number of rectangles (n): ");
    scanf("%d",&n);
    do {
 
        printf("Please enter the interval of integration (a b): ");
        scanf("%lf %lf", &a,&b);
        if (a>b){
            do{ 
                printf("Invalid interval!\n");
                printf("Please enter the interval of integration (a b): ");
                scanf("%lf %lf", &a,&b);
            }while (a>b);
        }
 
        double deltaX = (b-a)/n;
        double sum = 0;
        double x = a;
        while (x<b){
            double xkstar = x + 0.5 * deltaX;
            sum += deltaX * function(xkstar);
            x += deltaX;
        }
        printf("The integral of e^-x^2 on [%.5lf, %.5lf] with n = %d is: %.5lf\n",a,b,n,sum);

        printf("Please enter the number of rectangles (n): ");
        scanf("%d",&n);
    }while (n>=1);
    printf("Exiting.");

    return 0;
}


//  gcc lab3part3.c -o lab3part3 -lm
// 2. ~aps105i/public/exercise 3 lab3part3
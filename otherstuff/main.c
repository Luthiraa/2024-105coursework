// Goldenbach's conjecture

// Every even integer greater than 2 can be expressed as the sum of two prime numbers.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}
int main (void){
    int n; 
    do{
        printf("Enter an even number greater than 2: ");
        scanf("%d", &n);
    }while(n < 2 || n % 2 != 0);
    
    for (int i = 2; i <= n / 2; i++){
        if (is_prime(i) && is_prime(n - i)){
            printf("%d = %d + %d\n", n, i, n - i);
        }
    }
}

#include <stdio.h>
#include <math.h>

int main(void){
    int num, count = 0, rotations = 0; 
    printf("Number pls: ");
    scanf("%d", &num);
    printf("Rotations: ");
    scanf("%d", &rotations);
    int i = num; 
    while (i != 0){
        i /= 10;
        count++;
    }
    int temp = 0;
    for (int i = 0; i < rotations; i++){
        temp = num % 10;
        num /= 10; 
        num = num + temp * pow(10, count - 1);
        printf("%d\n", num);
    }
    return 0;
}
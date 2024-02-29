#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int dotProduct(int arrA[], int arrB[]);

int main(void){
    
    int rows=0 ;
    printf("Amount of rows: ");
    scanf("%d", &rows);

    for (int i = 1; i<=rows; i++){
        for (int j = 1; j<=((rows*2)-1); j++){
            if (j==1||j==(rows*2)-1||i==1||i==rows||i+j==rows+1||j-i==rows-1){
            printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
}
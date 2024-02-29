#include <stdio.h>

int main(void){
    int rows;
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    for (int i =0; i<=i; i++){
        for (int j = 0; j<=i;j++ ){
            printf(" ");
        }
        for (int j=i;j<=rows; j++){
            printf("*");
        }
        for (int j =i ; j<rows; j++){
            printf("*");
        }
        printf("\n");
    }


}
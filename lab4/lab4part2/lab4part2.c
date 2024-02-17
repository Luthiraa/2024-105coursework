#include <stdio.h>
#include <stdlib.h>

int num7s(int num){
    int count=0;
    num = abs(num);
    while (num){
        if (num % 10 == 7){
            count++;
        }
        num /= 10;
    }
    return count;
}

int main (void) {
    int num;
    int luckyNums =0; 
    printf("Input an integer: ");
    scanf("%d", &num);
    while (num!=0){
        if (num7s(num) == 3){
            luckyNums++;
        }
        printf("Input an integer (0 to stop): ");
        scanf("%d", &num);
    }
    printf("You entered %d lucky number(s)!\n", luckyNums);


}


// Input an integer: 71237<enter>
// Input an integer (0 to stop): 717717<enter>
// Input an integer (0 to stop): 1727378<enter>
// Input an integer (0 to stop): -1742797<enter>
// Input an integer (0 to stop): 0<enter>
// You entered 2 lucky number(s)!


//  gcc lab4part2.c -o lab4part2
// 2. ~aps105i/public/exercise 4 lab4part2
#include <stdio.h>

int main(void)
{
    char userSign;
    int userNum;
    int sum = 0;

    printf("Enter sequence of numbers to add: ");

    do
    {
        scanf(" %c%d", &userSign, &userNum);

        if (userSign == '-')
        {
            sum -= userNum;
            printf("Sum is updated to %d\n", sum);
        }
        else if (userSign == '+')
        {
            sum += userNum;
            printf("Sum is updated to %d\n", sum);
        }
    } while (sum >= 0);

    printf("Sum fell below zero.\n");

    return 0;
}

// Enter sequence of numbers to add: <enter>+9<enter>
// Sum is updated to 9
// -2<enter>
// Sum is updated to 7
// +7<enter>
// Sum is updated to 14
// -9<enter>
// Sum is updated to 5
// -9<enter>
// Sum is updated to -4
// Sum feel below zero.



// . gcc lab3part1.c -o lab3part1
// 2. ~aps105i/public/exercise 3 lab3part1
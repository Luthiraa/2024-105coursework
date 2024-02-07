#include <stdio.h>
#include <math.h>

int main(void) {
    int departH, departM, arrivalH, arrivalM, tripHours, tripMinutes;
    double tripTime, totalTime;

    printf("Enter current time: ");
    scanf("%d %d", &departH, &departM);
    printf("Enter trip time: ");
    scanf("%lf", &tripTime);

    tripHours = (int)tripTime;
    tripMinutes = (int)((tripTime - tripHours) * 60);

    arrivalH = departH + tripHours;
    arrivalM = departM + tripMinutes;

    if (arrivalM >= 60) {
        arrivalH += arrivalM / 60;
        arrivalM %= 60;
    }

    if (arrivalH >= 24) {
        arrivalH %= 24;
    }

    printf("\nCurrent time is %02d:%02d\n", departH, departM);

    if (arrivalH < departH || (arrivalH == departH && arrivalM < departM)) {
        printf("Arrival Time is next day %02d:%02d\n", arrivalH, arrivalM);
    } else {
        printf("Arrival Time is same day %02d:%02d\n", arrivalH, arrivalM);
    }

    return 0;
}


// gcc lab2part2.c -o lab2part2
// 2. ~aps105i/public/exercise 2 lab2part2
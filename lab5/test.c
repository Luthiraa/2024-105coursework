#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

bool get_decision(void){
    int yOrN; 
    printf("Decide now (0 for no, 1 for yes): ");
    scanf("%d", &yOrN); 

    while (yOrN!=0 && yOrN!=1) {
        printf("Decide now (0 for no, 1 for yes): ");
        scanf("%d", &yOrN); 
    }
    return yOrN; 
}

int pick_case_index(int cases[], int cases_size) {
    int caseNum; 
    for (int i = 0; i < cases_size; i++){
        if (cases[i] != -1) {
            printf("%d\n", i + 1);
        }
    }
    printf("Pick a case: ");
    scanf("%d", &caseNum); 

    while (caseNum < 1 || caseNum > cases_size || cases[caseNum - 1] == -1) {
        printf("Pick a case: ");
        scanf("%d", &caseNum);
    }

    return caseNum - 1;
}

int cases_average(int cases[], int cases_size,int initial_amount){
    int sum=0;
    for (int i=0; i<cases_size+1;i++){
        sum+=cases[i];
    }
    int average = (sum+initial_amount)/cases_size; 
    return average;
}

void eliminate_cases(int cases[], int cases_size, int eliminated) {
    printf("Eliminating %d cases.\n", eliminated);

    for (int i = 0; i < eliminated; i++) {
        int caseIndex = pick_case_index(cases, cases_size);
        int amount = remove_case_and_get_amount(cases, cases_size, caseIndex);
        printf("Eliminated case %d with amount %d.\n", caseIndex + 1, amount);
    }
}

int main () {
    int cases[] = {
        0,
        1,
        5,
        10,
        25,
        50,
        75,
        100,
        200,
        300,
        400,
        500,
        750,
        1000,
        5000,
        10000,
        25000,
        50000,
        75000,
        100000,
        200000,
        300000,
        400000,
        500000,
        750000,
        1000000,
    };
    int caseSize = ARRAY_SIZE(cases);

    printf("%d",pick_case_index(cases, caseSize));
}
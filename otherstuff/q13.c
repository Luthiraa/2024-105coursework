#include <stdio.h>
#include <stdbool.h>
int sortTemp(int temp[], int size);

int main(void) {
    int temp[7] = {5, 4, 10, 11, 11, 10, 4};
    printf("\nThe lowest temperature is %d\n", sortTemp(temp, 7));
    return 0;
}

int sortTemp(int temp[], int size) { 
    int histogram [12] = {0}; 

    for(int i = 0; i<size; i++){
        (histogram[temp[i]])++;
    }

    for(int i = 0; i<12; i++){
        printf("%d, ", histogram[i]);
    }

    //sort 
    bool sorted = false; 
    while (!sorted){
        bool swapped = false;
        for (int i = 0; i<size; i++){
            int x = temp[i];
            if (temp[i]>temp[i+1]){
                temp[i] = temp[i+1]; 
                temp[i+1] = x;
                swapped = true; 
            }
        }
        sorted = true;
    }

    return temp[0]; 
}
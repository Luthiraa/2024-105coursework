#include <stdio.h>
#include <stdbool.h>

int main(void){
    int arr[] = {1,2,4,532,1,4,3,2,4,5,33,52,34,6,2,1};
    bool sorted = false; 
    int sizeArr = sizeof(arr)/sizeof(arr[0]);
    while (!sorted){
        bool swapped = false; 
        for (int i = 0; i < sizeArr - 1; i++){  
            int temp = arr[i]; 
            if (arr[i] > arr[i+1]){
                arr[i] = arr[i+1]; 
                arr[i+1] = temp; 
                swapped = true;  
            }
        }
        sorted = !swapped; 
    }
    for (int i = 0; i < sizeArr; i++){
        printf("%d , ", arr[i]);
    }
}
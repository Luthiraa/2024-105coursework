#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//searching and sorting

//if unsorted you have to do a linear search through entire array

//*binary search algorithm
//! try to do this recursively
//1. sort the array
//2. find the middle element
//3. if the middle element is the target, return the index
//4. if the middle element is less than the target, search the right half
//5. if the middle element is greater than the target, search the left half
//6. repeat until the target is found or the left index is greater than the right index

int binarySearch(int arr[], int size, int target){
    int left = 0;
    int right = size - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return -1;
}


//* bubble sort 
//1. compare the first two elements
//2. if the first element is greater than the second element, swap them
//3. move to the next element
//4. repeat until the end of the array
//5. repeat the process until no swaps are made

// int * bubbleSort(int arr[], int size){
//     //create a copy of the array
//     int sorted [] = malloc(size * sizeof(int));
//     //copy the array
//     for(int i = 0; i < size; i++){
//         sorted[i] = arr[i];
//     }
//     //`swapped` is a flag to check if any swaps were made
//     int swapped = 1;
//     while(swapped){
//         swapped = 0;
//         for(int i = 0; i < size - 1; i++){
//             if(sorted[i] > sorted[i + 1]){
//                 int temp = sorted[i];
//                 sorted[i] = sorted[i + 1];
//                 sorted[i + 1] = temp;
//                 swapped = 1;
//             }
//         }
//     }
//     return sorted;
// }

void bubbleSortVoid(int list[],int size){
    int temp;
    bool isSorted = false; //flag to check if any swaps were made
    //iteratre through the array
    for (int top=size-1; top>=1 && !isSorted; top--){
        isSorted = true; 
        //swapping per iteration
        for (int j=0; j<top; j++){
            //if the current element is greater than the next element, swap them
            if (list[j] > list[j + 1]){
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
                isSorted = false;
            }
        }
    }

    for (int i = 0; i < size; i++){
        printf("%d ", list[i]);
    }
}


int main(void){
    int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%d\n", binarySearch(list, 10, 5));
    int unsortedList[] = {243,43,2,34,2,4,52,23,5,99};
    // int * sortedArray = bubbleSort(unsortedList, sizeof(unsortedList)/sizeof(int));
    // for (int i = 0; i < 10; i++){
    //     printf("%d ", sortedArray[i]);
    // }
    bubbleSort(unsortedList, sizeof(unsortedList)/sizeof(int));
}
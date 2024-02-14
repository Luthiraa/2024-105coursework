//Write a program tha reverses order of elemnts in an array 
#include <stdio.h>

//Steps:
//low = 0 , high = SIZE - 1
// swap array [low] <-> array [high]
//low++, high --
//repeat (2-3) until low >= high
#define SIZE 6
int main (void){
    int arr[SIZE] = {1,2,3,4,5,6};
   
    int high = SIZE-1;
    int temp; 
    for(int low = 0;low>=high;low++, high-- ){
        temp = arr[low];
        arr[low] = arr[high];
        arr[high]=temp;
        printf("The array is:%d", arr[low]);
    }
    

}


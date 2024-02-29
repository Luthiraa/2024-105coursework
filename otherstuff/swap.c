#include <stdio.h>

int main(void){
    int arr[]={1,2,3,4,5,6}; 

    int arrSize= sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i<arrSize/2; i++){
        int temp = arr[i];
       arr[i] = arr[arrSize-1-i];
        arr[arrSize-1-i]=temp; 

    }
    for(int i = 0; i<arrSize; i++){
        printf("%d , ", arr[i]);
    }
}
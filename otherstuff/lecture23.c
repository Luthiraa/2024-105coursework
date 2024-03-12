#include <stdio.h>

// malloc for 2d arrays
//1. dynamically allocate 1d array for each row -- stored as a pointer
//2. dynamically allocate 1d array to store pointers to each 1d row, previously stored -- stored as a pointer to a pointer aka a pointer pointer
        //where each ptr in this array points to the first element og the first 1d array

//example 2x3 2d array 
int main(void){ 
    //typecast to int** b/c it points to a pointer (implicitly done but good practise)
    int** arr = (int**)malloc(2*sizeof(int*)); // 2 of size (int *)

    //malloc for each row, so in this case we have 2 rows of 3 elements
    for(int i = 0;i<2;i++){
        arr[i]=malloc(3*sizeof(int)); //or *(arr + i)
    }
    //access and change elements inside the array
    for (int i =0; i<2;i++){
        for(int j=0; j<3;j++){
            arr[i][j]=1;
            // or *(*(arr+i)+j) this is beacuse you deference the pointer to the row which is stored in teh first array and then deferencence everthing to getthe value stored at [i][j]
        }
    }
    for (int i =0; i<2;i++){
        for(int j=0; j<3;j++){
            printf("%d\n", arr[i][j]);
        }
    }
    // Free the dynamically allocated memory
    for (int i = 0; i < 2; i++) {
        free(arr[i]);
        arr[i] = NULL;
    }
    free(arr);
    arr=NULL;
}
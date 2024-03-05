#include <stdlib.h>
#include <stdio.h>

int main(void){
	int numOfStudents; 
	printf("Enter the number of students: ");
	scanf("%d", &numOfStudents);

    int *arr = (int*)malloc(numOfStudents * sizeof(int));
		// malloc returns a pointer takes in size to be allocated, in the heap,
        // so in this case numOfStudents x size in bytes for the size of an integer, 
        //if unsuccessful returns null
		printf("Enter marks: " );
	for(int i = 0; i<numOfStudents; i++){
		scanf(" %d", &arr[i]); //input for each mark and store it in the newly allocated memory for arr
	}
    free(arr); //free the memory in the heap and takes in the arguemnt for the first element in the array;
    arr = NULL;
}
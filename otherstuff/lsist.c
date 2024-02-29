#include <stdio.h>

void listMan(int* list, int size){
    for (int i =0; i<size; i++){
        printf("%d ", list[i]);
    }
}

int main(void){
    int list []= {1,2,3,4};
    int size = sizeof(list)/sizeof(list[0]);
    listMan(list, size);
    return 0;
}
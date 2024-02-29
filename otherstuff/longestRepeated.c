#include <stdio.h>

int longestRepeatedLength(int list[], int size) {

    int count = 1;
    int maxCount = 0;
    for (int i=0; i<size-1;i++){
         
        if (list[i]==list[i+1]){
            count+=1;
        }else{
            if (count > maxCount) {
                maxCount = count;
            }
            count=1;
        }
    }
    if (count > maxCount) {
        maxCount = count;
    }
    printf("%d",maxCount);
    return maxCount;
}
int main(void){
    int list [] = {1,2,3,4,4,4,5,5,5,5,5,5,6,6,6};
    int size = sizeof(list) / sizeof(list[0]);
    longestRepeatedLength(list, size);
}
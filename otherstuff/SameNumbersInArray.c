#include <stdio.h>
#include <stdbool.h>

bool sameNums(int *a, int *b){

    
    for (int i =0; a[i]!=-1;  i++){
        bool found = false;
        for (int j =0;b[j]!=-1;j++){
            if (a[i]==b[j]){
                found=true;
                break;
            }
        }
        if (!found){
            return false;
        }

    }
    
   return true;
}

int main(void){
    int a[] = {1,2,3,4,5,-1};
    int b[] = {5,4,3,2,1,-1};
    sameNums(a,b);
    return 0;
}
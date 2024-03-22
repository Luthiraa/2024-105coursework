#include <stdio.h>

//recursion cont'd

//printing a row of stars recursivly
void printStars(int n ){
    if (n==1 ){
        printf("*\n");
    }else{
        printf("*");
        printStars(n-1);
    }
//after the final function call of printStar(1), it goes back to teh previous call which was printStar(2) and it returns 
//it does the same thing for printStar(2) and printStar(3). This is done to clear the stack for all function calls 
}

//print the following pattern recursivley 
// *****
// ****
// ***
// **
// *
// *
// **
// ***
// ****
// *****
//printPatter(5)
//5 stars
//printPatten(4)
//5 stars
void printPattern(int n){
    if (n>0){
        printStars(n);
        printPattern(n-1);
        printStars(n);
    } 
    //no base case beacuse if n<=0, we do nothing
}

//!trace code above 

int main(void){
    printStars(3);
    printPattern(5);
    return 0; 
    
}
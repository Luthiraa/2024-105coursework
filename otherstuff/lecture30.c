#include <stdio.h>
#include <stdbool.h>

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
//! for exams will be either pattern or array

//* for strings: 
    //palindrome radar same foward and backward
//recursive function to determine if a word is a palindrome or not 
bool isPalindrome(char * word){
    int length = strlen(word);
    if (length <= 1) {// the base case is when the length of the word is 1 
        return true; 
    } else {
        if (word[0] == word[length - 1]) {
            // First and last characters match, check if the substring is a palindrome
            word[length - 1] = '\0'; // Remove last character
            return isPalindrome(word + 1);
        } else {
            return false; // Not a palindrome
        }
    }
} 

//salma explaination 

bool checkPalindrome(char * word, int low, int high ){
    int low = 0, high = strlen(word)-1;
    if (word[low]!=word[high]){
        return false;
    }else{
        return checkPalindrome(word, low+1,high-1);
    }
}

//!trace aswell 
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, world! This is a test string.";
    char *substring = "world";

    // Find the first occurrence of substring in str
    char *result = strstr(str, substring);

    if (result != NULL) {
        printf("Substring found at index: %ld\n", result - str);
    } else {
        printf("Substring not found\n");
    }

    return 0;
}


#include <stdio.h>
#include <stdlib.h>

//introduction to strings

int main (void){
    //in C a sting is null (\0), ASCII code of 0 -terminalted array of characters

    // method #1
    //Declare and initialize a string
    char myString []=  "Hello";
    //or 
    // char myString [s+1]= "Hello";   - where s is the number of characters and +1 is the null terminator
    // char myString [8] = "Hello"; the remaining 3 (empty elemnts) would be null characters (\0)
    //stored in the stack ******
    // char *p = myString;



    //method #2

    char *p = "WOW"; // "WOW" is stored in the global variables / constants section in the memory stored as a character array {'W','O','W','\0'}
    // ^cannot change the string at all b/c it is a constant string

    //p is a pointer that stores the address of the 1st element of the constant string "WOW"
    printf("%s", p);

    p = "Other"; // p reassigns from pointing to the first character in WOW to the first character in Other
    printf(" %s", p);
    char s[] = "Fine";
    //s=p;//cannot do this becuase you cannot modify the array identifier which in this case is s which stores the address to teh first element in the array

}

//Write a fnction that counts space in a string and returns the number of space


int spaceCounter ( char *s){
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++){
        if (s[i] == ' '){
            count++;
        }
    }
    return count;

}
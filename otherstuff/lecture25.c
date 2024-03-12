#include <stdio.h>
#include <string.h>

//String I/O

int main (void){

    //output strings
    char * s="an exmplae";
    //use the modifier %s for strings (prints all eleemnts until the null character is met)
    //argument is the ADDRESS to the first element of the string - s(first character address) to \0 (null character, exclusive)
    printf("%s\n",s);
    //4th element onward
    printf("%s\n",s+3);
    //ending character can be set using %.Xs where x is the index of the last element to be printed
    printf("%.3s", s);

    //single characters
    //in this case you have to dereference the string because the agrument must be of time char. , *s dereferences to the single caracter 'a'
    printf("%c", *s);
    
    //easy way to print strings, no format speccifier nessecary, prints from s[0] to null char (\0)
    puts(s);


    //input strings

    char st[10];
    scanf(" %s", st); //st is the array identifier and also the pointer to the first element in the array
    //after entering strings and user presses <enter>, it automatically appends the string with the null character \0.

    //!properties of scanf
    //* 1. ignores all white spaces before characters entered
    //* 2. reads characters till a white space  -   where white spaces can be space, enter of skip
    //* 3. terminates strings with the null chracter    
    
    //ex if you enter ___ABCD__ff<enter> you will require 2 scanfs 
    //because it there are white spaces so it terminates and then scans again, replacing the first 2 elements from AB to ff.

    //so this scanf will start at where it stopped at last
    scanf("%s", &st[5]); //in this case since it is after the null charcter (string is already terminated, it will ignore/omit the rest of the characters)
    printf("%s", st);


    // char sn[10];
    //gets reads the white spaces & any characters until enter
    // gets(sn);
    // puts(sn);

    //! if the size of the entered characters exceeds the size of array, scanf illegally accesses spaces that were not allocated.
    //! teh overflowing characters will return a phenomenon called buffer overflow
    //* behaviour of the code is undefined and it doesnt return an error
    

    
}
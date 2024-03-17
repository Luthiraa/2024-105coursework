#include <stdio.h>
#include <string.h>

//string methods


//5 concatenates n characters. Copy maximum n characters or untill null chracters is observed in src
//ptr to destination is returned
char * strncatcopy (char * dest, char * src, int n){
    int i =0;
    while(src[i]!='\0' || i!=n){
        dest[i]=src[i];
        i++;
    }
    return dest;
}

int main(void){
    //strlen(char * s) // argument is a pointer to the string and returns an integer

    //!Exam question 
    //* Example: Copies string to another string
    char s[6]="Hello";
    //char d[6]=s; 
    //!cannot do this beacause you cannot change an array identifier of d

    char d[6]; 
    //first arguement is copy to (pointer type for both) , second arguement is copy from, NULL CHARACTER IS ALSO COPIED
    strcpy(d,s);
    
    char n[4];
    //str(s,n); if you were to do this, you would get a buffer overflow in which you are accessing illegal memoery space because size of n<d.


    //3. copies the first n-1 characters in string to another string

    //char * strncpy(char * dest, char * src, int n); where n is the number of characters you want to copy +1 whwere the +1 

    char string[]="Hello World";
    
    //*copies "Hello" and stores into the string array
    strncpy(string,"Hello",6); //5 characters + null character
    puts(string); // just prints Hello b/c the 6th character is the null character and only prints upto the null character


    char new[]="Hello"; 
    strncpy(new, "auaufsudfgusdgfuis", 1000);



    //concatenate 2 strings strcat(char*dest, const char*src); the source string must be a constant string
    char abc[] ="hello";

    strcat(abc," world");
    puts(abc);

    strncat(abc,"YAY",4);

}


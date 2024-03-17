#include <stdio.h>
#include <string.h>
//get string safely and string library functions 

//*implement 'fgets' alike function 
char * getStrSafe (char *s, int size){
        int i=0;
    while (i<size-1){
        char c = getchar();
        if (c=='\n'){
            break;
        }
        s[i]=c;
        i++;
    }
    s[i]='\0';
}

//! better way:
// char * getStrSafe(char *s, int size){
//     int i=0; 
//     char c; 
//     while((i<size-1) && (c =getchar()!='\n')){
//         s[i]=c;
//         i++;
//     }   
//     s[i]='\0';
//     return s;
// }

int main(void){

    // to get  string input in a safe manner to avoid accessing illegal memory space, we can use: fgets( string identfier, #of characetrs, stdin);
    // where number of characetrs is # of characters -1 and put 1 null character \0 at the end of the string 
    // stdin 
    char s[7+1];
    fgets(s,3,stdin); // in this example we have 2 spaces for input and 1 spot for the null character
    puts(s); 

    //* There is s getchar() methof that reads only 1 character
    char c = getchar(); // scanf("%c", c);
    char n[5];
    getStrSafe(n, 5);
    puts(n);


    //string methods
    //int strlen(const char *);
    //the const in const char is there to guard against changes to the constant string, it is a constant string
    
    char m[6]="hi";
    printf("%d", strlen(m));
}




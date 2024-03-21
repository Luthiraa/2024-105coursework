#include <stdio.h>

//lecture 29 Recursion 

//greatest common divisor 
//* utilize the euclidean algorithm st: 
    // d divides a and b, then d divides (a, b-a)


//! Advantages and disadvantages 
//! - Easy to implement and write code 
//! - Memory ineffecient : May cause stack overflow due to all function calls  
//! - Time ineffecient 

int gcd(int a, int b){
    if (a>b){
        //if a is greater than b then the function will call on itself decreasing the value of b by a (a-b) = b
        // for the example of a = 8 and b = 20 
            //1. a <b: pass
            // 2. a>b: a=8, b= 20-8 = 12
            //3. a<b: pass
            //4. a>b: a=12, b= 12-8 = 4
            //6.a>b: a=4 b=8-4= 4

       return gcd(b,a-b);
       //calling on return after each function call allows to erase the calls from the stack
    }else if (b>a){
        //if b is greater than a then it will call gcd but reverse the order, passing in b as a and a as b 
       // for the example of a = 8 and b = 20 
        //b>a
        //1. gcd(20,8)
        //3. gcd (12,8)
        //5. gcd(8,4)
       return gcd(b,a);
    }else{
        //return 4
        return a; 
    }
    
}

//factorial using recursion 
        //smaller problem of n! = n * (n-1)!
int factorial(int n ){  
    if(n==1){
        //break condition
        return 1;
       
    }else{
        return n * factorial(n-1); 
    }
     
}

int main (void){
    printf("%d\n", gcd(8,20));
    printf("Factorial: %d", factorial(3));
}
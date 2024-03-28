#include <stdio.h>

//data structures 

// struct NStruct {
//     int neuronNum; 
//     char areaName[50];

// };
//or use 
typedef struct NStruct {
    int neuronNum; 
    char areaName[50];

}Neuron;
// this would allow calling it by using Neuron neuron;

int main(void){
    Neuron neuron;
    neuron.neuronNum = 100;
    //*pointer notation
        //Neuron *p = &neuron;  
        // (*p).neuronNum = 100; 
        //!arrow used to access items
        // p ->neuronNum = 100;

    //dynamically allocates size of neruson and return Neuron*   
    Neuron *q= malloc (sizeof(Neuron));
    free(q);


    Neuron neurons[500];
    neurons[0].neuronNum = 0;

    
}
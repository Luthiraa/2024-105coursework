#include <stdio.h>

//linked lists
//independant nodes that are linked using a ptr

typedef struct node{
    int data; 
    //! dont forget * or it will be a recurisve data structure 
    struct node * next;  // its nto an int * beacuse it points to the next node as a whole and not just a singular item
    //acceptable to use struct node beacuse its previously defined


}Node ;

int main (void){

    //must define a pointer to the first element in the linked list called 'head'
    Node * head  = NULL; //ptr to a node
    Node * newNode = (Node *)malloc (sizeof(Node)); //dynamically allocate a node with: data and next  (uninit)
    (*newNode).data = 1; //assign 1 to the first node (newNode)
    (*newNode).next = NULL; //points to null 
   //* or 
    // newNode -> data = 1; 
    // newNode -> next = NULL; 
    head = newNode;
    //*newnode is just a pointer
    newNode = (Node*) malloc(sizeof(Node)); //! head is still pointing to old node 

    newNode -> data = 2; 
    newNode -> next = NULL;
    //upto here head is still poitning to NULL so we must link them
    //we have to move it after the first node
    
    head -> next = newNode;// point the to the next node 



    //printf("%d", head->data);
}
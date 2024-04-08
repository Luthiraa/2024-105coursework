#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *next;
}node;

//solution 1: pass the address of head in main to insertAtFront
// in this case headPtr points to the address of head in the main function 
bool insertAtFront(node**headPtr,int value){
    node*temp = (node*)malloc(sizeof(node));
    if(temp == NULL){
        return false;
    }
    // points the temp variable to the head in main 
    temp->next = *headPtr; 
    // sets head  to temp 
    *headPtr = temp; 
    return true; 
}

//solution 2: Enclose / wrap the head pointer inside a data structure: LinkedList
// the pointer to the head is stores in a data structure 
typedef struct list{
    node * head; 
}LinkedList;

int * createNode(int value){
    node *newNode = (node*)malloc(sizeof(node));
    if(newNode == NULL){
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// it is not a double pointer beacuse it is implied by the the declaration of head in the struct itself
bool insertAtFront2(LinkedList * list,int value){
    node * temp = createNode(value);
    if (temp == NULL){
        return false; 
    }
    temp -> next = list->head; // points to the head of the list
    list->head = temp; // sets the head to the temp variable
    return true;
}
//function that prints the nodes inside the linked list

void printList (LinkedList * list){
    node * current = list->head;
    while(current != NULL){
        printf("%d --> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

node * findFirstNode (LinkedList * list, int value){
    node * current = list->head;
    while(current != NULL){
        if(current->data == value){
            return current;
        }
        current = current->next;
    }
    return NULL;

}


int main(void){
    //solution 1:
    node * head = createNode(7);
    insertAtFront(&head, 1);
    printf("Solution 1: \n%d --> %d", head->data, head->next->data);


    // solution 2:  
    LinkedList list; 
    list.head = createNode(7);
    insertAtFront2(&list, 1);
    printf("\nSolution 2: \n");
    printList(&list);

}


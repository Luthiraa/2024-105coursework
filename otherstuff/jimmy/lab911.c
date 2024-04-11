#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// Implement these functions
void handleInsert(LinkedList*);
void handleRemove(LinkedList*);
void handleCurrentCal(LinkedList*, int);
void handleVoltage(LinkedList*, int);
void handlePrint(LinkedList*);
void handleQuit(LinkedList*);

int main(void) {
  LinkedList circuit; // Creates new node that has head as a member
  initList(&circuit); // Initializes head member of circuit
  char command = '\0';
  printf("Welcome to our circuit simulator\n");
  // Enter the source voltage!
  printf("What is the source of the voltage?\n");
  int voltage;
  readInputNumber(&voltage); // Reads in the voltage

  while (command != 'Q') {
    command = getCommand();

    switch (command) {
      case 'I':
        handleInsert(&circuit);
        break;
      case 'R':
        handleRemove(&circuit);
        break;
      case 'C':
        handleCurrentCal(&circuit, voltage);
        break;
      case 'V':
        handleVoltage(&circuit, voltage);
        break;
      case 'P':
        handlePrint(&circuit);
        break;
      case 'Q':
        handleQuit(&circuit);
        break;
    }
  }
  return 0;
}

void handleInsert(LinkedList* circuit) {
  int resistance = 0;
  printf("What's the value of the resistor: ");
  readInputNumber(&resistance);
  printf("What's the label of the resistor: ");
  char labelName[STRING_MAX];
  readInputString(labelName, STRING_MAX);
  
  // TODO: Implement the insert into ordered list function
  Node* currentNode = circuit -> head; 

  // Allocating memory to create and initialize the Node to be inserted
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode -> value = resistance;
  strcpy(newNode -> name, labelName);
  newNode -> next = NULL;

  // Checks if list is empty
  if (currentNode == NULL){
    currentNode = (Node*)malloc(sizeof(Node));
    // Set currentNode to newNode so head now points to what is now the first node
    currentNode -> value = newNode -> value;
    strcpy(currentNode -> name, newNode -> name); 
    currentNode -> next = NULL;
    return;
  } else if (currentNode != NULL){
    // If the Linked List is not empty, check if the name to be inputted comes before the name in the first node
    if (strcmp(currentNode -> name, labelName) == 0){
      printf("A resistor with %s label already exists.", labelName);
      return;
    } else if (strcmp(currentNode -> name, labelName) < 0){
      // If name to be inputted IS NOT before name in first node, proceed to check all nodes
      while (currentNode -> next != NULL && strcmp (currentNode -> next -> name, labelName) <=0){
        // Checking for repeats at every node
        if (strcmp(currentNode -> name, labelName) == 0){
          printf("A resistor with %s label already exists.", labelName);
          return;
        } 
        // Sets currentNode to next Node
        currentNode = currentNode -> next;
       }
      }
    }

    // Inserting the node 
    newNode -> next = currentNode -> next;
    currentNode -> next = newNode;

    // printf("%d, %s", circuit -> head -> next -> value, circuit -> head -> next -> name);

    return;
  }

void handleRemove(LinkedList* circuit) {
  // TODO: Implement the remove function
  char label[STRING_MAX];
  printf("What's the label of the resistor you want to remove: ");
  readInputString(label, STRING_MAX);

  // Dynamically allocate memory for the current node
  Node* currentNode = circuit -> head;

  // Checks if list is empty
  if (currentNode == NULL){
    // Nothing to return
    return;
  } else if (currentNode != NULL){
    // If first node is to be removed, if statement is skipped and goes straight to deletion
    // If first node is NOT removed...
    // If name to be inputted IS NOT before name in first node, proceed to check all nodes
      while (currentNode -> next != NULL && strcmp (currentNode -> next -> name, label) != 0){
        // Sets currentNode to next Node
        currentNode = currentNode -> next;
      }
  }

  // If last element...
  if (currentNode -> next == NULL){
    printf("The resistor with %s label does not exist.", label);
    return;
  }

  // Deleting the node 
  Node* temp = currentNode -> next;
  currentNode -> next = currentNode -> next -> next;
  free (temp);
  return;
}

void handleCurrentCal(LinkedList* circuit, int voltage) {
  // TODO: Implement the function that prints the value of current in the
  // circuit
}
void handleVoltage(LinkedList* circuit, int voltage) {
  // TODO: Implement the function that prints the potential difference across a
  // resistor
}

void handlePrint(LinkedList* circuit) {
  // TODO: they can implement the print function
  Node* currentNode = circuit -> head;

  while (currentNode != NULL){
    printf("\n%s   %d", currentNode -> name, currentNode -> value);
    currentNode = currentNode -> next;
    // printf("\n%s   %d", currentNode -> name, currentNode -> value);
  }

  return;
}

void handleQuit(LinkedList* circuit) {
  // TODO: Implement the quit function
}

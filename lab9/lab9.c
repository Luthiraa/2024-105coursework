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
  LinkedList circuit;
  initList(&circuit);
  char command = '\0';
  printf("Welcome to our circuit simulator\n");
  // Enter the source voltage!
  printf("What is the source of the voltage?\n");
  int voltage;
  readInputNumber(&voltage);

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
  Node * newNode = malloc(sizeof(Node));
  newNode->value = resistance; 
  strncpy(newNode->name, labelName, STRING_MAX);

  Node* current = circuit->head;
  // keep track of previous node to connect it in the end
  Node* low = NULL;

  // Check if a resistor with the same label exists
  while (current != NULL) {
    if (strcmp(current->name, newNode->name) == 0) {
      printf("A resistor with %s label already exists.\n", newNode->name);
      free(newNode);
      return;
    }
    current = current->next;
  }

  current = circuit->head;

  // iterate through only if the list isn't empty and while the label's value comes before the one being inserted
  while (current != NULL && strcmp(current->name, newNode->name) < 0) {
    // iterate through low and current
    low = current;
    current = current->next;
  }

  newNode->next = current;

  // if at the beginning set the new node to the head
  if (low == NULL) {
    circuit->head = newNode;
  } else {
    // connect the previous node to the new node
    low->next = newNode;
  }
}

void handleRemove(LinkedList* circuit) {
  printf("What's the label of the resistor you want to remove: ");
  char labelName[STRING_MAX];
  readInputString(labelName, STRING_MAX);

  Node* current = circuit->head;
  Node* low = NULL;

  while (current != NULL) {
    if (strcmp(current->name, labelName) == 0) {
      if (low == NULL) {
        circuit->head = current->next;
      } else {
        low->next = current->next;
      }
      free(current);
      return;
    }
    low = current;
    current = current->next;
  }
  printf("The resistor with %s label does not exist.\n", labelName);
}

void handleCurrentCal(LinkedList* circuit, int voltage) {
  int rEQ = 0;
  Node* current = circuit->head;
  while (current != NULL) {
    //simply add resistors bc they in series
    rEQ += current->value;
    current = current->next;
  }
  //calculate current
  double currentFlow = (double)voltage / rEQ;
  printf("The current in the circuit is %.6fA\n", currentFlow);
}

double calculateCurrent (LinkedList * circuit, int voltage){
  //req in series
  int rEQ = 0;
  Node* current = circuit->head;
  while (current != NULL) {
    rEQ += current->value;
    current = current->next;
  }
  double currentFlow = (double)voltage / rEQ;
  return currentFlow; 
}

void handleVoltage(LinkedList* circuit, int voltage) {
  // calculate current 
  // calculate voltage drop across each resistor
  double currentInCircuit = calculateCurrent(circuit, voltage);
  //traverse the list to match the label, and grab the resistor value
  printf("What\'s the label of the resistor you want to find the voltage across : ");
  char labelName[STRING_MAX];
  readInputString(labelName, STRING_MAX);
  Node * current = circuit->head; 
  while(current !=NULL){
    if (strcmp(current->name, labelName) == 0){
      double potentialDiff = currentInCircuit * current->value; 
      // printf("\n%f ---- %d \n", potentialDiff, currentInCircuit,circuit->value);
      printf("Voltage across resistor is %.6fV",potentialDiff);
      return;
    }
    current = current->next;
  }
  printf("The resistor with %s label does not exist.\n",labelName);
}
void handlePrint(LinkedList* circuit) {
  
  Node * current = circuit->head; 
  while(current!=NULL){
    printf("%s %d Ohms\n",current->name,current->value);
    current = current ->next;
  }
  // TODO: they can implement the print function
}

void handleQuit(LinkedList* circuit) {
  printf("Removing all resistors in the circuit ...\n");
  
  // Traverse the list and free each node
  Node* current = circuit->head;
  while (current != NULL) {
    Node* temp = current;
    current = current->next;
    printf("%s %d Ohms", temp->name,temp->value);
    free(temp);
  }  
  // Reset the head pointer
  circuit->head = NULL;
}

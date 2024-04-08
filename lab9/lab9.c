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
  Node * current = circuit->head; 
  Node* current = circuit->head;
  Node* prev = NULL;
  while (current != NULL && strcmp(current->name, newNode->name) < 0) {
    prev = current;
    current = current->next;
  }
  if (current != NULL && strcmp(current->name, newNode->name) == 0) {
    printf("A resistor with %s label already exists .\n",newNode->name);
    free(newNode);
    return;
  }
  newNode->next = current;
  if (prev == NULL) {
    circuit->head = newNode;
  } else {
    prev->next = newNode;
  }
}
void handleRemove(LinkedList* circuit) {
  printf("What ’s the label of the resistor you want to remove: ");
  char labelName[STRING_MAX];
  readInputString(labelName, STRING_MAX);
  Node* current = circuit->head;
  Node* prev = NULL;
  

  // TODO: Implement the remove function
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
}

void handleQuit(LinkedList* circuit) {
  // TODO: Implement the quit function
}

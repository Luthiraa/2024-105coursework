#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// LinkedList operations
//* delete at tail
//  1. free up space in the last node  -> stop at 2nd last node then free (current->next)
//  2.set the next of 2nd last node to null -> current->next =NULL;

typedef struct Node
{
    int data;
    struct node *next;
} Node;

typedef struct list
{
    Node *head;
} LinkedList;

void deleteAtTail(LinkedList *list)
{
    Node *current = list->head;
    if (current == NULL)
    { // or could be (list->head == NULL);
        return;
    }
    if (current->next == NULL)
    { // or could be (list->head->next == NULL);
        free(current);
        list->head = NULL;
        return;
    }
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

//*delete a node with a specific value in a linked list
// should then point the previous node to the next node of the node to be deleted

//! steps:
// travserse list and stop at the node priror to the ndoe we want to delete
// temp = current->next;
// current-next = temp ->next;
// free it up and link the temp to the current next  (free(temp))

//! salma way
bool deleteFirsyMatch(LinkedList *list, int value)
{
    //! ORDER OF IF STATEMETNSTS mATTEr

    if (list->head == NULL)
    {
        return false;
    }
    if (list->head == value)
    {
        deleteAtFront(list->head);
        return true;
    }

    Node *current = list->head;
    while (current->next != NULL && current->next->data != value)
    {
        current = current->next;
    }
    if (current->next != NULL)
    {
        Node *temp = current->next;
        current->next = temp->next;
        current->next = temp->next;
        free(temp);
        return true;
    }
    else
    {
        return false;
    }
}

//! my way
void deleteNode(LinkedList *list, int value)
{
    Node *current = list->head;
    Node *prev = NULL;
    while (current != NULL)
    {
        if (current->data == value)
        {
            if (prev == NULL)
            {
                list->head = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

//* delete all matches
int deleteAllMatches(LinkedList *list, int value)
{
    int count = 0;
    while (deleteFirsyMatch(list, value))
    {
        count++;
    }
    return count;
}

int main(void)
{
}
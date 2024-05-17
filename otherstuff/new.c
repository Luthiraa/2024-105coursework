#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void printReverse()
{
    int num;
    printf("Enter num: ");

    scanf("%d", &num);
    if (num == 0)
    {
        printf("Reversed nums: ");
        return;
    }
    printReverse();

    printf("%d ", num);
}

void NumsToN(int x)
{
    if (x == 0)
    {
        return;
    }

    NumsToN(x - 1);
    printf("%d ", x);
}

int numOccurences(char *str, char *search) {
    int length_str = strlen(str);
    int length_search = strlen(search);

    if (length_str < length_search) {
        return 0;
    }

    if (strncmp(str, search, length_search) == 0) {
        return 1 + numOccurences(str + 1, search);
    } else {
        return numOccurences(str + 1, search);
    }
}


typedef struct node {
int data;
struct node *next;
} Node;

typedef struct linkedList {
Node *head;
} LinkedList;

void insertSequence(LinkedList *list, LinkedList* sequence) {
    Node * current = list->head; 
    Node * seqCurr = sequence->head; 
    Node * store = NULL;
    while(current->next!=NULL){
        if(current->data < seqCurr->data){
            store = current; 
            break; 
        }
        current = current->next; 
    }
    if (store == NULL){
        list->head = seqCurr; 
    }
    store->next = seqCurr; 
    while (seqCurr->next !=NULL){
        seqCurr = seqCurr->next; 
    }
    seqCurr->next = current; 
}

void printStars(int n) {
    if (n == 1) {
        printf("*\n");
    }else{
        printf("*");
        printStars(n-1);
    }
}

void printPattern(int n){
    if (n>0){
        printPattern(n-1);
        printStars(n);
        
    }
}

void revStr (char * str, int len){
    if (len<=0){
        return; 
    }
    printf("%c",str[len-1]);
    revStr(str+1,len-1);
}


int main(void)
{
    // NumsToN(5);
    // // printReverse();
    // int x = numOccurencess("HelloHello", "Hello");
    // printf("%d", x);
    // printPattern(10);
    revStr("Hello",6);
}
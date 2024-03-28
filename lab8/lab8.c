//
// Author:Luthira Abeykoon
//

#include "reversi.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

char coords []={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
//i
//reused code from lab6 due to simmilaer logic 
int di[] = {-1,-1,0,1,1,1,0,-1};  //di[0],dj[0] would be a combination assosicated with a direction (direction[0])
//j
int dj[] = {0,1,1,1,0,-1,-1,-1};
// char *directions[]={"north", "north-east","east","south-east","south","south-west", "west","north-west"};

void initBoard(char board[][26], int n) {
    //tried to do it all in 1 function but didnt work
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //initial positions where white and black can exist for any nxn grid
            if (i==n/2&&j==n/2||i==n/2-1&&j==n/2-1){
                board[i][j] = 'W';
            } else if (i == n/2-1&&j==n/2||i==n/2&&j==n/2-1){
                board[i][j] = 'B';
            } else {
                //any other position that is not W or B
                board[i][j] = 'U';
            }
        }
    }
}

void printBoard(char board[][26], int n) {
    //print board
    printf("  ");
    for (int i = 0; i < n; i++) {
        printf("%c", coords[i]);
    }
    printf("\n");
    for (int i=0; i < n; i++) {
        printf("%c ", coords[i]);
        for (int j = 0; j < n; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}


int main (void){
  int n; 
  printf("Enter the board dimension: ");
  scanf("%d", &n);
  char board[n][26];
  if (n%2==0){
    initBoard(board, n);
    
    do{
    }while(n);
  }
}
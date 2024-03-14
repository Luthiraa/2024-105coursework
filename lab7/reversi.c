//
// Author:Luthira Abeykoon
//

#include "reversi.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

void printBoard(char board[][26], int n) {
    char coords []={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i==n/2&&j==n/2||i==n/2-1&&j==n/2-1){
                board[i][j] = 'W';
            } else if (i == n/2-1&&j==n/2||i==n/2&&j==n/2-1){
                board[i][j] = 'B';
            } else {
                board[i][j] = 'U';
            }
        }
    }
    printf(" ");
    for (int i = 0; i < n; i++) {
        printf("%c", coords[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%c ", coords[i]);
        for (int j = 0; j < n; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    char color, row, col;
    printf("Enter board configuration: \n");
    while (scanf(" %c%c%c", &color, &row, &col)==3&&color!= '!') {
        int i=row-'a';
        int j=col- 'a';
        if (i >= 0 && i < n && j >= 0 && j < n) {
            board[i][j]=color;
        }
    }
    printf("  ");
    for (int i = 0; i < n; i++) {
        printf("%c", coords[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%c ", coords[i]);
        for (int j = 0; j < n; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

bool positionInBounds(int n, int row, int col) {
}

bool checkLegalInDirection(char board[][26], int n, int row, int col,
                           char colour, int deltaRow, int deltaCol) {
}

void readBoard(char board[][26], int n) {

}
int main(void) {
  int n; 
  printf("Enter board dimensions: ");
  scanf("%d", &n);
  char board[n][26];
  printBoard(board,n);

}

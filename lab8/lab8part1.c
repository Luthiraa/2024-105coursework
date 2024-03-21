//
// Author:Luthira Abeykoon
//

#include "lab8part1.h"
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

bool positionInBounds(int n, int row, int col) {
  //within boundaries
    if (row >= 0 && row < n && col >= 0 && col < n){
        return true;
    }
    return false;
}

char assignColour(char colour){
    char other;
    if (colour == 'B'){
        other = 'W';
    }else{
        other = 'B';
    }
    return other; 
}

bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol) {
    char other = assignColour(colour);
    row += deltaRow;
    col += deltaCol;
    //error check fiurst 
    if (positionInBounds(n, row, col)==false||board[row][col]!= other){
        return false; 
    }
    row += deltaRow;
    col += deltaCol;
    //if in bounds
    while (positionInBounds(n, row, col)) {
        //if its empty return false beacuse you cannot flip it bc its not an opponent colour
        if (board[row][col] == 'U') {
            return false;
        }
        if (board[row][col] == colour) {
            return true;
        }
        //iteratre through
        row += deltaRow;
        col += deltaCol;
    }
    return false;
}


void movesAvail(char board[][26], int n, char colour) {
    //simmilar to my lab6 code however but checks reaach rdirection of teh reversi board instead
    printf("Available moves for %c:\n", colour);
    for (int i = 0; i<n;i++){
        for (int j = 0;j<n;j++){
            if (board[i][j]=='U'){
                //8 diff directions
                for (int m =0; m<8;m++){
                    if(checkLegalInDirection(board, n, i, j, colour, di[m], dj[m])){
                        printf("%c%c\n", coords[i], coords[j]);
                        break;
                    }
                }
            }
        }
    }
}


void readBoard(char board[][26], int n) {
    char color, row, col;
    printf("Enter board configuration: \n");
    while (scanf(" %c%c%c", &color, &row, &col)==3&&color!= '!') {
        //convert back to the grid of the game excluding the coordinate system defined on i=0 and j=0
        int i=row-'a';
        int j=col- 'a';
        if (positionInBounds(n,i ,j)) {
            board[i][j]=color;
        }
    }
}
void flip(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol) {
    char other = assignColour(colour);
    int i = row + deltaRow;
    int j = col + deltaCol;
    while (board[i][j] == other) {
        board[i][j] = colour;
        i += deltaRow;
        j += deltaCol;
    }
}

void makeMove(char board[][26], int n, int row, int col, char colour) {
    board[row][col] = colour;
    for (int m = 0; m < 8; m++) {
        if (checkLegalInDirection(board, n, row, col, colour, di[m], dj[m])) {
            
            flip(board, n, row, col, colour, di[m], dj[m]);
        }
    }
}
int computeScore(char board[][26], int n, int row, int col, char colour) {
    int score = 0;
    char other = assignColour(colour);
    for (int m = 0; m < 8; m++) {
        int i = row + di[m];
        int j = col + dj[m];
        while (positionInBounds(n, i, j) && board[i][j] == other) {
            score++;
            i += di[m];
            j += dj[m];
        }
    }
    return score;
}

void CMove(char board[][26], int n, char colour) {
    int maxScore = -1;
    int bestRow, bestCol;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'U') {
                int score = computeScore(board, n, i, j, colour);
                if (score > maxScore) {
                    maxScore = score;
                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }
    if (maxScore > 0) {
        makeMove(board, n, bestRow, bestCol, colour);
    }
}

int main(void) {
  int n; 
  printf("Enter the board dimension: ");
  scanf("%d", &n);
  char board[n][26];
  if (n%2==0){
    initBoard(board, n);
    char opponentColour, colour,row, col; 
    srand(time(NULL));
    if (rand() % 2 == 0){
        opponentColour = 'W';
        colour='B';
    }else{
        opponentColour = 'B';
        colour = 'W';
    }
    printf("Computer plays (B/W): %c\n", opponentColour);
    printBoard(board, n);

  }
//   //even nxn array
//   if (n%2==0){
//     // Initialize the board before printing
//     initBoard(board,n);  
//     printBoard(board,n);
//     readBoard(board, n);
//     //printf("after!!!!!!!!!!!!!!!!!!!!!!\n");
//     printBoard(board, n);
//     movesAvail(board,n, 'W');
//     movesAvail(board,n, 'B');
//     char colour, row, col;
//     printf("Enter a move:\n");
//     scanf(" %c%c%c", &colour, &row, &col);
//     //reinit to proper grid
//     int i = row - 'a';
//     int j = col - 'a';
//   bool isValid = false;
//   for (int m = 0; m < 8; m++) {
//     if (checkLegalInDirection(board, n, i, j, colour, di[m], dj[m])) {
//         isValid = true;
//         break;
//     }
//   }
//   if (positionInBounds(n, i, j) && board[i][j] == 'U' && isValid==true) {
//     printf("Valid move.\n");
//     makeMove(board, n, i, j, colour);
//     printBoard(board, n);
//   } else {
//     printf("Invalid move.\n");
//     printBoard(board, n);
//   }
//   }
}
// Enter the board dimension: 4
// abcd
// a UUUU
// b UWBU
// c UBWU
// d UUUU
// Enter board configuration:
// Bba
// Wca
// Bac
// !!!
// abcd
// a UUBU
// b BWBU
// 4
// c WBWU
// d UUUU
// Available moves for W:
// aa
// bd
// db
// Available moves for B:
// ab
// cd
// da
// dc
// Enter a move:
// Wdb
// Valid move.
// abcd
//property of luthira :)))

// a UUBU
// b BWBU
// c WWWU
// d UWUU


// Bbd
// Bad
// Wde
// Wcb
// !!!

// gcc reversi.c -o reversi
// ~aps105i/public/exercise 7 reversi
// ~aps105i/public/submit 7
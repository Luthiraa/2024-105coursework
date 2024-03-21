#include "reversi.h"
#include <stdio.h>
#include <stdbool.h>

void initialize_board (char board[][26], int n){
  for (int row = 0; row < n; row ++){
    for (int col = 0; col < n; col ++){
      board[row][col] = 'U';
    }
  }

  // Initialize Centre
  board[n / 2 - 1][n / 2] = 'B';             // Top right corner
  board[n / 2 - 1][n / 2 - 1] = 'W';         // Top left corner
  board[n / 2][n / 2] = 'W';                 // Bottom right corner
  board[n / 2][n / 2 - 1] = 'B';             // Bottom left corner
}

void printBoard(char board[][26], int n) {
  char letter_coord [26]; 
  printf(" ");
  for (int i = 0; i < n; i++){
    letter_coord [i] = 'a' + i;
    printf("%c", letter_coord [i]);
  }
  
  // Printing
  for (int row = 0; row < n; row++){
    printf("\n%c", letter_coord[row]);
    for (int col = 0; col < n; col++){
      printf("%c", board[row][col]);
    }
  }
}

bool positionInBounds(int n, int row, int col) {
  if (row > n || row <= 0 || col > n || col <= 0){
    return false;
  } else {
    return true;
  }
}

bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol) {
    bool opponent_piece = false;

    for (int i = row + deltaRow, j = col + deltaCol; (i >= 0 && i < n) && (j >= 0 && j < n); i += deltaRow, j += deltaCol) {
        if ((board[i][j] == 'W' && colour == 'B') || (board[i][j] == 'B' && colour == 'W')) {
            opponent_piece = true;
        } else if (board[i][j] == colour && opponent_piece) {
            return true;
        } else if (board[i][j] == colour && (opponent_piece == false)|| (board[i][j] == 'U')) {
            break;
        }
    }
    return false;
}

void flip(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol) {
    bool opponent_piece = false;

    for (int i = row + deltaRow, j = col + deltaCol; (i >= 0 && i < n) && (j >= 0 && j < n); i += deltaRow, j += deltaCol) {
        // If black is player, flip white to black
        if ((board[i][j] == 'W' && colour == 'B')) {
            board[i][j] = 'B';
            opponent_piece = true;
        // If white is player, flip black to white
        } else if ((board[i][j] == 'B' && colour == 'W')){
            board[i][j] = 'W';
            opponent_piece = true;
        // If encounters own piece, stop flipping
        } else if (board[i][j] == colour && opponent_piece) {
            break;
        }
    }
}

int main(void) {
  int n = 0;
  char first_char;
  char second_char;
  char third_char;
  
  printf("Enter the board dimension: \n");
  scanf("%d", &n);

  char board [n][n];
  initialize_board(board, n);
  printBoard(board, n);

  printf("\nEnter board configuration: \n");
  
  do {
    scanf(" %c%c%c", &first_char, &second_char, &third_char);

    if (first_char == 'B'){
      board[second_char-97][third_char-97] = 'B'; // Adjust ASCII
    } else if (first_char == 'W'){
      board[second_char-97][third_char-97] = 'W'; // Adjust ASCII
    } else if (first_char == 'U'){
      board[second_char-97][third_char-97] = 'U'; // Adjust ASCII
    }

  } while (first_char != 33);

  printBoard(board, n);

  // Displaying available moves
  printf("\nAvailable moves for W:");

  int direction_row[] = {-1, -1, 0, 1, 1,  1,  0, -1};
  int direction_col[] = { 0,  1, 1, 1, 0, -1, -1, -1};
  
  char letter_coord [26]; 
  for (int i = 0; i < 26; i++){
    letter_coord [i] = 'a' + i;
  }

  for (int row = 0; row < n; row++){
    for (int col = 0; col < n; col++){
      if(board[row][col] == 'U'){
        for (int direction = 0; direction < 8; direction ++){
          if (checkLegalInDirection(board, n, row, col, 'W', direction_row[direction], direction_col[direction])){
            printf("\n%c%c", letter_coord[row], letter_coord[col]);
            break;
          }
        }
      }
    }
  }

  printf("\nAvailable moves for B:");
  
  for (int row = 0; row < n; row++){
    for (int col = 0; col < n; col++){
      if(board[row][col] == 'U'){
        for (int direction = 0; direction < 8; direction ++){
          if (checkLegalInDirection(board, n, row, col, 'B', direction_row[direction], direction_col[direction])){
            printf("\n%c%c", letter_coord[row], letter_coord[col]);
            break;
          }
        }
      }
    }
  }

  printf("\nEnter a move: ");
  scanf(" %c%c%c", &first_char, &second_char, &third_char); 
  // Inbounds function to be implemented

  // Checks if inBounds or not
  if (positionInBounds(n, (second_char - 97), (third_char - 97))){
    //Cycles through every cell and checks if legal move cells are equal to inputted move
    bool valid = false;

    for (int row = 0; row < n; row++){
      for (int col = 0; col < n; col++){
        if(board[row][col] == 'U'){
          bool first_run = true;
          for (int direction = 0; direction < 8; direction ++){
            if (checkLegalInDirection(board, n, row, col, first_char, direction_row[direction], direction_col[direction])){         
              // Flipping
              if (letter_coord[row] == second_char && letter_coord[col] == third_char){
                // Printing move validity
                if(first_run){
                  printf("\nValid move.\n");
                  first_run = false;
                  valid = true;
                }
                flip(board, n, row, col, first_char, direction_row[direction], direction_col[direction]); // Flipping
                board[row][col] = first_char; // Flip target cell
              } 
            }
          }
        }
      }
    }

    // If within bounds but doesn't meet a legal move
    if (valid == false){
      printf("\nInvalid move.\n");
    } 
  } else if (positionInBounds(n, (second_char - 97), (third_char - 97)) == false){
    printf("\nInvalid move. \n");
  } 

  printBoard(board, n);

  return 0;
}

// gcc reversi.c -o reversi
// ~aps105i/public/exercise 7 reversi
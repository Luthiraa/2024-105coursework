//
// Author:Luthira Abeykoon
//

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "lab8part1.h"

char coords[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
// i
// reused code from lab6 due to simmilaer logic
int di[] = {-1, -1, 0, 1, 1, 1, 0, -1}; // di[0],dj[0] would be a combination assosicated with a direction (direction[0])
// j
int dj[] = {0, 1, 1, 1, 0, -1, -1, -1};
// char *directions[]={"north", "north-east","east","south-east","south","south-west", "west","north-west"};

void initBoard(char board[][26], int n)
{
    // tried to do it all in 1 function but didnt work
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // initial positions where white and black can exist for any nxn grid
            if (i == n / 2 && j == n / 2 || i == n / 2 - 1 && j == n / 2 - 1)
            {
                board[i][j] = 'W';
            }
            else if (i == n / 2 - 1 && j == n / 2 || i == n / 2 && j == n / 2 - 1)
            {
                board[i][j] = 'B';
            }
            else
            {
                // any other position that is not W or B
                board[i][j] = 'U';
            }
        }
    }
}

void printBoard(char board[][26], int n)
{
    // print board
    printf("  ");
    for (int i = 0; i < n; i++)
    {
        printf("%c", coords[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%c ", coords[i]);
        for (int j = 0; j < n; j++)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}
bool positionInBounds(int n, int row, int col)
{
    // within boundaries
    if (row >= 0 && row < n && col >= 0 && col < n)
    {
        return true;
    }
    return false;
}

char assignColour(char colour)
{
    char other;
    if (colour == 'B')
    {
        other = 'W';
    }
    else
    {
        other = 'B';
    }
    return other;
}
bool hasValidMove(char board[][26], int n, char colour)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'U')
            {
                for (int m = 0; m < 8; m++)
                {
                    if (checkLegalInDirection(board, n, i, j, colour, di[m], dj[m]))
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
bool anyPlayerHasMove(char board[][26], int n, char colour1, char colour2)
{
    return hasValidMove(board, n, colour1) || hasValidMove(board, n, colour2);
}
bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol)
{
    char other = assignColour(colour);
    row += deltaRow;
    col += deltaCol;
    // error check fiurst
    if (positionInBounds(n, row, col) == false || board[row][col] != other)
    {
        return false;
    }
    row += deltaRow;
    col += deltaCol;
    // if in bounds
    while (positionInBounds(n, row, col))
    {
        // if its empty return false beacuse you cannot flip it bc its not an opponent colour
        if (board[row][col] == 'U')
        {
            return false;
        }
        if (board[row][col] == colour)
        {
            return true;
        }
        // iteratre through
        row += deltaRow;
        col += deltaCol;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == colour)
            {
                continue;
            }
        }
    }
    return false;
}

void movesAvail(char board[][26], int n, char colour)
{
    // simmilar to my lab6 code however but checks reaach rdirection of teh reversi board instead
    printf("Available moves for %c:\n", colour);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'U')
            {
                // 8 diff directions
                for (int m = 0; m < 8; m++)
                {
                    if (checkLegalInDirection(board, n, i, j, colour, di[m], dj[m]))
                    {
                        printf("%c%c\n", coords[i], coords[j]);
                        break;
                    }
                }
            }
        }
    }
}

void readBoard(char board[][26], int n)
{
    char color, row, col;
    printf("Enter board configuration: \n");
    while (scanf(" %c%c%c", &color, &row, &col) == 3 && color != '!')
    {
        // convert back to the grid of the game excluding the coordinate system defined on i=0 and j=0
        int i = row - 'a';
        int j = col - 'a';
        if (positionInBounds(n, i, j))
        {
            board[i][j] = color;
        }
    }
}
void flip(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol)
{
    char other = assignColour(colour);
    int i = row + deltaRow;
    int j = col + deltaCol;
    while (board[i][j] == other)
    {
        board[i][j] = colour;
        i += deltaRow;
        j += deltaCol;
    }
}

void makeMove(char board[][26], int n, int row, int col, char colour)
{
    board[row][col] = colour;
    for (int m = 0; m < 8; m++)
    {
        if (checkLegalInDirection(board, n, row, col, colour, di[m], dj[m]))
        {
            flip(board, n, row, col, colour, di[m], dj[m]);
        }
    }
}

int calculateScore(char board[][26], int n, int row, int col, char colour)
{
    int score = 0;

    for (int m = 0; m < 8; m++)
    {
        if (checkLegalInDirection(board, n, row, col, colour, di[m], dj[m]))
        {
            int tempRow = row + di[m], tempCol = col + dj[m];

            while (board[tempRow][tempCol] == assignColour(colour))
            {
                score++;
                tempRow += di[m];
                tempCol += dj[m];
            }
        }
    }

    return score;
}
bool computerMove(char board[][26], int n, char colour)
{
    int MScore = 0;
    int BRow = 0;
    int BCol = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'U')
            {
                int score = calculateScore(board, n, i, j, colour);

                if (score > MScore)
                {
                    MScore = score;
                    BRow = i;
                    BCol = j;
                }
            }
        }
    }

    if (MScore == 0)
    {
        return false;
    }
    else
    {
        makeMove(board, n, BRow, BCol, colour);
        printf("Computer places %c at %c%c.\n", colour, coords[BRow], coords[BCol]);
        return true;
    }
}


void displayWinner(char board[][26], int n)
{
    int countB = 0, countW = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'B')
            {
                countB++;
            }
            else if (board[i][j] == 'W')
            {
                countW++;
            }
        }
    }

    if (countB > countW)
    {
        printf("B player wins.\n");
    }
    else
    {
        printf("W player wins.\n");
    }
}
bool isBoardFilled(char board[][26], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'U')
            {
                return false;
            }
        }
    }
    return true;
}

int main(void)
{
    char row, col;
    int n;
    bool notValidInvoked = false;
    printf("Enter the board dimension: ");
    scanf(" %d", &n);

    char board[n][26];
    initBoard(board, n);

    char CColour, YColour;
    printf("Computer plays (B/W): ");
    scanf(" %c", &CColour);

    if (CColour == 'W')
    {
        YColour = 'B';
    }
    else
    {
        YColour = 'W';
    }
    printBoard(board, n);
    while (true)
    {        // Check if the board is filled or if neither player has a valid move, if so, end the game
        if (isBoardFilled(board, n) || !anyPlayerHasMove(board, n, 'W', 'B'))
        {
            break;
        }
     if (CColour == 'B')
        {
            // Computer's turn
            char currentColour = CColour;
            char oppColour = YColour;
                 if (isBoardFilled(board, n) == true)
            {
                break;
            }
            // If computer cannot make a move, skip turn
            if (!hasValidMove(board, n, currentColour))
            {
                printf("%c player has no valid move.\n", currentColour);
            }
            else
            {
                if (!computerMove(board, n, currentColour))
                {
                    printf("%c player has no valid move.\n", currentColour);
                }           
                printBoard(board, n);     
            }
      
            // Player's turn
            currentColour = YColour;
            oppColour = CColour;
            if (isBoardFilled(board, n) == true)
            {
                break;
            }
            // If player cannot make a move, skip turn
            if (!hasValidMove(board, n, currentColour))
            {
                printf("%c player has no valid move.\n", currentColour);
            }
            else
            {
                printf("Enter move for colour %c (RowCol): ", currentColour);
                scanf(" %c%c", &row, &col);
                int rowIndex = row - 'a';
                int colIndex = col - 'a';
                if (positionInBounds(n, rowIndex, colIndex) && board[rowIndex][colIndex] == 'U')
                {
                    bool isValidMove = false;
                    for (int i = 0; i < 8; i++)
                    {
                        if (checkLegalInDirection(board, n, rowIndex, colIndex, currentColour, di[i], dj[i]))
                        {
                            isValidMove = true;
                            break;
                        }
                    }
                    if (isValidMove)
                    {
                        makeMove(board, n, rowIndex, colIndex, currentColour);
                        printBoard(board, n);
                    }
                    else
                    {
                        printf("Invalid move.\n");
                        printf("%c player wins.\n", CColour);
                        notValidInvoked = true;
                        break; // End the game since it's an invalid move
                    }
                }
                else
                {
                    printf("Invalid move.\n");
                    printf("%c player wins.\n", CColour);
                    notValidInvoked = true;
                    break; // End the game since it's an invalid move
                }
            }
 
        }



        //! C = WHITE 
        else
        {
            char currentColour = YColour;
            char oppColour = CColour;
            if (isBoardFilled(board, n) == true)
            {
                break;
            }
           
            if (!hasValidMove(board, n, currentColour))
            {
                printf("%c player has no valid move.\n", currentColour);
            }
            else
            {
                printf("Enter move for colour %c (RowCol): ", currentColour);
                scanf(" %c%c", &row, &col);
                int rowIndex = row - 'a';
                int colIndex = col - 'a';
                if (positionInBounds(n, rowIndex, colIndex) && board[rowIndex][colIndex] == 'U')
                {
                    bool isValidMove = false;
                    for (int i = 0; i < 8; i++)
                    {
                        if (checkLegalInDirection(board, n, rowIndex, colIndex, currentColour, di[i], dj[i]))
                        {
                            isValidMove = true;
                            break;
                        }
                    }
                    if (isValidMove)
                    {
                        makeMove(board, n, rowIndex, colIndex, currentColour);
                    }
                    else
                    {
                        printf("Invalid move.\n");
                        printf("%c player wins.\n", CColour);
                        notValidInvoked = true;
                        break; // End the game since it's an invalid move
                    }
                }
                else
                {
                    printf("Invalid move.\n");
                    printf("%c player wins.\n", CColour);
                    notValidInvoked = true;
                    break; // End the game since it's an invalid move
                }
            }

            // Print board after player's move
            printBoard(board, n);


            // Computer's turn
            currentColour = CColour;
            oppColour = YColour;
            if (isBoardFilled(board, n) == true)
            {
                break;
            }
            // If computer cannot make a move, skip turn
            if (!hasValidMove(board, n, currentColour))
            {
                printf("%c player has no valid move.\n", currentColour);
            }
            else
            {
              

                if (!computerMove(board, n, currentColour))
                {
                    
                    continue;
                   
                }
                printBoard(board, n);
            }
            if (isBoardFilled(board, n) == true)
            {
                break;
            }
        }
    }

    // Display winner if the game did not end due to invalid move, a full board, or no valid moves for either player
    if (!notValidInvoked)
    {
        displayWinner(board, n);
    }
    
    // Display winner if the game did not end due to invalid move

    return 0;
}

// ba
// ab
// bd
// da
// dd
// dc
// ad

// 4
// B
// ac
// ca
// aa
// dd
// bd

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
bool anyValidMoves(char board[][26], int n, char color)
{
    int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < n; ++col)
        {
            for (int i = 0; i < 8; ++i)
            {
                if (checkLegalInDirection(board, n, row, col, color, directions[i][0], directions[i][1]))
                {
                    return true;
                }
            }
        }
    }
    return false;
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
// Function to make a move for the computer
bool computerMove(char board[][26], int n, char colour)
{
    // Initialize the maximum score and the best move coordinates
    int MScore = -1, BRow = -1, BCol = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // unoccupied
            if (board[i][j] == 'U')
            {
                // Initialize the score for this cell
                int score = 0;

                // Iterate over all directions
                for (int m = 0; m < 8; m++)
                {
                    if (checkLegalInDirection(board, n, i, j, colour, di[m], dj[m]))
                    {
                        int row = i + di[m], col = j + dj[m];

                        while (board[row][col] == assignColour(colour))
                        {
                            score++;
                            row += di[m];
                            col += dj[m];
                        }
                    }
                }

                // If score for this cell is higher than the current max score,
                if (score > MScore)
                {
                    MScore = score;
                    BRow = i;
                    BCol = j;
                }
            }
        }
    }

    // If no legal move was found, return false
    if (MScore == -1)
    {
        return false;
    }
    // Otherwise, make the best move and return true
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

    // Print initial board
    printBoard(board, n);

    // Main game loop
    while (true)
    {
        // If computer is 'B', it should play first
        if (CColour == 'B')
        {
           // Computer's turn
        char currentColour = CColour;
        char oppColour = YColour;
        // If computer cannot make a move, skip turn
        if (!anyValidMoves(board, n, currentColour))
        {
            printf("%c has no valid move.\n", currentColour);
            CColour = 'W'; // Switch the colours
            YColour = 'B';
            continue; // Skip the rest of the loop and continue with the next iteration
        }
            else
            {
                if (!computerMove(board, n, currentColour))
                {
                    printf("%c player has no valid move.\n", currentColour);
                }
            }
            printBoard(board, n);
        }

        /// Player's turn
    char currentColour = YColour;
    char oppColour = CColour;
    // If player cannot make a move, skip turn
    if (!anyValidMoves(board, n, currentColour))
    {
        printf("%c player has no valid move.\n", currentColour);
        CColour = 'B'; // Switch the colours
        YColour = 'W';
        continue; // Skip the rest of the loop and continue with the next iteration
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

        // If computer is 'W', it should play after the player
        if (CColour == 'W')
        {
            // Computer's turn
            char currentColour = CColour;
            char oppColour = YColour;
            // If computer cannot make a move, skip turn
            if (!anyValidMoves(board, n, currentColour))
            {
                printf("%c has no valid move.\n", currentColour);
                printf("Enter move for colour %c (RowCol): ", oppColour);
                scanf(" %c%c", &row, &col);
                int rowIndex = row - 'a';
                int colIndex = col - 'a';

                if (positionInBounds(n, rowIndex, colIndex) && board[rowIndex][colIndex] == 'U')
                {
                    bool isValidMove = false;
                    for (int i = 0; i < 8; i++)
                    {
                        if (checkLegalInDirection(board, n, rowIndex, colIndex, oppColour, di[i], dj[i]))
                        {
                            isValidMove = true;
                            break;
                        }
                    }
                    if (isValidMove)
                    {
                        makeMove(board, n, rowIndex, colIndex, oppColour);
                    }
                    else
                    {
                        printf("Invalid move.\n");
                        printf("12893718237");
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
            else
            {
                if (!computerMove(board, n, currentColour))
                {
                    printf("%c player has no valid move.\n", currentColour);
                }
            }
            printBoard(board, n);
        }

        // Check if the board is filled, if so, end the game
        if (isBoardFilled(board, n))
        {
            break;
        }
    }

    // Display winner if the game did not end due to invalid move
    if (!notValidInvoked)
    {
        displayWinner(board, n);
    }

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


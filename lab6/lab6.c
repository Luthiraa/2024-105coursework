
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void readWordPuzzle(const int Size, char puzzle[][Size]);

char *readWord(int *wordSize);

void printWordPuzzle(const int Size, char puzzle[][Size]);

void printWord(char *word, const int wordSize);

void search(const int Size, char puzzle[][Size], const int wordSize, char *word);

bool inBounds(int row, int col, const int Size);

int main(void){
    const int Size = 20;
    char puzzle[Size][Size];
    readWordPuzzle(Size, puzzle);
    int wordSize = 0;
    char *word = readWord(&wordSize);
    printWordPuzzle(Size, puzzle);
    printf("The word you are looking for is\n");
    printWord(word, wordSize);
    printf("\n");
    printf("Do you want to search? (Y or N)\n");
   
    char isSearch;
    scanf(" %c", &isSearch);
   
    if (isSearch == 'Y' || isSearch == 'y'){
        search(Size, puzzle, wordSize, word);
    }
   
    free(word);
    return 0;
}


void search(const int Size, char puzzle[][Size], const int wordSize, char* word) {
    //i
    int di[] = {-1,-1,0,1,1,1,0,-1}; //di[0],dj[0] would be a combination assosicated with a direction (direction[0])
    //j
    int dj[] = {0,1,1,1,0,-1,-1,-1};
    char *directions[]={"north", "north-east","east","south-east","south","south-west", "west","north-west"};

    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            if (puzzle[i][j] == word[0]) {
                for(int m=0; m<8; m++){ //8 directions
                    int rowIndex = i, columnIndex = j;
                    int k;
                    for(k = 0; k < wordSize; k++){
                        if(rowIndex < 0 || rowIndex >= Size || columnIndex < 0 || columnIndex >= Size || puzzle[rowIndex][columnIndex] != word[k]){ //check if it overflows
                            break;
                        }
                        rowIndex += di[m];
                        columnIndex += dj[m];
                    }
                    if(k == wordSize){
                        printf("%s can be found at row , col = (%d, %d) in the %s direction\n", word, i+1, j+1, directions[m]);
                        return;
                    }
                }                
            }
        }
    }
    printf("'%s' cannot be found !\n", word);
}

  

char *readWord(int *wordSize) {
    printf("How many characters are there in the word?\n");
    scanf(" %d",wordSize);
    char *word = malloc((*wordSize + 1) * sizeof(char));

    if (word == NULL) {
        printf("Malloc failed\n");
        exit(1);
    }

    printf("What is the word that you are looking for?\n");
    scanf("%s", word);

    return word;
}

void readWordPuzzle(const int Size, char puzzle[][Size]) {
    printf("Please enter the word puzzle:\n");
    for (int i = 0; i<Size; i++){
        for(int j = 0; j< Size; j++){
            scanf(" %c", &puzzle[i][j]);
        }
    }
}

bool inBounds(int row, int col, const int Size) {
  return row >= 0 && row < Size && col >= 0 && col < Size;  
}

void printWordPuzzle(const int Size, char puzzle[][Size]) {
    printf("The word puzzle entered is\n");
    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            printf("%c ", puzzle[i][j]);
        }
        printf("\n");
    }
}
void printWord(char *word, const int wordSize) {
    for (int i = 0; i<wordSize; i++){
        printf("%c ", word[i]);
    }
}

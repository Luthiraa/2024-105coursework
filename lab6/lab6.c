
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
void readWordPuzzle(const int Size, char puzzle[][Size]);
char *readWord(int *wordSize);
void printWordPuzzle(const int Size, char puzzle[][Size]);
void printWord(char *word, const int wordSize);
void search(const int Size,
            char puzzle[][Size],
            const int wordSize,
            char *word);
bool inBounds(int row, int col, const int Size);
int main(void)
{
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
    if (isSearch == 'Y' || isSearch == 'y')
    {
        search(Size, puzzle, wordSize, word);
    }
    free(word);
    return 0;
}
void search(const int Size,
            char puzzle[][Size],
            const int wordSize,
            char *word) {}

char *readWord(int *wordSize) {
    printf("How many characters are there in the word?\n");
    scanf(" %d",wordSize);
    char *word = malloc((*wordSize + 1) * sizeof(char));

    if (word == NULL) {
        printf("Memory allocation failed\n");
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




bool inBounds(int row, int col, const int Size) {}

// void printWordPuzzle(const int Size, char puzzle[][Size]) {
//     for (int i=0; i<Size;i++){
//         for(int j = 0; j<Size;j++){
//             printf("%c\n", &puzzle[i][j]);
//         }
//     }
// }

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
        printf("%c ", *(word+i));
    }
}

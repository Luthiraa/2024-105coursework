#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
int dotProduct(int arrA[], int arrB[]);
int countOccurrences(const char *str, const char *sub) {
    int count = 0;
    int subLen = strlen(sub);

    // Find the first occurrence of sub in str
    char *pos = strstr(str, sub);

    // Repeat until no more occurrences are found
    while (pos != NULL) {
        count++;

        // Move the pointer past the last occurrence to search for the next one
        pos += subLen;

        // Find the next occurrence of sub in str
        pos = strstr(pos, sub);
    }

    return count;
}

int main() {
    char str[] = "ababababab";
    char sub[] = "ab";

    int occurrences = countOccurrences(str, sub);

    printf("Number of occurrences: %d\n", occurrences);

    return 0;
}
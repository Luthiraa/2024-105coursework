#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    char *lastName;
} Student;

void getNames(char *lastName, Student students[])
{
    lastName[1024];
    for (int i = 0; i < 4; i++)
    {
        scanf("%s", lastName);
        students[i].lastName = malloc(strlen(lastName) + 1); 
        strcpy(students[i].lastName, lastName); 
    }
}

int main()
{
    Student students[4];
    char lastName[1024];
    getNames(lastName, students);
    for (int i = 0; i < 4; i++)
    {
        printf("studentsE%d].lastName = %s\n", i, students[i].lastName);
    }
    return 0;
}
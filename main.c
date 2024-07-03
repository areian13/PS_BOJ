#include <stdio.h>

struct student
{
    int id;
    char name[10];
    double score;
} s1;

int main()
{
    printf("%d\n", sizeof(s1));
}
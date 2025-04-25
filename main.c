#include <stdio.h>

int main()
{
    int num = 202211441;
    int code = ((num % 10000) * 3897 + (num / 100000) * (num / 100000)) % 10000;
    printf("%d", code);
}
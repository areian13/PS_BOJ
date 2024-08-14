#include <iostream>
#include <cstdio>
#include <ctime>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    time_t timer = time(NULL);
    tm* t = localtime(&timer);

    printf("%d-%02d-%02d\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
}
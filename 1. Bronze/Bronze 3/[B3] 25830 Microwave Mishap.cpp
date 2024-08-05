#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int m, s;
    scanf("%d:%d", &m, &s);

    int result = 60 * 60 * m + 60 * s - (60 * m + s);
    printf("%02d:%02d:%02d\n", result / 60 / 60, result / 60 % 60, result % 60);
}
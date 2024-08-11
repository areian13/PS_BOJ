#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int h1, m1, h2, m2;
    scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);

    int minute1 = h1 * 60 + m1;
    int minute2 = h2 * 60 + m2;

    int result = minute2 + (24 * 60 - minute1);
    printf("%02d:%02d", result / 60, result % 60);
}
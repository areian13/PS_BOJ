#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int y, m, d, n;
    scanf("%d-%d-%d\n%d", &y, &m, &d, &n);

    int day = y * 12 * 30 + (m - 1) * 30 + (d - 1) + n;
    printf("%d-%02d-%02d\n", day / 12 / 30, day % (12 * 30) / 30 + 1, day % 30 + 1);
}
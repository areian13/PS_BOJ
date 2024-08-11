#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    scanf("%d", &n);

    int secSum = 0;
    for (int i = 0; i < n; i++)
    {
        int m, s;
        scanf("%d:%d", &m, &s);

        secSum += 60 * m + s;
    }
    printf("%02d:%02d:%02d\n", secSum / 60 / 60, secSum / 60 % 60, secSum % 60);
}
#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int h, m, n;
    scanf("%02d:%02d\n%d", &h, &m, &n);

    while (n > 0)
    {
        if (m == 0)
            n -= h;
        else if (m % 15 == 0)
            n--;
        m++;

        if (m == 60)
        {
            m = 0;
            h++;
        }
        if (h == 13)
            h = 1;
    }
    m--;
    printf("%02d:%02d\n", h, m);
}
#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, c;
    scanf("%d %d", &n, &c);

    int time = -c * (n - 1);
    for (int i = 0; i < n; i++)
    {
        int m, s;
        scanf("%d:%d", &m, &s);
        time += 60 * m + s;
    }

    int h = time / 3600;
    int m = (time / 60) % 60;
    int s = time % 60;
    printf("%02d:%02d:%02d\n", h, m, s);
}
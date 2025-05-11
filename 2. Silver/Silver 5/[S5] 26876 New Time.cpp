#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int h1, m1, h2, m2;
    scanf("%d:%d\n%d:%d", &h1, &m1, &h2, &m2);

    int c1 = h1 * 60 + m1;
    int c2 = h2 * 60 + m2;
    if (c1 > c2)
        c2 += 24 * 60;

    int result = (c2 - c1) / 60 + (c2 - c1) % 60;
    cout << result << '\n';
}
#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define PI 3.14159265359

double GetA(int h, int m, int s, int u)
{
    return h * 30.0 + m / 2.0 + s / 120.0 + u / 12000.0;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        int h1, m1, s1, u1;
        cin >> h1 >> m1 >> s1 >> u1;

        double a1 = GetA(h1, m1, s1, u1);

        int h2, m2, s2, u2;
        cin >> h2 >> m2 >> s2 >> u2;

        double a2 = GetA(h2, m2, s2, u2);

        double r;
        cin >> r;

        double result = PI * r * r * (a2 - a1) / 360.0;
        printf("%d. %.3lf\n", t, result);
    }
}
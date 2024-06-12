#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        double p, q;
        cin >> p >> q;

        double result = 1 / ((1 / p) + (1 / q));
        printf("f = %.1lf\n", result);
    }
}
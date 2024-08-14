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
        double d, f, p;
        cin >> d >> f >> p;

        double result = d * f * p;
        printf("$%.2lf\n", result);
    }
}
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        string t, e;
        double v;
        cin >> t >> e >> v;

        double result = (t == "H" ? -log10(v) : 14 + log10(v));
        printf("%.2lf\n", result);
    }
}
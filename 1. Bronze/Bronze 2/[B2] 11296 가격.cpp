#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    unordered_map<char, double> s;
    s['R'] = 0.55;
    s['G'] = 0.70;
    s['B'] = 0.80;
    s['Y'] = 0.85;
    s['O'] = 0.90;
    s['W'] = 0.95;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        double p;
        char c, k, w;
        cin >> p >> c >> k >> w;

        double result = p * s[c] * (k == 'C' ? 0.95 : 1.00);
        result = round(result * 100) / 100;

        if (w == 'C')
            result = ceil(result * 10 - 0.5) / 10;

        printf("$%.2lf\n", result);
    }
}
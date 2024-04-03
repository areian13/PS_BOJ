#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

int main()
{
    FastIO;

    string s;
    cin >> s;

    double sum = 0;
    int n = 0;
    for (char c : s)
    {
        if (c == '+')
            sum += 0.5;
        else
        {
            sum += max(4 - (c - 'A'), 0);
            n++;
        }
    }

    double result = sum / n;
    lf(4);
    cout << result << '\n';
}
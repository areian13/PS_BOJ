#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsAbsurd(int c)
{
    int r = c;

    int l = log10(c) + 1;
    double s = c * 0.95;
    double e = c * 1.05;

    while (c % 10 == 0)
        c /= 10;

    int k = log10(c) + 1;
    int d = c % 10;
    c /= 10;
    c *= 10;
    if (d > 5)
        c += 5;

    int p = pow(10, l - k);
    for (int i = 0; i < 2; i++)
    {
        int t = c * p;
        if (r != t && s <= t && t <= e)
            return true;
        c += 5;
    }
    return false;
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int i = 1; i <= TC; i++)
    {
        int c;
        cin >> c;

        bool result = IsAbsurd(c);
        if (result == true)
            cout << "absurd" << '\n';
        else
            cout << "not absurd" << '\n';
    }
}
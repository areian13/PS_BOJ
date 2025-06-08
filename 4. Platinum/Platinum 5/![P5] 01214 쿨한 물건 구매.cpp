#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int d, p, q;
    cin >> d >> p >> q;

    for (int b = 0; (b + 1) * q <= d; b++)
    {
        int a = (d - b * q + p - 1) / p;
        cout << a * p + b * q << '\n';
    }
    for (int a = 0; (a + 1) * p <= d; a++)
    {
        int b = (d - a * p + q - 1) / q;
        cout << a * p + b * q << '\n';
    }
}
#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int main()
{
    FastIO;

    array<int, 6> d1;
    for (int i = 0; i < 6; i++)
        cin >> d1[i];

    array<int, 6> d2;
    for (int i = 0; i < 6; i++)
        cin >> d2[i];

    int p = 0;
    int q = 36;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
            p += (d1[i] > d2[j]);
    }

    int gcd = GCD(p, q);
    p /= gcd;
    q /= gcd;
    cout << p << '/' << q << '\n';
}
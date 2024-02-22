#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long GCD(long long a, long long b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int main()
{
    FastIO;

    long double k;
    cin >> k;

    long long p = k * 1e+8;
    long long q = 1e+8;

    long long gcd = GCD(p, q);
    p /= gcd;
    q /= gcd;

    cout << "YES" << '\n' << p << ' ' << q << '\n';
}

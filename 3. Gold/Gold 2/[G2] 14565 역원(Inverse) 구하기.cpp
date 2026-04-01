#include <iostream>
#include <numeric>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

pair<long long, long long> xgcd(long long a, long long b)
{
    if (b == 0) return { 1,0 };
    auto [x, y] = xgcd(b, a % b);
    return { y, x - (a / b) * y };
}
long long Inv(long long a, long long mod)
{
    if (gcd(a, mod) != 1) return -1;
    return (xgcd(a, mod).first + mod) % mod;
}

int main()
{
    FastIO;

    long long n, a;
    cin >> n >> a;

    long long p = n - a;
    long long q = Inv(a, n);
    cout << p << ' ' << q << '\n';
}
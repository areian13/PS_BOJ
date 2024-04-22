#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MOD 1'000'000'007

long long Pow(long long a, long long x)
{
    if (x == 1)
        return a % MOD;

    long long result = Pow(a, x / 2) % MOD;
    result *= result;
    result %= MOD;

    if (x % 2 == 1)
    {
        result *= a % MOD;
        result %= MOD;
    }
    return result;
}

int main()
{
    FastIO;

    long long a, x;
    cin >> a >> x;

    long long result = Pow(a, x);
    cout << result << '\n';
}
#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MAX = 4'000'000;
const int MOD = 1'000'000'007;
vector<int> fact(MAX + 1), invFact(MAX + 1);

long long Pow(long long a, long long b)
{
    long long result = 1;
    while (b)
    {
        if (b & 1)
            result = result * a % MOD;
        b >>= 1, a = a * a % MOD;
    }
    return result;
}

int main()
{
    FastIO;

    fact[0] = 1;
    for (int i = 1; i <= MAX; i++)
        fact[i] = 1LL * fact[i - 1] * i % MOD;

    invFact[MAX] = Pow(fact[MAX], MOD - 2);
    for (int i = MAX - 1; i >= 0; i--)
        invFact[i] = 1LL * invFact[i + 1] * (i + 1) % MOD;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n, k;
        cin >> n >> k;

        int result = (1LL * fact[n] * invFact[k] % MOD) * invFact[n - k] % MOD;
        cout << result << '\n';
    }
}
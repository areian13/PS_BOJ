#include <iostream>
#include <vector>
#include <bit>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MAX = 1'000'000;
vector<bool> isPrime(MAX + 1, true);
void GetPrime()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAX; i++)
    {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= MAX; j += i)
            isPrime[j] = false;
    }
}

const int MOD = 998'244'353;
const int W = 3;

int Power(int a, int b)
{
    int c = 1;
    while (b)
    {
        if (b & 1)
            c = 1LL * c * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return c;
}
void NTT(vector<int>& v, bool inv = false)
{
    int n = v.size();

    vector<int> rev(n, 0);
    for (int i = 0; i < n; i++)
    {
        rev[i] = rev[i >> 1] >> 1;
        if (i & 1) rev[i] |= n >> 1;
        if (i < rev[i]) swap(v[i], v[rev[i]]);
    }

    int x = Power(W, (MOD - 1) / n);
    if (inv) x = Power(x, MOD - 2);

    vector<int> root(n);
    root[0] = 1;
    for (int i = 1; i < n; i++)
        root[i] = 1LL * root[i - 1] * x % MOD;

    for (int i = 2; i <= n; i <<= 1)
    {
        int step = n / i;
        for (int j = 0; j < n; j += i)
        {
            for (int k = 0; k < i >> 1; k++)
            {
                int p = v[j | k];
                int q = 1LL * v[j | k | i >> 1] * root[step * k] % MOD;
                v[j | k] = (1LL * p + q) % MOD;
                v[j | k | i >> 1] = (1LL * p - q) % MOD;
                if (v[j | k | i >> 1] < 0) v[j | k | i >> 1] += MOD;
            }
        }
    }

    if (inv)
    {
        int t = Power(n, MOD - 2);
        for (int i = 0; i < n; i++)
            v[i] = 1LL * v[i] * t % MOD;
    }
}

const int S_MAX = bit_ceil(1u * MAX) * 2;
vector<int> goldbach(S_MAX);
void GetGoldbach()
{
    vector<int> v(S_MAX, 0);
    for (int i = 0; i <= MAX; i++)
        v[i] = isPrime[i];
    NTT(v, false);

    for (int i = 0; i < S_MAX; i++)
        goldbach[i] = 1LL * v[i] * v[i] % MOD;
    NTT(goldbach, true);

    for (int i = 0; i <= MAX; i++)
        goldbach[i] = goldbach[i] / 2 + isPrime[i / 2];
}

int main()
{
    FastIO;

    GetPrime();
    GetGoldbach();

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        cout << goldbach[n] << '\n';
    }
}
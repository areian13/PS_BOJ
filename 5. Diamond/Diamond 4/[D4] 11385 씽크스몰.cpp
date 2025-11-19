#include <iostream>
#include <vector>
#include <bit>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#ifndef ONLINE_JUDGE
#define __int128 long long
#endif

const long long MOD = 9'223'372'036'737'335'297;
const int W = 3;

long long Power(long long a, long long b)
{
    long long c = 1;
    while (b)
    {
        if (b & 1)
            c = (__int128)c * a % MOD;
        a = (__int128)a * a % MOD;
        b >>= 1;
    }
    return c;
}
void NTT(vector<long long>& v, bool inv = false)
{
    int n = v.size();

    vector<long long> rev(n, 0);
    for (int i = 0; i < n; i++)
    {
        rev[i] = rev[i >> 1] >> 1;
        if (i & 1) rev[i] |= n >> 1;
        if (i < rev[i]) swap(v[i], v[rev[i]]);
    }

    long long x = Power(W, (MOD - 1) / n);
    if (inv) x = Power(x, MOD - 2);

    vector<long long> root(n);
    root[0] = 1;
    for (int i = 1; i < n; i++)
        root[i] = (__int128)root[i - 1] * x % MOD;

    for (int i = 2; i <= n; i <<= 1)
    {
        int step = n / i;
        for (int j = 0; j < n; j += i)
        {
            for (int k = 0; k < i >> 1; k++)
            {
                long long p = v[j | k];
                long long q = (__int128)v[j | k | i >> 1] * root[step * k] % MOD;
                v[j | k] = ((__int128)p + q) % MOD;
                v[j | k | i >> 1] = ((__int128)p - q) % MOD;
                if (v[j | k | i >> 1] < 0) v[j | k | i >> 1] += MOD;
            }
        }
    }

    if (inv)
    {
        long long t = Power(n, MOD - 2);
        for (int i = 0; i < n; i++)
            v[i] = (__int128)v[i] * t % MOD;
    }
}

void Multiply(vector<long long> a, vector<long long> b, vector<long long>& c)
{
    int n = bit_ceil(max(a.size(), b.size())) * 2;
    a.resize(n), b.resize(n), c.resize(n);
    NTT(a, false), NTT(b, false);

    for (int i = 0; i < n; i++)
        c[i] = (__int128)a[i] * b[i] % MOD;
    NTT(c, true);
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;
    n++, m++;

    vector<long long> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    vector<long long> c;
    Multiply(a, b, c);
    long long result = 0;
    for (long long f : c)
        result ^= f;
    cout << result << '\n';
}
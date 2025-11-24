#include <iostream>
#include <vector>
#include <bit>
#include <numeric>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

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

void Multiply(vector<int> a, vector<int> b, vector<int>& c)
{
    int n = bit_ceil(max(a.size(), b.size())) * 2;
    a.resize(n), b.resize(n), c.resize(n);
    NTT(a, false), NTT(b, false);

    for (int i = 0; i < n; i++)
        c[i] = 1LL * a[i] * b[i] % MOD;
    NTT(c, true);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n, 0), b(n, 0), c;
    for (int i = 1; i < n; i++)
    {
        a[1LL * i * i % n]++;
        b[2LL * i * i % n]++;
    }

    Multiply(a, a, c);
    long long result = 0;
    for (int i = 1; i < n; i++)
    {
        int k = 1LL * i * i % n;
        int t = c[k] + c[k + n];
        int s = b[k];
        result += (t - s) / 2 + s;
    }
    cout << result << '\n';
}
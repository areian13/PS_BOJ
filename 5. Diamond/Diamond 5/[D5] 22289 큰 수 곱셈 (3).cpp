#include <iostream>
#include <string>
#include <vector>
#include <bit>
#include <algorithm>

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

struct big_int
{
    string v;
    friend istream& operator >> (istream& is, big_int& bi)
    {
        is >> bi.v;
        reverse(bi.v.begin(), bi.v.end());
        return is;
    }
    friend ostream& operator << (ostream& os, big_int& bi)
    {
        string& v = bi.v;
        for (auto it = v.rbegin(); it != v.rend(); it++)
            os << *it;
        return os;
    }

    friend big_int operator * (const big_int& a, const big_int& b)
    {
        int n = bit_ceil(max(a.v.size(), b.v.size())) * 2;
        vector<int> av(n, 0), bv(n, 0);
        ToVec(a.v, av), ToVec(b.v, bv);

        NTT(av, false), NTT(bv, false);

        vector<int> cv(n);
        for (int i = 0; i < n; i++)
            cv[i] = 1LL * av[i] * bv[i] % MOD;

        NTT(cv, true);

        big_int c;
        c.v.resize(n);

        long long carry = 0;
        for (int i = 0; i < n; i++)
        {
            long long value = cv[i] + carry;
            c.v[i] = value % 10 + '0';
            carry = value / 10;
        }
        while (carry > 0)
        {
            c.v += carry % 10 + '0';
            carry /= 10;
        }
        while (c.v.size() > 1 && c.v.back() == '0')
            c.v.pop_back();

        return c;
    }

    static void ToVec(const string& s, vector<int>& v)
    {
        int n = s.size();
        for (int i = 0; i < n; i++)
            v[i] = s[i] - '0';
    }
};

int main()
{
    FastIO;

    big_int a, b;
    cin >> a >> b;

    big_int result = a * b;
    cout << result << '\n';
}
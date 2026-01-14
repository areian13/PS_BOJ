#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <bit>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Fraction
{
    long long p, q;

    Fraction() : p(0), q(0) {}
    Fraction(long long p, long long q) : p(p), q(q) {}

    friend Fraction operator + (const Fraction& a, const Fraction& b)
    {
        long long p = a.p + b.p;
        long long q = a.q + b.q;
        return Fraction(p, q);
    }
    friend Fraction& operator += (Fraction& a, const Fraction& b)
    {
        return a = a + b;
    }
};

Fraction PSW(int d, unsigned int select, vector<int>& a, vector<int>& l,
    vector<vector<Fraction>>& dp, vector<int>& p)
{
    int n = a.size();
    int k = dp.size();
    if (popcount(select) == n) return { !d,1 };
    Fraction& result = dp[d][select];
    if (result.p != -1) return result;

    result = { 0,0 };
    for (int i = 0; i < n; i++)
    {
        if (select & (1 << i)) continue;

        int nd = (d * p[l[i] - 1] + a[i]) % k;
        result += PSW(nd, select | (1 << i), a, l, dp, p);
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<string> ta(n);
    for (int i = 0; i < n; i++)
        cin >> ta[i];

    int k;
    cin >> k;

    vector<int> a(n, 0), l(n);
    for (int i = 0; i < n; i++)
    {
        l[i] = ta[i].size();
        for (char c : ta[i])
        {
            a[i] *= 10;
            a[i] += c - '0';
            a[i] %= k;
        }
    }
    vector<int> p(50, 10);
    for (int i = 1; i < 50; i++)
        p[i] = p[i - 1] * 10 % k;

    vector<vector<Fraction>> dp(k, vector<Fraction>(1 << n, { -1,-1 }));
    Fraction result = PSW(0, 0, a, l, dp, p);
    long long g = gcd(result.p, result.q);
    cout << result.p / g << '/' << result.q / g << '\n';
}
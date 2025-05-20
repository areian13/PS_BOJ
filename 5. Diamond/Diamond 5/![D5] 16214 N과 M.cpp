#include <iostream>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#ifndef ONLINE_JUDGE
#define __int128 long long
#endif

typedef long long ll;

namespace miller_rabin
{
    ll mul(ll x, ll y, ll mod) { return (__int128)x * y % mod; }
    ll power(ll x, ll y, ll p)
    {
        ll result = 1, temp = x % p;
        while (y > 0)
        {
            if (y % 2 == 1)
                result = mul(result, temp, p);
            temp = mul(temp, temp, p);
            y /= 2;
        }
        return result % p;
    }
    bool miller_rabin(ll n, ll a)
    {
        if (n % a == 0)
            return true;

        ll d = n - 1;
        while (true)
        {
            ll temp = power(a, d, n);
            if (d % 2 == 1)
                return (temp == 1 || temp == n - 1);
            else if (temp == n - 1)
                return true;
            d /= 2;
        }
    }
    bool is_prime(ll n)
    {
        if (n <= 1)
            return false;
        static vector<ll> base = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
        for (auto& a : base)
        {
            if (!miller_rabin(n, a))
                return false;
        }
        return true;
    }
}

namespace pollard_rho
{
    void rho(ll n, vector<ll>& v)
    {
        if (n == 1)
            return;
        if (n % 2 == 0)
        {
            v.push_back(2);
            rho(n / 2, v);
            return;
        }
        if (miller_rabin::is_prime(n))
        {
            v.push_back(n);
            return;
        }

        ll a, b, c, g = n;
        auto f = [&](ll x) { return (c + miller_rabin::mul(x, x, n)) % n; };
        do
        {
            if (g == n)
            {
                a = b = rand() % (n - 2) + 2;
                c = rand() % 2 + 1;
            }

            a = f(a);
            b = f(f(b));
            g = gcd(abs(a - b), n);
        } while (g == 1);

        rho(g, v);
        rho(n / g, v);
    }

    vector<ll> factorize(ll n)
    {
        vector<ll> result;
        rho(n, result);
        sort(result.begin(), result.end());
        return result;
    }
}

ll phi(ll n)
{
    unordered_map<ll, int> cnt;
    for (ll factor : pollard_rho::factorize(n))
        cnt[factor]++;

    ll result = 1;
    for (auto& pa : cnt)
    {
        ll p = miller_rabin::power(pa.first, pa.second, n + 1);
        result *= p - p / pa.first;
    }
    return result;
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n, m;
        cin >> n >> m;

        int p = n;
        while (true)
        {
            int u = miller_rabin::power(p, p, m);
            if (p == u)
                break;
            p = u;
        }
        cout << p << '\n';
    }
}
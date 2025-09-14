#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 400

#ifdef ONLINE_JUDGE
#include <string>
#include <algorithm>

ostream& operator << (ostream& os, __int128 value)
{
    bool isNega = value < 0;
    if (isNega)
        value = -value;

    string result = "";
    do
    {
        result += (value % 10 + '0');
        value /= 10;
    } while (value > 0);

    if (isNega)
        result += '-';
    reverse(result.begin(), result.end());
    return os << result;
}
#else
#define __int128 long long
#endif

struct Fraction
{
    __int128 p, q;
    Fraction() : p(0), q(1) {}
    Fraction(__int128 p) : p(p), q(1) {}
    Fraction(__int128 p, __int128 q)
    {
        if (q < 0) p *= -1, q *= -1;
        __int128 g = gcd(abs(p), abs(q));
        this->p = p / g;
        this->q = q / g;
    }

    friend Fraction operator + (const Fraction& a, const Fraction& b)
    {
        return Fraction(a.p * b.q + b.p * a.q, a.q * b.q);
    }
    friend Fraction operator - (const Fraction& a, const Fraction& b)
    {
        return Fraction(a.p * b.q - b.p * a.q, a.q * b.q);
    }
    friend Fraction operator * (const Fraction& a, const Fraction& b)
    {
        return Fraction(a.p * b.p, a.q * b.q);
    }

    friend ostream& operator << (ostream& os, const Fraction& f)
    {
        os << f.p;
        if (f.q != 1)
            os << '/' << f.q;
        return os;
    }
};

int main()
{
    FastIO;

    vector<vector<Fraction>> dp(MAX + 1, vector<Fraction>(MAX + 2, 1));
    for (int i = 1; i <= MAX; i++)
    {
        Fraction sum = Fraction(0);
        for (int j = i + 1; j >= 2; j--)
        {
            dp[i][j] = Fraction(i, j) * dp[i - 1][j - 1];
            sum = sum + dp[i][j];
        }
        dp[i][1] = Fraction(1) - sum;
    }

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int m, k;
        cin >> m >> k;

        cout << dp[m][k] << '\n';
    }
}
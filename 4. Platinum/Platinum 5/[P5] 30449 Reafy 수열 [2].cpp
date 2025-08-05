#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Fraction
{
    int p, q;

    Fraction(int p, int q) : p(p), q(q) {}
    friend bool operator != (const Fraction& a, const Fraction& b)
    {
        return a.p != b.p || a.q != b.q;
    }
    friend bool operator < (const Fraction& a, const Fraction& b)
    {
        int ap = a.p * b.q;
        int bp = b.p * a.q;
        return ap < bp;
    }
};

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;
    k--;

    vector<Fraction> fs;
    fs.push_back({ 0,1 });
    fs.push_back({ 1,1 });
    for (int q = 2; q <= n; q++)
    {
        for (int p = 1; p < q; p += 1 + ~(q & 1))
        {
            if (gcd(p, q) == 1)
                fs.push_back({ p,q });
        }
    }

    nth_element(fs.begin(), fs.begin() + k, fs.end());
    cout << fs[k].p << ' ' << fs[k].q << '\n';
}
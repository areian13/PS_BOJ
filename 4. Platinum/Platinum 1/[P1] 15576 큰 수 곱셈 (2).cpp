#include <iostream>
#include <string>
#include <vector>
#include <complex>
#include <cmath>
#include <bit>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const double PI = acos(-1);
using cpx = complex<double>;
using cpxs = vector<cpx>;

void FFT(cpxs& c, const cpx& w)
{
    int n = c.size();
    if (n == 1)
        return;

    cpxs even(n / 2), odd(n / 2);
    for (int i = 0; i < n; i++)
        (i % 2 == 0 ? even : odd)[i / 2] = c[i];

    FFT(even, w * w);
    FFT(odd, w * w);

    cpx wp(1, 0);
    for (int i = 0; i < n / 2; i++) {
        c[i] = even[i] + wp * odd[i];
        c[i + n / 2] = even[i] - wp * odd[i];
        wp *= w;
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
        cpxs ac, bc;
        ToCpxs(a.v, ac), ToCpxs(b.v, bc);

        int n = bit_ceil(max(ac.size(), bc.size())) * 2;
        ac.resize(n), bc.resize(n);

        cpx w(cos(2 * PI / n), sin(2 * PI / n));
        FFT(ac, w), FFT(bc, w);

        cpxs cc(n);
        for (int i = 0; i < n; i++)
            cc[i] = ac[i] * bc[i];

        FFT(cc, conj(w));
        for (int i = 0; i < n; i++)
            cc[i] /= n;

        big_int c;
        c.v.resize(n);
        int carry = 0;
        for (int i = 0; i < n; i++)
        {
            int value = round(cc[i].real()) + carry;
            c.v[i] = value % 10 + '0';
            carry = value / 10;
        }
        while (carry > 0)
        {
            c.v.push_back(carry % 10 + '0');
            carry /= 10;
        }
        while (c.v.size() > 1 && c.v.back() == '0')
            c.v.pop_back();
        return c;
    }

    static void ToCpxs(const string& s, cpxs& c)
    {
        int n = s.size();
        c.resize(n);
        for (int i = 0; i < n; i++)
            c[i] = s[i] - '0';
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
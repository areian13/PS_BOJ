#include <iostream>
#include <string>
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const double PI = acos(-1);

void StrToCpxs(string& str, vector<complex<double>>& cpxs)
{
    int n = str.size();
    cpxs.resize(n);
    for (int i = 0; i < n; i++)
        cpxs[i] = str[n - 1 - i] - '0';
}

void FFT(vector<complex<double>>& f, complex<double> w)
{
    int n = f.size();
    if (n == 1)
        return;

    vector<complex<double>> even(n / 2), odd(n / 2);
    for (int i = 0; i < n; i++)
        (i % 2 == 0 ? even : odd)[i / 2] = f[i];

    FFT(even, w * w);
    FFT(odd, w * w);

    complex<double> wp(1, 0);
    for (int i = 0; i < n / 2; i++) {
        f[i] = even[i] + wp * odd[i];
        f[i + n / 2] = even[i] - wp * odd[i];
        wp *= w;
    }
}

vector<int> Multiply(string& a, string& b)
{
    vector<complex<double>> ac;
    StrToCpxs(a, ac);

    vector<complex<double>> bc;
    StrToCpxs(b, bc);

    int r = ceil(log2(max(ac.size(), bc.size()))) + 1;
    int n = 1 << r;

    ac.resize(n);
    bc.resize(n);

    complex<double> w(cos(2 * PI / n), sin(2 * PI / n));
    FFT(ac, w);
    FFT(bc, w);

    vector<complex<double>> c(n);
    for (int i = 0; i < n; i++)
        c[i] = ac[i] * bc[i];

    FFT(c, conj(w));
    for (int i = 0; i < n; i++)
        c[i] /= n;

    vector<int> result(n);
    int carry = 0;
    for (int i = 0; i < n; i++)
    {
        int value = round(c[i].real()) + carry;
        result[i] = value % 10;
        carry = value / 10;
    }
    while (carry > 0)
    {
        result.push_back(carry % 10);
        carry /= 10;
    }
    while (result.size() > 1 && result.back() == 0)
        result.pop_back();

    return result;
}

int main()
{
    FastIO;

    string a, b;
    cin >> a >> b;

    auto result = Multiply(a, b);
    for (auto it = result.rbegin(); it != result.rend(); it++)
        cout << *it;
    cout << '\n';
}
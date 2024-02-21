#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf cout.unsetf(ios::scientific);

using namespace std;

#define c 299792458.0

int main()
{
    FastIO;

    double a, b;
    cin >> a >> b;

    double result = (a + b) / (1 + (a * b) / (c * c));

    lf(9);
    cout << result << '\n';
}
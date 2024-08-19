#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;


int main()
{
    FastIO;

    int d1, d2, d3;
    cin >> d1 >> d2 >> d3;

    double a = (d1 - d3 + d2) / 2.0;
    double b = d1 - a;
    double c = d2 - a;

    if (a <= 0 || b <= 0 || c <= 0)
        cout << -1 << '\n';
    else
    {
        lf(1);
        cout << 1 << '\n';
        cout << a << ' ' << b << ' ' << c << '\n';
    }
}
#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf cout.unsetf(ios::scientific);

using namespace std;

int main()
{
    FastIO;

    double k, d1, d2;
    cin >> k >> d1 >> d2;

    double x = (d1 - d2) / 2;
    
    lf(6);
    double result = k * k - x * x;
    cout << result << '\n';
}
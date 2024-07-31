#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

int main()
{
    FastIO;

    double a;
    cin >> a;

    lf(6);
    double result = sqrt(2 * a * sqrt(3)) * 2;
    cout << result << '\n';
}
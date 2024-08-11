#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

#define PI 3.14159265359

int main()
{
    FastIO;

    double a;
    cin >> a;

    double r = sqrt(a / PI) + 1;

    lf(9);
    double result = r * r * 4;
    cout << result << '\n';
}
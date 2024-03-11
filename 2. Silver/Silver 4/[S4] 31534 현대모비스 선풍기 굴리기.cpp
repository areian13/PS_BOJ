#include <iostream>
#include <algorithm>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf cout.unsetf(ios::scientific);

using namespace std;

#define PI 3.14159265359

double Trace(double w, double h)
{
    return PI * (w * w + h * h);
}

double RollFan(double a, double b, double h)
{
    if (a == b)
        return -1;

    if (b < a)
        swap(a, b);

    double x = a * h / (b - a);
    return Trace(b, h + x) - Trace(a, x);
}

int main()
{
    FastIO;

    double a, b, h;
    cin >> a >> b >> h;

    double result = RollFan(a, b, h);
    lf(6);
    cout << result << '\n';
}
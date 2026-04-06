#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

double BatteryTime(double t, double p)
{
    if (p > 20)
        return (p + 20) *t / (100 - p);
    double x = (120 - p * 2) / t;
    return p * 2 / x;
}

int main()
{
    FastIO;

    int t, p;
    cin >> t >> p;

    double result = BatteryTime(t, p);
    printf("%.4lf\n", result);
}
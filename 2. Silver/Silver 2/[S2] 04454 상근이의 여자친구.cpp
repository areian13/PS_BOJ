#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); 

using namespace std;

double UsedOil(double v, double time, double a, double b, double c, double d)
{
    return (a * pow(v, 4) + b * pow(v, 3) + c * pow(v, 2) + d * v) * time;
}

double Fastest(double a, double b, double c, double d, double m, double t)
{
    double start = 0;
    double end = 1000;

    double result = 0;
    while (abs(start - end) > 0.0001)
    {
        double mid = (start + end) / 2;

        double time = m / mid;
        double usedOil = UsedOil(mid, time, a, b, c, d);
        if (usedOil <= t)
        {
            start = mid;
            result = max(result, mid);
        }
        else
            end = mid;
    }
    return result;
}

int main()
{
    FastIO;

    while (true)
    {
        double a, b, c, d, m, t;
        cin >> a >> b >> c >> d >> m >> t;

        if (cin.eof())
            break;

        double result = Fastest(a, b, c, d, m, t);
        result = (int)(result * 100) / 100.0l;
        printf("%.2lf\n", result);
    }
}
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

double MinDist(int x, int y, int d, int t)
{
    double dist = sqrt(x * x + y * y);
    if (d <= t)
        return dist;

    int k = dist / d - 1;
    dist -= k * d;

    double a = k * t + dist;
    double b = (k + 2) * t;
    double c = (k + 1) * t + abs(dist - d);

    return min({ a,b,c });
}

int main()
{
    FastIO;

    int x, y, d, t;
    cin >> x >> y >> d >> t;

    double result = MinDist(x, y, d, t);
    printf("%.9lf\n", result);
}
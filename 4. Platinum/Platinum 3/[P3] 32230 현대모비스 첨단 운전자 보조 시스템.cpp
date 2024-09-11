#include <iostream>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

#define PI 3.14159265359

struct Point
{
    long double x, y;
};

long double PolyArea(vector<Point>& points)
{
    int n = points.size();

    long double area = 0;
    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        area += (points[i].x * points[j].y);
        area -= (points[i].y * points[j].x);
    }

    long double result = abs(area) / 2.0;
    return result;
}

long double SafeArea(vector<Point>& points)
{
    int n = points.size();

    if (n <= 2)
        return 0;

    long double area = PolyArea(points);
    long double result = (area - (PI * area / (3 * sqrt(3)))) / 3;
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    lf(9);
    long double result = SafeArea(points);
    cout << result << '\n';
}
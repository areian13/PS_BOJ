#include <iostream>
#include <array>
#include <cfloat>
#include <cmath>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf cout.unsetf(ios::scientific);

using namespace std;

struct Point
{
    double x, y;

    static double Dist(const Point& a, const Point& b)
    {
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        return sqrt(dx * dx + dy * dy);
    }
    static double Incline(const Point& a, const Point& b)
    {
        if (a.x == b.x)
            return DBL_MAX;
        return (a.y - b.y) / (a.x - b.x);
    }
};

double ParallelogramGap(array<Point, 3>& points)
{
    if (Point::Incline(points[0], points[1]) == Point::Incline(points[1], points[2]))
        return -1;

    array<double, 3> dists;
    for (int i = 0; i < 3; i++)
        dists[i] = Point::Dist(points[i], points[(i + 1) % 3]);

    double maxDist = 0;
    double minDist = DBL_MAX;
    for (int i = 0; i < 3; i++)
    {
        maxDist = max(maxDist, (dists[i] + dists[(i + 1) % 3]) * 2);
        minDist = min(minDist, (dists[i] + dists[(i + 1) % 3]) * 2);
    }

    return maxDist - minDist;
}

int main()
{
    FastIO;

    array<Point, 3> points;
    for (int i = 0; i < 3; i++)
        cin >> points[i].x >> points[i].y;

    lf(10);
    double result = ParallelogramGap(points);
    cout << result << '\n';
}
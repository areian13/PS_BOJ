#include <iostream>
#include <cstdio>
#include <array>
#include <cmath>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const double EPS = 1e-9;

struct Point
{
    double x, y;

    static double Dist(const Point& a, const Point& b)
    {
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        return sqrt(dx * dx + dy * dy);
    }

    friend Point operator + (const Point& a, const Point& b)
    {
        return { a.x + b.x,a.y + b.y };
    }
    friend Point operator - (const Point& a, const Point& b)
    {
        return { a.x - b.x,a.y - b.y };
    }
    friend Point operator * (const Point& a, double v)
    {
        return { a.x * v,a.y * v };
    }
    friend Point operator / (const Point& a, double v)
    {
        return { a.x / v,a.y / v };
    }
};

double Angle(const Point& a, const Point& b, const Point& c)
{
    Point u = a - b, v = c - b;
    double dot = u.x * v.x + u.y * u.y;
    double cross = u.x * v.y - u.y * v.x;
    return atan2(abs(cross), dot);
}

Point BrocardPoint(array<Point, 3>& tri)
{
    sort(tri.begin(), tri.end(),
        [](const Point& a, const Point& b)
        {
            if (a.x != b.x)
                return a.x < b.x;
            return a.y < b.y;
        }
    );

    auto& [a, b, c] = tri;
    double cotA = 1 / tan(Angle(c, a, b));
    double cotB = 1 / tan(Angle(a, b, c));
    double cotC = 1 / tan(Angle(b, c, a));

    double w = atan(1 / (cotA + cotB + cotC));

}

int main()
{
    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        array<Point, 3> tri;
        for (auto& point : tri)
            cin >> point.x >> point.y;

        Point result = BrocardPoint(tri);
        printf("%.5lf %.5lf\n", result.x, result.y);
    }
}
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

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
};
struct Circle
{
    Point o;
    double r;

    Circle(vector<Point>& points)
    {
        int n = points.size();

        if (n <= 1)
        {
            o = { 0,0 };
            r = 0;
            return;
        }
        if (n == 2)
        {
            *this = Circle(points[0], points[1]);
            return;
        }
        if (n == 3)
        {
            *this = Circle(points[0], points[1], points[2]);
            for (int i = 0; i < 3; i++)
            {
                Circle c = Circle(points[i], points[(i + 1) % 3]);
                if (c.IsIn(points[(i + 2) % 3]) && this->r > c.r)
                    *this = c;
            }
            return;
        }

        vector<Point> hull;
        *this = MEC(n, points, hull);
    }
    Circle(const Point& a, const Point& b)
    {
        o.x = (a.x + b.x) / 2;
        o.y = (a.y + b.y) / 2;
        r = Point::Dist(a, b) / 2;
    }
    Circle(const Point& a, const Point& b, const Point& c)
    {
        double A = b.x - a.x;
        double B = b.y - a.y;
        double C = c.x - a.x;
        double D = c.y - a.y;
        double E = A * (a.x + b.x) + B * (a.y + b.y);
        double F = C * (a.x + c.x) + D * (a.y + c.y);
        double G = 2 * (A * (c.y - b.y) - B * (c.x - b.x));

        if (G == 0)
        {
            vector<Point> temp = { a,b,c };
            sort(temp.begin(), temp.end(),
                [](auto& a, auto& b)
                {
                    if (a.x != b.x)
                        return a.x < b.x;
                    return a.y < b.y;
                }
            );
            *this = Circle(temp[0], temp[2]);
            return;
        }

        o.x = (D * E - B * F) / G;
        o.y = (A * F - C * E) / G;
        r = Point::Dist(a, o);
    }

    static Circle MEC(int n, vector<Point>& points, vector<Point>& hull)
    {
        int h = hull.size();
        if (n == 0 || h == 3)
            return Circle(hull);

        Point p = points[n - 1];
        Circle result = MEC(n - 1, points, hull);
        if (result.IsIn(p))
            return result;

        hull.push_back(p);
        result = MEC(n - 1, points, hull);
        hull.pop_back();
        return result;
    }
    bool IsIn(const Point& p)
    {
        return Point::Dist(p, o) <= r;
    }
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Point> points(n);
    for (auto& point : points)
        cin >> point.x >> point.y;

    Circle result(points);
    printf("%.2lf\n", result.r * 2);
}
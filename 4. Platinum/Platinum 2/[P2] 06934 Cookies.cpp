#include <iostream>
#include <cstdio>
#include <vector>
#include <cfloat>
#include <cmath>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const double EPS = 1e-10;

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

        o = { 0,0 };
        for (int i = 0; i < n; i++)
        {
            o.x += points[i].x;
            o.y += points[i].y;
        }
        o.x /= n, o.y /= n;

        Point far;
        double preMaxDist = DBL_MAX;
        double lr = 1.0;
        while (true)
        {
            double maxDist = 0;
            for (auto& point : points)
            {
                double dist = Point::Dist(o, point);
                if (dist > maxDist)
                {
                    maxDist = dist;
                    far = point;
                }
            }

            if (abs(preMaxDist - maxDist) < EPS)
            {
                r = maxDist;
                break;
            }

            o.x += (far.x - o.x) * lr;
            o.y += (far.y - o.y) * lr;

            lr *= 0.99;
            preMaxDist = maxDist;
        }
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
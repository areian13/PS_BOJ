#include <iostream>
#include <cstdio>
#include <vector>
#include <cfloat>
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

        double lr = 1.0;
        double preMaxDist = DBL_MAX;
        while (true)
        {
            Point far;
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
    printf("%.3lf %.3lf\n", (int)round(result.o.x * 1000) / 1000., (int)round(result.o.y * 1000) / 1000.);
    printf("%.3lf\n", (int)round(result.r * 1000) / 1000.);
}
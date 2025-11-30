#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cfloat>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const double EPS = 1e-8;

struct Point
{
    double x, y, r;

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
        o = { 0,0,0 };
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
            Point far = o;
            double maxDist = 0;

            for (auto& point : points)
            {
                double dist = max(Point::Dist(o, point) - point.r, 0.);
                if (dist > maxDist)
                {
                    maxDist = dist;

                    double dx = o.x - point.x;
                    double dy = o.y - point.y;
                    double l = sqrt(dx * dx + dy * dy);

                    double ux = dx / l;
                    double uy = dy / l;

                    far = { point.x + ux * point.r,point.y + uy * point.r };
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
    for (auto& [x, y, r] : points)
        cin >> x >> y >> r;

    Circle result(points);
    printf("%.5lf\n", result.r);
}
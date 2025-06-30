#include <iostream>
#include <cstdio>
#include <vector>
#include <cfloat>
#include <cmath>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const double EPS = 1e-10;

struct Point3D
{
    double x, y, z;
};
struct Point2D
{
    double x, y;

    Point2D() { x = y = 0; }
    Point2D(const Point3D& p3, int i)
    {
        if (i == 0)
            x = p3.x, y = p3.y;
        else if (i == 1)
            x = p3.y, y = p3.z;
        else
            x = p3.z, y = p3.x;
    }

    static double Dist(const Point2D& a, const Point2D& b)
    {
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        return sqrt(dx * dx + dy * dy);
    }
};
struct Circle
{
    Point2D o;
    double r;

    Circle() { o.x = o.y = r = 0; }
    Circle(vector<Point2D>& points)
    {
        int n = points.size();
        o.x = o.y = 0;
        for (int i = 0; i < n; i++)
        {
            o.x += points[i].x;
            o.y += points[i].y;
        }
        o.x /= n, o.y /= n;

        double preMaxDist = DBL_MAX;
        double lr = 1.00;
        while (true)
        {
            Point2D far = o;
            double maxDist = 0;
            for (auto& point : points)
            {
                double dist = Point2D::Dist(o, point);
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

            preMaxDist = maxDist;
            lr *= 0.99;
        }
    }
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Point3D> points3D(n);
    for (auto& point : points3D)
        cin >> point.x >> point.y >> point.z;

    Circle result;
    result.r = DBL_MAX;
    for (int j = 0; j < 3; j++)
    {
        vector<Point2D> points2D(n);
        for (int i = 0; i < n; i++)
            points2D[i] = Point2D(points3D[i], j);

        Circle circle(points2D);
        if (result.r > circle.r)
            result = circle;
    }

    printf("%.4lf\n", result.r * 2);
}
#include <iostream>
#include <cstdio>
#include <vector>
#include <cfloat>
#include <cmath>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const double EPS = 1e-9;

struct Point3D
{
    double x, y, z;

    static double Dist(const Point3D& a, const Point3D& b)
    {
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        double dz = a.z - b.z;
        return sqrt(dx * dx + dy * dy + dz * dz);
    }
};
struct Sphere
{
    Point3D o;
    double r;

    Sphere(vector<Point3D>& points)
    {
        int n = points.size();
        
        o = { 0,0,0 };
        for (int i = 0; i < n; i++)
        {
            o.x += points[i].x;
            o.y += points[i].y;
            o.z += points[i].z;
        }
        o.x /= n, o.y /= n, o.z /= n;

        Point3D far;
        double preMaxDist = DBL_MAX;
        double lr = 1.0;
        while (true)
        {
            double maxDist = 0;
            for (auto& point : points)
            {
                double dist = Point3D::Dist(o, point);
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
            o.z += (far.z - o.z) * lr;

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

    vector<Point3D> points(n);
    for (auto& point : points)
        cin >> point.x >> point.y >> point.z;

    Sphere result(points);
    printf("%.2lf\n", result.r);
}
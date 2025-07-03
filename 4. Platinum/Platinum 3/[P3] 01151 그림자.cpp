#include <iostream>
#include <cstdio>
#include <array>
#include <algorithm>
#include <cfloat>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define INF DBL_MAX

struct Point2D
{
    double x, y;

    static double Area(vector<Point2D>& points)
    {
        int n = points.size();
        double result = 0;
        for (int i = 0; i < n; i++)
        {
            result += points[i].x * points[(i + 1) % n].y;
            result -= points[i].y * points[(i + 1) % n].x;
        }
        return abs(result) / 2;
    }
    static int CCW(const Point2D& a, const Point2D& b, const Point2D& c)
    {
        int ccw = (b.x - a.x) * (c.y - a.y)
            - (b.y - a.y) * (c.x - a.x);
        return (ccw > 0) - (ccw < 0);
    }

    friend bool operator == (const Point2D& a, const Point2D& b)
    {
        return a.x == b.x && a.y == b.y;
    }
};
struct Point3D
{
    int x, y, z;

    static Point2D ProjZ(Point3D& a, Point3D b)
    {
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        double dz = a.z - b.z;

        double t = a.z / dz;

        return { a.x - dx * t,a.y - dy * t };
    }
};
struct Cuboid
{
    Point3D a, b;

    Cuboid(Point3D& ta, Point3D& tb)
    {
        a.x = min(ta.x, tb.x), b.x = max(ta.x, tb.x);
        a.y = min(ta.y, tb.y), b.y = max(ta.y, tb.y);
        a.z = min(ta.z, tb.z), b.z = max(ta.z, tb.z);
    }
};

void MakeConvexHull(vector<Point2D>& points, vector<int>& indices)
{
    Point2D p0 = *min_element(points.begin(), points.end(),
        [](auto& a, auto& b)
        {
            if (a.y != b.y)
                return a.y < b.y;
            return a.x < b.x;
        }
    );
    sort(points.begin(), points.end(),
        [&p0](auto& a, auto& b)
        {
            int ccw = Point2D::CCW(p0, a, b);
            if (ccw != 0)
                return ccw > 0;
            if (a.y != b.y)
                return a.y < b.y;
            return a.x < b.x;
        }
    );

    int n = points.size();
    for (int k = 0; k < n; k++)
    {
        while (indices.size() > 2)
        {
            int j = indices.back();
            indices.pop_back();
            int i = indices.back();

            if (Point2D::CCW(points[i], points[j], points[k]) > 0)
            {
                indices.push_back(j);
                break;
            }
        }
        indices.push_back(k);
    }

    if (indices.size() == 2 && points[indices[0]] == points[indices[1]])
        indices.pop_back();
}

double Shadow(Cuboid& cuboid, Point3D& light)
{
    auto& [a, b] = cuboid;
    bool zx = a.x == b.x;
    bool zy = a.y == b.y;
    bool zz = a.z == b.z;

    if (zx + zy + zz >= 2)
        return 0;
    if (light.z <= a.z)
        return 0;
    if (light.z <= b.z)
        return INF;

    vector<Point3D> p3d = {
        {a.x,a.y,a.z},{a.x,a.y,b.z},
        {a.x,b.y,a.z},{a.x,b.y,b.z},
        {b.x,a.y,a.z},{b.x,a.y,b.z},
        {b.x,b.y,a.z},{b.x,b.y,b.z},
    };
    vector<Point2D> p2d(8);
    for (int i = 0; i < 8; i++)
        p2d[i] = Point3D::ProjZ(p3d[i], light);


    vector<int> indices;
    MakeConvexHull(p2d, indices);

    int h = indices.size();
    vector<Point2D> hull(h);
    for (int i = 0; i < h; i++)
        hull[i] = p2d[indices[i]];
    return Point2D::Area(hull);
}

int main()
{
    FastIO;

    array<Point3D, 3> points;
    for (auto& point : points)
        cin >> point.x >> point.y >> point.z;

    Cuboid cuboid(points[0], points[1]);
    double result = Shadow(cuboid, points[2]);
    if (result == INF)
        printf("-1\n");
    else
        printf("%.6lf\n", result);
}
#include <iostream>
#include <cstdio>
#include <vector>
#include <cfloat>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const double INF = DBL_MAX;

struct Point
{
    int x, y;

    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        long long ccw = 1LL * (b.x - a.x) * (c.y - a.y)
            - 1LL * (b.y - a.y) * (c.x - a.x);
        return (ccw > 0) - (ccw < 0);
    }
};

void MakeHull(vector<Point>& points, vector<int>& indices)
{
    Point p0 = *min_element(points.begin(), points.end(),
        [](const Point& a, const Point& b)
        {
            if (a.y != b.y) return a.y < b.y;
            return a.x < b.x;
        }
    );
    sort(points.begin(), points.end(),
        [&p0](const Point& a, const Point& b)
        {
            long long ccw = Point::CCW(p0, a, b);
            if (ccw != 0) return ccw > 0;
            if (a.y != b.y) return a.y < b.y;
            return a.x < b.x;
        }
    );

    int n = points.size();
    for (int c = 0; c < n; c++)
    {
        while (indices.size() >= 2)
        {
            int b = indices[indices.size() - 1];
            int a = indices[indices.size() - 2];

            if (Point::CCW(points[a], points[b], points[c]) > 0)
                break;
            indices.pop_back();
        }
        indices.push_back(c);
    }
}

long long TriArea(Point& a, Point& b, Point& c)
{
    long long ccw = 1LL * (b.x - a.x) * (c.y - a.y)
        - 1LL * (b.y - a.y) * (c.x - a.x);
    return abs(ccw);
}

double MaxTri(vector<Point>& hull)
{
    int n = hull.size();
    if (n <= 2) return 0;

    long long result = TriArea(hull[0], hull[1], hull[2]);
    for (int a = 0; a < n; a++)
    {
        int b = (a + 1) % n, c = (b + 1) % n;
        while (c != a)
        {
            if (TriArea(hull[a], hull[b], hull[(c + 1) % n])
                < TriArea(hull[a], hull[b], hull[c]))
                b = (b + 1) % n;
            else
                c = (c + 1) % n;

            result = max(result, TriArea(hull[a], hull[b], hull[c]));
        }
    }
    return result / 2.;
}

int main()
{
    FastIO;

    int n;
    Point p0, p1;
    cin >> n >> p0.x >> p0.y >> p1.x >> p1.y;

    double m = (p0.x == p1.x ? INF : 1. * (p1.y - p0.y) / (p1.x - p0.x));

    vector<Point> points = { p0,p1 };
    points.reserve(n + 2);
    for (int i = 0; i < n; i++)
    {
        int y, x0, x1;
        cin >> y >> x0 >> x1;

        double x = (m == INF ? p0.x : (y - p0.y + m * p0.x) / m);

        if (x0 <= x && x <= x1)
            continue;
        if (x < x0)
            points.push_back({ x0,y });
        else
            points.push_back({ x1,y });
    }

    vector<int> indices;
    MakeHull(points, indices);

    int h = indices.size();
    vector<Point> hull(h);
    for (int i = 0; i < h; i++)
        hull[i] = points[indices[i]];

    double result = MaxTri(hull);
    printf("%.1lf\n", result);
}
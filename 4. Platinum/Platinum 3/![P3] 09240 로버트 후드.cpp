#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf cout.unsetf(ios::scientific);

using namespace std;

struct Point
{
    int x, y;

    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        long long ccw = (long long)(b.x - a.x) * (c.y - a.y)
            - (long long)(b.y - a.y) * (c.x - a.x);

        if (ccw < 0)
            return -1;
        if (ccw > 0)
            return +1;
        return 0;
    }
    static int CCW(const Point& a, const Point& b,
        const Point& c, const Point& d)
    {
        Point t = { d.x - (b.x - c.x),d.y - (b.y - c.y) };
        return CCW(a, b, t);
    }
    static double Dist(const Point& a, const Point& b)
    {
        double dx = a.x - b.x;
        double dy = a.y - b.y;

        return sqrt(dx * dx + dy * dy);
    }
};

void MakeConvexHull(vector<Point>& points, vector<int>& convexHull)
{
    int n = points.size();

    Point zeroPoint = *min_element(points.begin(), points.end(),
        [](const Point& a, const Point& b)
        {
            if (a.y != b.y)
                return a.y < b.y;
            return a.x < b.x;
        }
    );
    sort(points.begin(), points.end(),
        [&zeroPoint](const Point& a, const Point& b)
        {
            int ccw = Point::CCW(zeroPoint, a, b);
            if (ccw != 0)
                return (ccw > 0);
            if (a.y != b.y)
                return a.y < b.y;
            return a.x < b.x;
        }
    );

    for (int i = 0; i < n; i++)
    {
        while (convexHull.size() >= 2)
        {
            int second = convexHull.back();
            convexHull.pop_back();
            int first = convexHull.back();

            if (Point::CCW(points[first], points[second], points[i]) > 0)
            {
                convexHull.push_back(second);
                break;
            }
        }

        convexHull.push_back(i);
    }
}

double MaxDist(vector<Point>& points)
{
    vector<int> convexHull;
    MakeConvexHull(points, convexHull);

    int p = convexHull.size();
    vector<Point> poly(p);
    for (int i = 0; i < p; i++)
        poly[i] = points[convexHull[i]];

    if (p <= 0)
        return 0;
    if (p == 2)
        return Point::Dist(poly[0], poly[1]);

    array<Point, 2> result = { Point{ 0,0 },{ 0,0 } };
    for (int i = 0, j = 1; i < p; i++)
    {
        while (j < p * 2
            && Point::CCW(poly[i], poly[(i + 1) % p], poly[j % p], poly[(j + 1) % p]) >= 0)
        {
            if (Point::Dist(result[0], result[1]) < Point::Dist(poly[i], poly[j % p]))
                result = { poly[i], poly[j % p] };
            j++;
        }

        if (Point::Dist(result[0], result[1]) < Point::Dist(poly[i], poly[j % p]))
            result = { poly[i], poly[j % p] };
    }
    return Point::Dist(result[0], result[1]);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    lf(6);
    double result = MaxDist(points);
    cout << result << '\n';
}
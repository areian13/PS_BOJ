#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y;

    static int CCW(Point a, Point b, Point c)
    {
        long long cross = 1LL * (b.x - a.x) * (c.y - a.y)
            - 1LL * (b.y - a.y) * (c.x - a.x);
        return (cross == 0 ? 0 : (cross > 0 ? +1 : -1));
    }

    static double Dist(Point a, Point b)
    {
        double dx = a.x - b.x;
        double dy = a.y - b.y;

        return sqrt(dx * dx + dy * dy);
    }

    friend Point operator-(Point a, Point b)
    {
        return { {a.x - b.x},{a.y - b.y} };
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
    for (int i = 0, j = 0; i < p; i++)
    {
        while (j + 1 < p &&
            Point::CCW(poly[i + 1] - poly[i], poly[j + 1] - poly[j], { 0,0 }) >= 0)
        {
            double dist = Point::Dist(poly[i], poly[j]);
            if (dist > Point::Dist(result[0], result[1]))
                result = { poly[i], poly[j] };
            j++;
        }
        double dist = Point::Dist(poly[i], poly[j]);
        if (dist > Point::Dist(result[0], result[1]))
            result = { poly[i], poly[j] };
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

    double result = MaxDist(points);
    printf("%.6lf\n", result);
}
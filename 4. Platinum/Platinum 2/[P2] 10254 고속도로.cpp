#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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

void MakeConvexHull(vector<int>& hullIndices, vector<Point>& points)
{
    int n = points.size();

    Point p0 = *min_element(points.begin(), points.end(),
        [](const Point& a, const Point& b)
        {
            if (a.y != b.y)
                return a.y < b.y;
            return a.x < b.x;
        }
    );
    sort(points.begin(), points.end(),
        [&p0](const Point& a, const Point& b)
        {
            int ccw = Point::CCW(p0, a, b);
            if (ccw != 0)
                return (ccw > 0);
            if (a.y != b.y)
                return a.y < b.y;
            return a.x < b.x;
        }
    );

    for (int i = 0; i < n; i++)
    {
        while (hullIndices.size() >= 2)
        {
            int second = hullIndices.back();
            hullIndices.pop_back();
            int first = hullIndices.back();

            if (Point::CCW(points[first], points[second], points[i]) > 0)
            {
                hullIndices.push_back(second);
                break;
            }
        }
        hullIndices.push_back(i);
    }
}

pair<Point, Point> GetHullDiameter(vector<Point>& hull)
{
    int n = hull.size();

    pair<Point, Point> result = { {0,0},{0,0} };
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j + 1 < n &&
            Point::CCW(hull[i + 1] - hull[i], hull[j + 1] - hull[j], { 0,0 }) >= 0)
        {
            double dist = Point::Dist(hull[i], hull[j]);
            if (dist > Point::Dist(result.first, result.second))
                result = { hull[i], hull[j] };
            j++;
        }
        double dist = Point::Dist(hull[i], hull[j]);
        if (dist > Point::Dist(result.first, result.second))
            result = { hull[i], hull[j] };
    }
    return result;
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        vector<Point> points(n);
        for (int i = 0; i < n; i++)
            cin >> points[i].x >> points[i].y;

        vector<int> hullIndices;
        MakeConvexHull(hullIndices, points);

        int h = hullIndices.size();
        vector<Point> hull(h);
        for (int i = 0; i < h; i++)
            hull[i] = points[hullIndices[i]];

        pair<Point, Point> result = GetHullDiameter(hull);
        cout << result.first.x << ' ' << result.first.y << ' ';
        cout << result.second.x << ' ' << result.second.y << '\n';
    }
}
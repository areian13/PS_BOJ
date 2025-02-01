#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    double x, y;

    static double Dist(Point a, Point b)
    {
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        return sqrt(dx * dx + dy * dy);
    }
    static int CCW(Point a, Point b, Point c)
    {
        int cross = (b.x - a.x) * (c.y - a.y)
            - (b.y - a.y) * (c.x - a.x);
        return (cross == 0 ? 0 : (cross > 0 ? +1 : -1));
    }

    friend Point operator-(Point a, Point b)
    {
        return { a.x - b.x,a.y - b.y };
    }
};

void MakeConvexHull(vector<Point>& points, vector<int>& hullIndices)
{
    Point p0 = *min_element(points.begin(), points.end(),
        [](Point& a, Point& b)
        {
            if (a.y != b.y)
                return a.y < b.y;
            return a.x < b.x;
        }
    );
    sort(points.begin(), points.end(),
        [&p0](Point& a, Point& b)
        {
            int ccw = Point::CCW(p0, a, b);
            if (ccw != 0)
                return (ccw > 0);
            if (a.y != b.y)
                return a.y < b.y;
            return a.x < b.x;
        }
    );

    int n = points.size();
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

double MinFence(vector<Point>& points)
{
    vector<int> hullIndices;
    MakeConvexHull(points, hullIndices);

    int h = hullIndices.size();
    vector<Point> hull(h);
    for (int i = 0; i < h; i++)
        hull[i] = points[hullIndices[i]];

    int left = 0, right = 0, top = 0, bottom = 0;
    double result = DBL_MAX;
    for (int i = 0; i < h; i++)
    {
        Point edge = hull[(i + 1) % h] - hull[i];

        while (Point::CCW({ 0,0 }, edge, hull[(left + 1) % h] - hull[left]) <= 0)
            left = (left + 1) % h;
        while (Point::CCW({ 0,0 }, edge, hull[(right + 1) % h] - hull[right]) >= 0)
            right = (right + 1) % h;
        while (Point::CCW({ 0,0 }, edge, hull[(top + 1) % h] - hull[top]) <= 0)
            top = (top + 1) % h;
        

        double w = Point::Dist(hull[left], hull[right]);
        double h = Point::Dist(hull[bottom], hull[top]);
        result = min(result, (w + h) * 2);
    }
    return result;
}

int main()
{
    FastIO;

    while (true)
    {
        int n;
        cin >> n;

        if (cin.eof())
            break;

        vector<Point> points(n);
        for (int i = 0; i < n; i++)
            cin >> points[i].x >> points[i].y;

        double result = MinFence(points);
        printf("%.9lf\n", result);
    }
}
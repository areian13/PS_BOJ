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
    int x, y;

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
    static double PerpendicularDist(Point a, Point b, Point c)
    {
        if (a.x == b.x)
            return abs(c.x - a.x);

        double m = 1.0 * (b.y - a.y) / (b.x - a.x);
        return abs(m * c.x - c.y + (-m * a.x + a.y)) / sqrt(m * m + 1);
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

pair<Point, Point> GetDiameterPoint(vector<Point>& points)
{
    vector<int> hullIndices;
    MakeConvexHull(points, hullIndices);

    int h = hullIndices.size();
    vector<Point> hull(h);
    for (int i = 0; i < h; i++)
        hull[i] = points[hullIndices[i]];

    pair<Point, Point> result = { {0,0},{0,0} };
    auto comp = [](pair<Point, Point> a, pair<Point, Point> b)
        {
            return Point::Dist(a.first, a.second) < Point::Dist(b.first, b.second);
        };
    for (int i = 0, j = 0; i < h; i++)
    {
        while (j + 1 < h &&
            Point::CCW(hull[i + 1] - hull[i], hull[j + 1] - hull[j], { 0,0 }) >= 0)
        {
            result = max(result, { hull[i], hull[j] }, comp);
            j++;
        }
        result = max(result, { hull[i], hull[j] }, comp);
    }
    return result;
}

double MinFence(vector<Point>& points)
{
    int n = points.size();

    auto [p0, p1] = GetDiameterPoint(points);

    array<double, 2> bothDist = { 0,0 };
    int minX = INT_MAX, minY = INT_MAX;
    int maxX = INT_MIN, maxY = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        minX = min(minX, points[i].x);
        minY = min(minY, points[i].y);
        maxX = max(maxX, points[i].x);
        maxY = max(maxY, points[i].y);

        int ccw = Point::CCW(p0, p1, points[i]);
        if (ccw == 0)
            continue;

        double dist = Point::PerpendicularDist(p0, p1, points[i]);
        bothDist[ccw < 0] = dist;
    }

    double l0 = (maxX - minX) + (maxY - minY);
    double l1 = Point::Dist(p0, p1) + bothDist[0] + bothDist[1];
    if (Point::Dist(p0, p1) == bothDist[0] + bothDist[1])
        l1 /= sqrt(2);
    return min(l0, l1) * 2;
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
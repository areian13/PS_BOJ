#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    long long x, y;

    static int CCW(Point a, Point b, Point c)
    {
        long long cross = (b.x - a.x) * (c.y - a.y)
            - (b.y - a.y) * (c.x - a.x);
        return (cross == 0 ? 0 : (cross > 0 ? +1 : -1));
    }
    static long long DistSq(Point a, Point b)
    {
        long long dx = a.x - b.x;
        long long dy = a.y - b.y;
        return dx * dx + dy * dy;
    }

    friend Point operator+(Point a, Point b)
    {
        return { a.x + b.x,a.y + b.y };
    }
    friend Point operator-(Point a, Point b)
    {
        return { a.x - b.x,a.y - b.y };
    }
    friend Point operator*(Point a, long long d)
    {
        return { a.x * d,a.y * d };
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

pair<Point, Point> GetDiameterPoint(vector<Point>& hull)
{
    int n = hull.size();

    pair<Point, Point> result = { {0,0},{0,0} };
    for (int i = 0, j = 0; i < n; i++)
    {
        while (j + 1 < n &&
            Point::CCW(hull[i + 1] - hull[i], hull[j + 1] - hull[j], { 0,0 }) >= 0)
        {
            if (Point::DistSq(hull[i], hull[j]) > Point::DistSq(result.first, result.second))
                result = { hull[i],hull[j] };
            j++;
        }
        if (Point::DistSq(hull[i], hull[j]) > Point::DistSq(result.first, result.second))
            result = { hull[i],hull[j] };
    }
    return result;
}

long long MaxDistStar(int d, vector<Point>& points, vector<Point>& dpoints)
{
    int n = points.size();

    vector<Point> npoints(n);
    for (int i = 0; i < n; i++)
        npoints[i] = points[i] + dpoints[i] * d;

    vector<int> hullIndices;
    MakeConvexHull(npoints, hullIndices);

    int h = hullIndices.size();
    vector<Point> hull(h);
    for (int i = 0; i < h; i++)
        hull[i] = npoints[hullIndices[i]];

    pair<Point, Point> diameterPoint = GetDiameterPoint(hull);
    return Point::DistSq(diameterPoint.first, diameterPoint.second);
}

pair<int, long long> MaxDistMinDay(int t, vector<Point>& points, vector<Point>& dpoints)
{
    int s = 0, e = t;
    while (e - s >= 3)
    {
        int p = (s * 2 + e) / 3, q = (s + e * 2) / 3;
        if (MaxDistStar(p, points, dpoints) > MaxDistStar(q, points, dpoints))
            s = p;
        else
            e = q;
    }

    pair<int, long long> result = { -1,LLONG_MAX };
    for (int i = s; i <= e; i++)
    {
        long long dist = MaxDistStar(i, points, dpoints);
        if (result.second > dist)
            result = { i,dist };
    }
    return result;
}

int main()
{
    FastIO;

    int n, t;
    cin >> n >> t;

    vector<Point> points(n), dpoints(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y >> dpoints[i].x >> dpoints[i].y;

    pair<int, long long> result = MaxDistMinDay(t, points, dpoints);
    cout << result.first << '\n';
    cout << result.second << '\n';
}
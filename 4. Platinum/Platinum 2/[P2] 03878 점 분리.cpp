#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

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
};

struct Line
{
    Point p1, p2;

    static bool IsCross(Line a, Line b)
    {
        int p1p2 = Point::CCW(a.p1, a.p2, b.p1) * Point::CCW(a.p1, a.p2, b.p2);
        int p3p4 = Point::CCW(b.p1, b.p2, a.p1) * Point::CCW(b.p1, b.p2, a.p2);

        if (p1p2 == 0 && p3p4 == 0)
        {
            auto point_greater_equal =
                [](const Point& a, const Point& b)
                {
                    if (a.x != b.x)
                        return a.x > b.x;
                    return a.y >= b.y;
                };

            if (point_greater_equal(a.p1, a.p2))
                swap(a.p1, a.p2);
            if (point_greater_equal(b.p1, b.p2))
                swap(b.p1, b.p2);

            return point_greater_equal(a.p2, b.p1) &&
                point_greater_equal(b.p2, a.p1);
        }
        return p1p2 <= 0 && p3p4 <= 0;
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
            long long ap = a.x - zeroPoint.x;
            long long aq = a.y - zeroPoint.y;
            long long bp = b.x - zeroPoint.x;
            long long bq = b.y - zeroPoint.y;

            if (aq * bp != ap * bq)
                return aq * bp < ap * bq;
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

void MakePoly(vector<Point>& points, vector<Point>& poly)
{
    vector<int> convexHull;
    MakeConvexHull(points, convexHull);

    for (int idx : convexHull)
        poly.push_back(points[idx]);
}

bool IsInnner(Point& p, vector<Point>& points)
{
    int n = points.size();

    int ccw = Point::CCW(points[n - 1], points[0], p);
    if (ccw == 0)
        return false;

    for (int i = 0; i < n - 1; i++)
    {
        if (Point::CCW(points[i], points[i + 1], p) != ccw)
            return false;
    }
    return true;
}

bool IsAway(vector<Point>& a, vector<Point>& b)
{
    int n = a.size();
    int m = b.size();

    for (int i = 0; i < n; i++)
    {
        Line l1 = { a[i],a[(i + 1) % n] };
        for (int j = 0; j < m; j++)
        {
            Line l2 = { b[j],b[(j + 1) % m] };
            if (Line::IsCross(l1, l2))
                return false;
        }
    }

    if (n <= 2 && m <= 2)
        return true;

    for (int i = 0; i < n; i++)
    {
        if (IsInnner(a[i], b))
            return false;
    }

    for (int i = 0; i < m; i++)
    {
        if (IsInnner(b[i], a))
            return false;
    }

    return true;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, m;
        cin >> n >> m;

        vector<Point> b(n);
        for (int i = 0; i < n; i++)
            cin >> b[i].x >> b[i].y;

        vector<Point> h(m);
        for (int i = 0; i < m; i++)
            cin >> h[i].x >> h[i].y;

        vector<Point> bPoly;
        MakePoly(b, bPoly);

        vector<Point> hPoly;
        MakePoly(h, hPoly);

        string result = IsAway(bPoly, hPoly) ? "YES" : "NO";
        cout << result << '\n';
    }
}
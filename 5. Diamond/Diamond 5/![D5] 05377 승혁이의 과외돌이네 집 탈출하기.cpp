#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cfloat>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y;

    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        long long ccw = 1LL * (b.x - a.x) * (c.y - a.y)
            - 1LL * (b.y - a.y) * (c.x - a.x);
        return (ccw > 0) - (ccw < 0);
    }
    static double Dist(const Point& a, const Point& b)
    {
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        return sqrt(dx * dx + dy * dy);
    }
    friend auto operator <=> (const Point& a, const Point& b) = default;
};
struct Line
{
    Point a, b;

    static bool OnLine(const Line& l, const Point& p)
    {
        return Point::CCW(l.a, l.b, p) == 0
            && min(l.a.x, l.b.x) <= p.x && p.x <= max(l.a.x, l.b.x)
            && min(l.a.y, l.b.y) <= p.y && p.y <= max(l.a.y, l.b.y);
    }
    static bool IsCross(const Line& l0, const Line& l1, bool bound = true)
    {
        auto& [a, b] = l0;
        auto& [c, d] = l1;

        int ab_cd = Point::CCW(a, b, c) * Point::CCW(a, b, d);
        int cd_ab = Point::CCW(c, d, a) * Point::CCW(c, d, b);

        if (ab_cd < 0 && cd_ab < 0)
            return true;
        if (!bound) return false;
        return OnLine(l0, c) || OnLine(l0, d)
            || OnLine(l1, a) || OnLine(l1, b);
    }
};

vector<Point> GetHull(vector<Point>& points) {
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
    vector<Point> hull;
    for (int c = 0; c < n; c++)
    {
        while (hull.size() >= 2)
        {
            Point& b = hull[hull.size() - 1];
            Point& a = hull[hull.size() - 2];

            if (Point::CCW(a, b, points[c]) >= 0)
                break;
            hull.pop_back();
        }
        hull.push_back(points[c]);
    }
    return hull;
}

bool IsIn(const Point& p, vector<Point>& hull)
{
    int n = hull.size();
    if (n < 3)
        return false;
    if (Point::CCW(hull[0], hull[1], p) <= 0)
        return false;
    if (Point::CCW(hull[0], hull[n - 1], p) >= 0)
        return false;

    int start = 1, end = n - 1;
    while (start + 1 < end) {
        int mid = (start + end) / 2;

        if (Point::CCW(hull[0], hull[mid], p) > 0)
            start = mid;
        else
            end = mid;
    }
    return Point::CCW(hull[start], hull[end], p) > 0;
}

double MinDist(Point& s, Point& t, vector<Point>& points)
{
    vector<Point> hull = GetHull(points);

    if (IsIn(s, hull) || IsIn(t, hull))
        return -1;

    hull.push_back(s), hull.push_back(t);
    hull = GetHull(hull);

    int n = hull.size();
    int i = 0, j = 0;
    while (i < n && hull[i] != s)
        i++;
    while (j < n && hull[j] != t)
        j++;

    if (i >= n || j >= n) return Point::Dist(s, t);

    double l = 0, r = 0;
    for (int k = i; k != j; k = (k + 1) % n)
        l += Point::Dist(hull[k], hull[(k + 1) % n]);
    for (int k = i; k != j; k = (k - 1 + n) % n)
        r += Point::Dist(hull[k], hull[(k - 1 + n) % n]);
    return min(l, r);
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        Point s, t;
        cin >> s.x >> s.y >> t.x >> t.y;

        int n;
        cin >> n;

        vector<Point> points(n);
        for (auto& [x, y] : points)
            cin >> x >> y;

        double result = MinDist(s, t, points);
        if (result == -1)
            printf("IMPOSSIBLE\n");
        else
            printf("%.3lf\n", result);
    }
}
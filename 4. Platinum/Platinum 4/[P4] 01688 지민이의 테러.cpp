#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y;

    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        long long ccw = 1LL * (b.x - a.x) * (c.y - a.y)
            - 1LL * (b.y - a.y) * (c.x - a.x);
        if (ccw > 0)
            return +1;
        if (ccw < 0)
            return -1;
        return 0;
    }
};

struct Line
{
    Point p0, p1;

    static bool OnSegment(const Point& p, const Line& l)
    {
        if (Point::CCW(l.p0, l.p1, p) != 0)
            return false;
        return min(l.p0.x, l.p1.x) <= p.x && p.x <= max(l.p0.x, l.p1.x)
            && min(l.p0.y, l.p1.y) <= p.y && p.y <= max(l.p0.y, l.p1.y);
    }
    static bool IsIntersecting(const Line& l0, const Line l1)
    {
        int ab_c = Point::CCW(l0.p0, l0.p1, l1.p0);
        int ab_d = Point::CCW(l0.p0, l0.p1, l1.p1);
        int cd_a = Point::CCW(l1.p0, l1.p1, l0.p0);
        int cd_b = Point::CCW(l1.p0, l1.p1, l0.p1);

        if (ab_c * ab_d < 0 && cd_a * cd_b < 0)
            return true;

        return OnSegment(l1.p0, l0) || OnSegment(l1.p1, l0)
            || OnSegment(l0.p0, l1) || OnSegment(l0.p1, l1);
    }
};

struct Poly
{
    vector<Point> points;
    int n;

    Poly(int n) : n(n)
    {
        points.resize(n);
    }
    bool IsIn(const Point& p)
    {
        int cnt = 0;
        Line l0 = { p,{ p.x + 1e9,p.y + 1 } };
        for (int i = 0; i < n; i++)
        {
            Line l1 = { points[i],points[(i + 1) % n] };
            if (Line::OnSegment(p, l1))
                return true;
            cnt += Line::IsIntersecting(l0, l1);
        }

        return (cnt % 2 == 1);
    }
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    Poly poly(n);
    for (int i = 0; i < n; i++)
        cin >> poly.points[i].x >> poly.points[i].y;

    for (int tc = 1; tc <= 3; tc++)
    {
        Point p;
        cin >> p.x >> p.y;

        bool result = poly.IsIn(p);
        cout << result << '\n';
    }
}
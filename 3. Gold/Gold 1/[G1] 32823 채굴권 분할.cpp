#include <iostream>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const double PI = acos(-1);

struct Point
{
    double x, y;

    Point()
    {
        x = y = 0;
    }
    Point(double t, double l)
    {
        t = t * PI / 180;

        x = l * cos(t);
        y = l * sin(t);
    }
    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        double ccw = (b.x - a.x) * (c.y - a.y)
            - (b.y - a.y) * (c.x - a.x);
        return (ccw > 0) - (ccw < 0);
    }
};
struct Line
{
    Point a, b;

    static bool OnSegment(const Line& l, const Point& p)
    {
        return Point::CCW(l.a, l.b, p) == 0
            && min(l.a.x, l.b.x) <= p.x && p.x <= max(l.a.x, l.b.x)
            && min(l.a.y, l.b.y) <= p.y && p.y <= max(l.a.y, l.b.y);
    }
    static bool IsIntersecting(const Line& l0, const Line& l1)
    {
        auto& [a, b] = l0;
        auto& [c, d] = l1;

        int ab_c = Point::CCW(a, b, c);
        int ab_d = Point::CCW(a, b, d);
        int cd_a = Point::CCW(c, d, a);
        int cd_b = Point::CCW(c, d, b);

        if (ab_c * ab_d < 0 && cd_a * cd_b < 0)
            return true;
        return OnSegment(l0, c) || OnSegment(l0, d)
            || OnSegment(l1, a) || OnSegment(l1, b);
    }
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Line> lines(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        lines[i] = { Point(a * 0.1, 1'000), Point(b * 0.1, 1'000) };
    }

    int at, al, bt, bl;
    cin >> at >> al >> bt >> bl;

    Line l = { Point(at * 0.1, al), Point(bt * 0.1, bl) };
    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += Line::IsIntersecting(l, lines[i]);

    if (cnt % 2 == 0)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}
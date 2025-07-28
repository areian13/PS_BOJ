#include <iostream>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const double PI = acos(-1);

struct Point
{
    double x, y;

    Point() { x = y = 0; }
    Point(double d, double l)
    {
        double t = d * PI / 180;
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
    static bool IsIntersecting(const Line& l1, const Line& l2)
    {
        auto& [a, b] = l1;
        auto& [c, d] = l2;

        int ab_c = Point::CCW(a, b, c), ab_d = Point::CCW(a, b, d);
        int cd_a = Point::CCW(c, d, a), cd_b = Point::CCW(c, d, b);

        if (ab_c * ab_d < 0 && cd_a * cd_b < 0)
            return true;
        return OnSegment(l1, c) || OnSegment(l1, d)
            || OnSegment(l2, a) || OnSegment(l2, b);
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
        int d1, d2;
        cin >> d1 >> d2;

        lines[i] = { Point(d1 * 0.1,1'000),Point(d2 * 0.1,1'000) };
    }

    int d1, l1, d2, l2;
    cin >> d1 >> l1 >> d2 >> l2;

    Line l = { Point(d1 * 0.1,l1),Point(d2 * 0.1,l2) };
    int cnt = 0;
    for (Line& line : lines)
        cnt += Line::IsIntersecting(l, line);

    bool result = cnt % 2 == 0;
    if (result)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}
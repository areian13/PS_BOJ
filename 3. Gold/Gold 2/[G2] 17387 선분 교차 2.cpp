#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    long long x, y;

    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        long long ccw = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
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
        return min(l.p0.x, l.p1.x) <= p.x && p.x <= max(l.p0.x, l.p1.x)
            && min(l.p0.y, l.p1.y) <= p.y && p.y <= max(l.p0.y, l.p1.y);
    }
    static bool IsIntersecting(const Line& l0, const Line& l1)
    {
        int ab_c = Point::CCW(l0.p0, l0.p1, l1.p0);
        int ab_d = Point::CCW(l0.p0, l0.p1, l1.p1);
        int cd_a = Point::CCW(l1.p0, l1.p1, l0.p0);
        int cd_b = Point::CCW(l1.p0, l1.p1, l0.p1);

        if (ab_c * ab_d < 0 && cd_a * cd_b < 0)
            return true;

        return (ab_c == 0 && OnSegment(l1.p0, l0))
            || (ab_d == 0 && OnSegment(l1.p1, l0))
            || (cd_a == 0 && OnSegment(l0.p0, l1))
            || (cd_b == 0 && OnSegment(l0.p1, l1));
    }
};

int main()
{
    FastIO;

    array<Line, 2> lines;
    for (int i = 0; i < 2; i++)
    {
        int x0, y0, x1, y1;
        cin >> x0 >> y0 >> x1 >> y1;

        lines[i] = { x0,y0,x1,y1 };
    }

    bool result = Line::IsIntersecting(lines[0], lines[1]);
    cout << result << '\n';
}
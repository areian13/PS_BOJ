#include <iostream>

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

    friend istream& operator >> (istream& is, Point& p)
    {
        is >> p.x >> p.y;
        return is;
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
    static bool IsCross(const Line& l0, const Line& l1)
    {
        auto& [a, b] = l0;
        auto& [c, d] = l1;

        int ab_cd = Point::CCW(a, b, c) * Point::CCW(a, b, d);
        int cd_ab = Point::CCW(c, d, a) * Point::CCW(c, d, b);

        if (ab_cd < 0 && cd_ab < 0)
            return true;
        return OnSegment(l0, c) || OnSegment(l0, d)
            || OnSegment(l1, a) || OnSegment(l1, b);
    }

    friend istream& operator >> (istream& is, Line& l)
    {
        is >> l.a >> l.b;
        return is;
    }
};

int main()
{
    FastIO;

    Line a, b;
    cin >> a >> b;

    bool result = Line::IsCross(a, b);
    cout << result << '\n';
}
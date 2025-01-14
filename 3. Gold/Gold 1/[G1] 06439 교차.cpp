#include <iostream>
#include <vector>

using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

struct Point
{
    int x, y;

    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        int cross = (b.x - a.x) * (c.y - a.y)
            - (b.y - a.y) * (c.x - a.x);
        return (cross == 0 ? 0 : (cross > 0 ? +1 : -1));
    }

    friend istream& operator>>(istream& is, Point& p)
    {
        is >> p.x >> p.y;
        return is;
    }
};

struct Line
{
    Point p0, p1;

    static bool OnSegment(const Line& l, const Point& p)
    {
        auto& [a, b] = l;
        if (Point::CCW(a, b, p) != 0)
            return false;
        return min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x)
            && min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
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

    friend istream& operator>>(istream& is, Line& l)
    {
        is >> l.p0 >> l.p1;
        return is;
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
        if (n < 3)
            return false;
        
        int ccw = Point::CCW(points[0], points[1], p);
        if (ccw == 0)
            return false;

        for (int i = 1; i < n; i++)
        {
            if (Point::CCW(points[i], points[(i + 1) % n], p) != ccw)
                return false;
        }
        return true;
    }
};

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        Line l0;
        cin >> l0;

        Poly poly(4);
        vector<Point>& points = poly.points;
        for (int i = 0; i < 2; i++)
        {
            cin >> points[i * 2];
            points[(i * 2 + 1) % 4].y = points[i * 2].y;
            points[(i * 2 + 3) % 4].x = points[i * 2].x;
        }

        bool result = poly.IsIn(l0.p0) || poly.IsIn(l0.p1);
        for (int i = 0; i < 4; i++)
        {
            Line l1 = { points[i],points[(i + 1) % 4] };
            result |= Line::IsIntersecting(l0, l1);
        }

        if (result == true)
            cout << 'T' << '\n';
        else
            cout << 'F' << '\n';
    }
}
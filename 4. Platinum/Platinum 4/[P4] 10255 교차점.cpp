#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    double x, y;

    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        double cross = (b.x - a.x) * (c.y - a.y)
            - (b.y - a.y) * (c.x - a.x);
        return (cross == 0 ? 0 : (cross > 0 ? +1 : -1));
    }

    friend auto operator <=> (const Point& a, const Point& b) = default;
};

struct Line
{
    Point p0, p1;

    static bool OnSegment(const Line& l, const Point& p)
    {
        auto& [a, b] = l;
        return Point::CCW(a, b, p) == 0
            && min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x)
            && min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
    }
    static set<Point> GetIntersections(const Line& l0, const Line& l1)
    {
        auto& [a, b] = l0;
        auto& [c, d] = l1;

        int ab_cd = Point::CCW(a, b, c) * Point::CCW(a, b, d);
        int cd_ab = Point::CCW(c, d, a) * Point::CCW(c, d, b);

        if (ab_cd < 0 && cd_ab < 0)
        {
            double a1 = b.y - a.y;
            double b1 = a.x - b.x;
            double c1 = a1 * a.x + b1 * a.y;

            double a2 = d.y - c.y;
            double b2 = c.x - d.x;
            double c2 = a2 * c.x + b2 * c.y;

            double d = a1 * b2 - a2 * b1;
            double x = (b2 * c1 - b1 * c2) / d;
            double y = (a1 * c2 - a2 * c1) / d;

            return { { x, y } };
        }

        set<Point> inters;
        if (OnSegment(l0, c)) inters.insert(c);
        if (OnSegment(l0, d)) inters.insert(d);
        if (OnSegment(l1, a)) inters.insert(a);
        if (OnSegment(l1, b)) inters.insert(b);
        return inters;
    }
};

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        double xm, ym, xM, yM, x1, y1, x2, y2;
        cin >> xm >> ym >> xM >> yM >> x1 >> y1 >> x2 >> y2;

        vector<Line> lines =
        {
            { xm,ym,xm,yM },{ xm,yM,xM,yM },
            { xM,yM,xM,ym },{ xM,ym,xm,ym }
        };

        Line l = { x1,y1,x2,y2 };
        set<Point> result;
        bool isInf = false;
        for (int i = 0; i < 4; i++)
        {
            set<Point> inters = Line::GetIntersections(l, lines[i]);
            if (inters.size() == 2)
            {
                isInf = true;
                break;
            }
            for (auto& it : inters)
                result.insert(it);
        }

        if (isInf)
            cout << 4 << '\n';
        else
            cout << result.size() << '\n';
    }
}
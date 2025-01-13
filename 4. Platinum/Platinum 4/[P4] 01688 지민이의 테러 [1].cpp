#include <iostream>
#include <vector>
#include <optional>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    double x, y;

    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        double ccw = (b.x - a.x) * (c.y - a.y)
            - (b.y - a.y) * (c.x - a.x);
        return (ccw == 0 ? 0 : (ccw > 0 ? +1 : -1));
    }

    friend bool operator==(const Point& a, const Point& b)
    {
        return a.x == b.x && a.y == b.y;
    }
    friend bool operator!=(const Point& a, const Point& b)
    {
        return !(a == b);
    }
};

struct Line
{
    Point p0, p1;

    static bool OnSegment(const Line& l, const Point& p)
    {
        if (Point::CCW(l.p0, l.p1, p) != 0)
            return false;
        return min(l.p0.x, l.p1.x) <= p.x && p.x <= max(l.p0.x, l.p1.x)
            && min(l.p0.y, l.p1.y) <= p.y && p.y <= max(l.p0.y, l.p1.y);
    }
    static optional<vector<Point>> SegmentIntersection(const Line& l0, const Line& l1)
    {
        auto& [a, b] = l0;
        auto& [c, d] = l1;

        int ab_c = Point::CCW(a, b, c);
        int ab_d = Point::CCW(a, b, d);
        int cd_a = Point::CCW(c, d, a);
        int cd_b = Point::CCW(c, d, b);

        if (ab_c * ab_d < 0 && cd_a * cd_b < 0)
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

            return vector<Point>{{ x,y }};
        }

        vector<Point> intersections;
        if (OnSegment(l0, c)) intersections.push_back(c);
        if (OnSegment(l0, d)) intersections.push_back(d);
        if (OnSegment(l1, a)) intersections.push_back(a);
        if (OnSegment(l1, b)) intersections.push_back(b);

        if (intersections.empty())
            return nullopt;
        if (intersections.size() == 2 && intersections[0] == intersections[1])
            return vector<Point>{intersections[0]};
        return intersections;
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
        Line l0 = { p,{ p.x + 1e9,p.y } };
        for (int i = 0; i < n; i++)
        {
            Line l1 = { points[i],points[(i + 1) % n] };
            if (Line::OnSegment(l1, p))
                return true;

            auto intersection = Line::SegmentIntersection(l0, l1);
            if (!intersection)
                continue;
            if (intersection->size() != 1)
                continue;
            if ((*intersection)[0] != l1.p1)
                cnt++;
            else
            {
                Point p2 = points[(i + 2) % n];
                if (Point::CCW(l0.p0, l0.p1, l1.p0) != Point::CCW(l0.p0, l0.p1, p2))
                    cnt++;
                i++;
            }
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
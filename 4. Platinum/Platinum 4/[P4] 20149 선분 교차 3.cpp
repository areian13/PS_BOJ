#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

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

    friend bool operator==(const Point& a, const Point& b)
    {
        return a.x == b.x && a.y == b.y;
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
    static vector<Point> GetIntersections(const Line& l0, const Line& l1)
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

            return vector<Point>{{ x, y }};
        }

        vector<Point> intersections;
        if (OnSegment(l0, c)) intersections.push_back(c);
        if (OnSegment(l0, d)) intersections.push_back(d);
        if (OnSegment(l1, a)) intersections.push_back(a);
        if (OnSegment(l1, b)) intersections.push_back(b);

        if (intersections.size() == 2 && intersections[0] == intersections[1])
            return vector<Point>{intersections[0]};
        return intersections;
    }

    friend istream& operator>>(istream& is, Line& l)
    {
        is >> l.p0 >> l.p1;
        return is;
    }
};

int main()
{
    FastIO;

    Line l0, l1;
    cin >> l0 >> l1;

    vector<Point> result = Line::GetIntersections(l0, l1);
    if (result.empty())
        printf("0\n");
    else
    {
        printf("1\n");
        if (result.size() == 1)
            printf("%.9lf %.9lf\n", result[0].x, result[0].y);
    }
}
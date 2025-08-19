#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const double EPS = 1e-6;
bool IsZero(double val) { return abs(val) < EPS; }

struct Point
{
    double x, y;

    friend auto operator <=> (const Point& a, const Point& b) = default;
    friend Point operator + (const Point& a, const Point& b) { return { a.x + b.x,a.y + b.y }; }
    friend Point operator - (const Point& a, const Point& b) { return { a.x - b.x,a.y - b.y }; }
    friend Point operator * (const Point& a, double d) { return { a.x * d,a.y * d }; }

    static double dot(const Point& a, const Point& b) { return { a.x * b.x + a.y * b.y }; }
    static double cross(const Point& a, const Point& b) { return { a.x * b.y - a.y * b.x }; }

    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        double ccw = cross(b - a, c - b);
        return (IsZero(ccw) ? 0 : (ccw > 0 ? +1 : -1));
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

        int ab_cd = Point::CCW(a, b, c) * Point::CCW(a, b, d);
        int cd_ab = Point::CCW(c, d, a) * Point::CCW(c, d, b);

        if (ab_cd < 0 && cd_ab < 0)
            return { a + (b - a) * (Point::cross(c - a, d - c) / Point::cross(b - a, d - c)) };

        set<Point> inters;
        if (OnSegment(l0, c)) inters.insert(c);
        if (OnSegment(l0, d)) inters.insert(d);
        if (OnSegment(l1, a)) inters.insert(a);
        if (OnSegment(l1, b)) inters.insert(b);
        return vector<Point>(inters.begin(), inters.end());
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
    printf("%d\n", !result.empty());
    if (result.size() == 1)
        printf("%.9lf %.9lf\n", result[0].x, result[0].y);
}
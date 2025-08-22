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

    static double dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
    static double cross(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }

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
    static int CrossType(const Line& l0, const Line& l1)
    {
        auto& [a, b] = l0;
        auto& [c, d] = l1;

        int ab_cd = Point::CCW(a, b, c) * Point::CCW(a, b, d);
        int cd_ab = Point::CCW(c, d, a) * Point::CCW(c, d, b);

        if (ab_cd < 0 && cd_ab < 0)
            return 2;

        set<Point> inters;
        if (OnSegment(l0, c)) inters.insert(c);
        if (OnSegment(l0, d)) inters.insert(d);
        if (OnSegment(l1, a)) inters.insert(a);
        if (OnSegment(l1, b)) inters.insert(b);

        if (inters.size() >= 2)
            return 3;
        return inters.size();
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

    int n;
    cin >> n;

    vector<Line> lines(n);
    for (int i = 0; i < n; i++)
        cin >> lines[i];

    vector<vector<int>> result(n, vector<int>(n, 3));
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            result[i][j] = result[j][i] = Line::CrossType(lines[i], lines[j]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << result[i][j];
        cout << '\n';
    }
}
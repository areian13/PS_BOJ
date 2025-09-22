#include <iostream>
#include <cstdio>
#include <vector>
#include <cfloat>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const double INF = DBL_MAX;

struct Point
{
    double x, y;
    bool isPort;

    static double Dist(const Point& a, const Point& b)
    {
        double dx = a.x - b.x, dy = a.y - b.y;
        return sqrtl(dx * dx + dy * dy);
    }
    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        double ccw = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
        return (ccw > 0) - (ccw < 0);
    }

    friend auto operator <=> (const Point& a, const Point& b)
    {
        if (a.x != b.x) return a.x <=> b.x;
        return a.y <=> b.y;
    }
    friend bool operator == (const Point& a, const Point& b) { return a.x == b.x && a.y == b.y; }
};

struct Line
{
    Point a, b;

    static bool OnLine(const Line& l, const Point& p)
    {
        auto& [a, b] = l;
        return Point::CCW(a, b, p) == 0
            && min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x)
            && min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
    }
    static bool IsCross(const Line& l1, const Line& l2)
    {
        auto& [a, b] = l1;
        auto& [c, d] = l2;

        int ab_cd = Point::CCW(a, b, c) * Point::CCW(a, b, d);
        int cd_ab = Point::CCW(c, d, a) * Point::CCW(c, d, b);

        if (ab_cd < 0 && cd_ab < 0)
            return true;
        return OnLine(l1, c) || OnLine(l1, d)
            || OnLine(l2, a) || OnLine(l2, b);
    }
};

bool IsInnerPoint(const Point& p, vector<Point>& points)
{
    int n = points.size();
    int cnt = 0;
    Line l1 = { p,{ p.x + 1e9,p.y + 1e-9 } };
    for (int i = 0; i < n; i++)
    {
        Line l2 = { points[i],points[(i + 1) % n] };
        if (Line::OnLine(l2, p))
            return true;
        cnt += Line::IsCross(l1, l2);
    }
    return (cnt % 2 == 1);
}
bool IsInnerLine(const Point& a, const Point& b, vector<Point>& points)
{
    if (a == b)
        return IsInnerPoint(a, points);
    if (!IsInnerPoint({ (a.x + b.x) / 2,(a.y + b.y) / 2 }, points))
        return false;

    int n = points.size();
    for (int i = 0; i < n; i++)
    {
        Point& c = points[i];
        Point& d = points[(i + 1) % n];
        if (a == c || a == d || b == c || b == d)
            continue;

        if (Line::IsCross({ a,b }, { c,d }))
            return false;
    }
    return true;
}

void FW(vector<vector<double>>& dists)
{
    int n = dists.size();
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dists[i][k] == INF || dists[k][j] == INF)
                    continue;
                dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
            }
        }
    }
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<Point> points(n);
    for (auto& point : points)
        cin >> point.x >> point.y;

    vector<Point> ports(m);
    for (auto& port : ports)
    {
        cin >> port.x >> port.y;
        port.isPort = true;

        for (int i = 0; i < points.size(); i++)
        {
            Point& p1 = points[i];
            Point& p2 = points[(i + 1) % points.size()];
            if (Line::OnLine({ p1,p2 }, port))
            {
                if (port == p1)
                    p1.isPort = true;
                else if (port == p2)
                    p2.isPort = true;
                else
                    points.insert(points.begin() + ++i, port);
                break;
            }
        }
    }
    n = points.size();

    vector<int> indices(m);
    for (int i = 0, j = 0; i < n; i++)
    {
        if (points[i].isPort)
            indices[j++] = i;
    }

    vector<vector<double>> dists(n, vector<double>(n, INF));
    for (int i = 0; i < n; i++)
    {
        Point& p1 = points[i];
        for (int j = 0; j < n; j++)
        {
            Point& p2 = points[j];
            if (IsInnerLine(p1, p2, points))
                dists[i][j] = Point::Dist(p1, p2);
        }
    }
    FW(dists);

    double result = 0;
    for (int i = 0; i < m; i++)
        result += dists[indices[i]][indices[(i + 1) % m]];
    printf("%.6lf\n", result);
}
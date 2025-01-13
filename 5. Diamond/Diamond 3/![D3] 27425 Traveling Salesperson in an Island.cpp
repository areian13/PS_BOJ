#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cfloat>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    double x, y;

    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        long long ccw = 1LL * (b.x - a.x) * (c.y - a.y)
            - 1LL * (b.y - a.y) * (c.x - a.x);
        return (ccw == 0 ? 0 : (ccw > 0 ? +1 : -1));
    }
    static double Dist(const Point& a, const Point& b)
    {
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        return sqrt(dx * dx + dy * dy);
    }

    friend bool operator==(const Point& a, const Point& b)
    {
        return a.x == b.x && a.y == b.y;
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
    static bool IsIntersecting(const Line& l0, const Line& l1)
    {
        int ab_c = Point::CCW(l0.p0, l0.p1, l1.p0);
        int ab_d = Point::CCW(l0.p0, l0.p1, l1.p1);
        int cd_a = Point::CCW(l1.p0, l1.p1, l0.p0);
        int cd_b = Point::CCW(l1.p0, l1.p1, l0.p1);

        if (ab_c * ab_d < 0 && cd_a * cd_b < 0)
            return true;

        return OnSegment(l0, l1.p0) || OnSegment(l0, l1.p1)
            || OnSegment(l1, l0.p0) || OnSegment(l1, l0.p1);
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

    bool IsIn(Point& p) const
    {
        Line l0 = { p,{p.x + 1e+9,p.y + 1e-9} };
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            Line l1 = { points[i],points[(i + 1) % n] };
            if (Line::OnSegment(l1, p))
                return true;
            cnt += Line::IsIntersecting(l0, l1);
        }
        return (cnt % 2 == 1);
    }
};

bool CanGoStraight(const Point& p0, const Point& p1, const Poly poly)
{
    Point pg = { (p0.x + p1.x) / 2,(p0.y + p1.y) / 2 };
    if (!poly.IsIn(pg))
        return false;

    int n = poly.n;
    Line l0 = { p0,p1 };
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        Line l1 = { poly.points[i],poly.points[(i + 1) % n] };
        if (Line::OnSegment(l1, p0) && Line::OnSegment(l1, p1))
            return true;

        if (l1.p0 == p0 || l1.p0 == p1)
            continue;

        cnt += Line::IsIntersecting(l0, l1);
    }
    return (cnt == 2);
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
                if (i == j)
                    continue;
                if (dists[i][k] == DBL_MAX || dists[k][j] == DBL_MAX)
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

    vector<Point> points(n + m);
    Poly poly(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
        poly.points[i] = points[i];
    }

    for (int i = 0; i < m; i++)
        cin >> points[n + i].x >> points[n + i].y;

    vector<vector<double>> dists(n + m, vector<double>(n + m, DBL_MAX));
    for (int i = 0; i < n + m - 1; i++)
    {
        for (int j = i + 1; j < n + m; j++)
        {
            if (!CanGoStraight(points[i], points[j], poly))
                continue;

            double dist = Point::Dist(points[i], points[j]);
            dists[j][i] = dists[i][j] = dist;
        }
    }
    FW(dists);

    vector<pair<Point, int>> idx(m);
    for (int i = 0; i < m; i++)
        idx[i] = { points[n + i],n + i };

    Point p0 = *min_element(points.begin() + n, points.end(),
        [](const Point& a, const Point& b)
        {
            if (a.y != b.y)
                return a.y < b.y;
            return a.x < b.x;
        }
    );
    sort(idx.begin(), idx.end(),
        [&p0](const auto& a, const auto& b)
        {
            int ccw = Point::CCW(a.first, b.first, p0);
            if (ccw != 0)
                return ccw > 0;
            if (a.first.y != b.first.y)
                return a.first.y < b.first.y;
            return a.first.x < b.first.x;
        }
    );

    int k = m - 1;
    while (k >= 1)
    {
        if (Point::CCW(p0, idx[k].first, idx[k - 1].first) != 0)
            break;
        k--;
    }
    reverse(idx.begin() + k, idx.end());

    double result = 0;
    for (int i = 0; i < m; i++)
        result += dists[idx[i].second][idx[(i + 1) % m].second];

    printf("%.7lf\n", result);
}
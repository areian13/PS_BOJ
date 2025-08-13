#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

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
    int h;

    static bool IsCross(const Line& l0, const Line& l1)
    {
        auto& [a, b, i] = l0;
        auto& [c, d, j] = l1;

        int ab_cd = Point::CCW(a, b, c) * Point::CCW(a, b, d);
        int cd_ab = Point::CCW(c, d, a) * Point::CCW(c, d, b);

        return ab_cd < 0 && cd_ab < 0;
    }

    friend istream& operator >> (istream& is, Line& l)
    {
        is >> l.a >> l.b >> l.h;
        return is;
    }
};

double Fence(int u, int v, vector<Point>& points, vector<Line>& lines)
{
    static const int n = points.size();
    static vector<vector<double>> fence(n, vector<double>(n, -1));

    if (fence[u][v] != -1)
        return fence[u][v];

    fence[u][v] = 1;
    Line l = { points[u],points[v] };
    for (Line& line : lines)
    {
        if (Line::IsCross(l, line))
            fence[u][v] *= 1.0 / line.h;
    }
    return fence[v][u] = fence[u][v];
}

double MaxFence(int d, int p, vector<vector<double>>& dp,
    vector<Point>& points, vector<Line>& lines)
{
    int n = points.size();
    int k = dp.size();

    if (d >= k)
        return Fence(p, 0, points, lines);
    if (dp[d][p] != -1)
        return dp[d][p];

    double result = 0;
    for (int i = 1; i < n; i++)
    {
        if (i == p)
            continue;

        double f = Fence(p, i, points, lines);
        double nf = MaxFence(d + 1, i, dp, points, lines);
        result = max(result, f * nf);
    }

    return dp[d][p] = result;
}

int main()
{
    FastIO;

    int n, k, f;
    cin >> n >> k >> f;
    n++;

    vector<Point> points(n);
    for (Point& point : points)
        cin >> point;

    vector<Line> lines(f);
    for (Line& line : lines)
        cin >> line;

    vector<vector<double>> dp(k, vector<double>(n, -1));
    double result = MaxFence(0, 0, dp, points, lines);
    printf("%.4e\n", result);
}
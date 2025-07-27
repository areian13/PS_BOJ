#include <iostream>
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
};

bool IsSameLine(Line& l0, Line& l1)
{
    auto& [a, b] = l0;
    auto& [c, d] = l1;

    int ab_c = Point::CCW(a, b, c), ab_d = Point::CCW(a, b, d);
    int cd_a = Point::CCW(c, d, a), cd_b = Point::CCW(c, d, b);

    if (ab_c || ab_d || cd_a || cd_b)
        return false;
    return Line::OnSegment(l0, c) || Line::OnSegment(l0, d)
        || Line::OnSegment(l1, a) || Line::OnSegment(l1, b);
}

struct UnionFind
{
    vector<int> p;
    UnionFind(int n) { p.resize(n, -1); }
    int Find(int u) { return p[u] < 0 ? u : p[u] = Find(p[u]); }
    void Union(int u, int v)
    {
        u = Find(u), v = Find(v);
        if (u == v)
            return;
        if (p[u] > p[v])
            swap(u, v);
        p[u] += p[v], p[v] = u;
    }
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Line> lines(n);
    for (int i = 0; i < n; i++)
    {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 *= 100, y1 *= 100, x2 *= 100, y2 *= 100;

        lines[i] = { (int)round(x1),(int)round(y1),
                     (int)round(x2),(int)round(y2) };
    }

    UnionFind uf(n);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (IsSameLine(lines[i], lines[j]))
                uf.Union(i, j);
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++)
        result += uf.p[i] < 0;
    cout << result << '\n';
}
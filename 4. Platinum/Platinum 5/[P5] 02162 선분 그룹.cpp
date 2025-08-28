#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y;

    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        int ccw = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
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

    static bool OnSegment(const Line& l, const Point& p)
    {
        auto& [a, b] = l;
        return Point::CCW(a, b, p) == 0
            && min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x)
            && min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
    }
    static bool IsCross(const Line& l0, const Line& l1)
    {
        auto& [a, b] = l0; auto& [c, d] = l1;

        int ab_cd = Point::CCW(a, b, c) * Point::CCW(a, b, d);
        int cd_ab = Point::CCW(c, d, a) * Point::CCW(c, d, b);

        if (ab_cd < 0 && cd_ab < 0)
            return true;
        return OnSegment(l0, c) || OnSegment(l0, d)
            || OnSegment(l1, a) || OnSegment(l1, b);
    }

    friend istream& operator >> (istream& is, Line& l)
    {
        is >> l.a >> l.b;
        return is;
    }
};

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
        if (p[u] < p[v])
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
    for (auto& line : lines)
        cin >> line;

    UnionFind uf(n);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (Line::IsCross(lines[i], lines[j]))
                uf.Union(i, j);
        }
    }

    int cnt = 0;
    int maxSize = 0;
    for (int i = 0; i < n; i++)
    {
        if (uf.Find(i) != i)
            continue;

        cnt++;
        maxSize = max(maxSize, -uf.p[i]);
    }

    cout << cnt << '\n' << maxSize << '\n';
}
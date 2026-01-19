#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const long double EPS = 1e-7;
bool IsZero(long double v) { return abs(v) < EPS; }

struct Point
{
    long double x, y;

    friend Point operator + (const Point& a, const Point& b) { return { a.x + b.x,a.y + b.y }; }
    friend Point operator - (const Point& a, const Point& b) { return { a.x - b.x,a.y - b.y }; }
    friend Point operator * (const Point& a, long double d) { return { a.x * d,a.y * d }; }

    friend long double operator * (const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
    friend long double operator / (const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }

    friend bool operator == (const Point& a, const Point& b) { return IsZero(a.x - b.x) && IsZero(a.y - b.y); }
    friend bool operator < (const Point& a, const Point& b)
    {
        if (!IsZero(a.x - b.x)) return a.x < b.x;
        return a.y < b.y;
    }

    static long double Dist(const Point& a, const Point& b)
    {
        Point d = a - b;
        return sqrt(d.x * d.x + d.y * d.y);
    }
    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        long double ccw = (b.x - a.x) * (c.y - a.y)
            - (b.y - a.y) * (c.x - a.x);
        return IsZero(ccw) ? 0 : (ccw > 0 ? +1 : -1);
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
    static vector<Point> GetInters(const Line& l0, const Line& l1)
    {
        auto& [a, b] = l0;
        auto& [c, d] = l1;

        int ab_cd = Point::CCW(a, b, c) * Point::CCW(a, b, d);
        int cd_ab = Point::CCW(c, d, a) * Point::CCW(c, d, b);

        if (ab_cd < 0 && cd_ab < 0)
            return { a + (b - a) * (((c - a) / (d - c)) / ((b - a) / (d - c))) };

        set<Point> inters;
        if (OnSegment(l0, c)) inters.insert(c);
        if (OnSegment(l0, d)) inters.insert(d);
        if (OnSegment(l1, a)) inters.insert(a);
        if (OnSegment(l1, b)) inters.insert(b);
        return vector<Point>(inters.begin(), inters.end());
    }
};
struct Block
{
    Point p;
    vector<Line> lines;
    Block(int x, int y, set<Point>& points)
    {
        p = { 1. * x,1. * y };

        long double u = y - .5, d = y + .5;
        long double l = x - .5, r = x + .5;
        Point lu = { l,u }, ru = { r,u };
        Point ld = { l,d }, rd = { r,d };

        lines.push_back({ lu,ru }), lines.push_back({ ru,rd });
        lines.push_back({ rd,ld }), lines.push_back({ ld,lu });

        points.insert(lu), points.insert(ru);
        points.insert(ld), points.insert(rd);
    }

    set<Point> GetInters(Line& l)
    {
        set<Point> inters;
        for (Line& line : lines)
        {
            for (Point& p : Line::GetInters(l, line))
                inters.insert(p);
        }
        return inters;
    }
};

long double Area(vector<Point>& poly)
{
    int n = poly.size();
    long double result = 0;
    for (int i = 0; i < n; i++)
    {
        Point& p0 = poly[i];
        Point& p1 = poly[(i + 1) % n];
        result += p0.x * p1.y;
        result -= p0.y * p1.x;
    }
    return abs(result) / 2;
}

set<Point> LightPoint(const Point& s, const Point& t, vector<Block>& blocks)
{
    Line l = { s,t + (t - s) * 1'00 };

    auto comp = [&s](const Point& a, const Point& b)
        { return Point::Dist(s, a) < Point::Dist(s, b); };
    map<Point, int, decltype(comp)> inters(comp);

    for (Block& block : blocks)
    {
        auto binter = block.GetInters(l);
        for (auto& p : binter)
            inters[p] += binter.size();
    }

    set<Point> result;
    for (auto& [p, cnt] : inters)
    {
        result.insert(p);
        if (cnt > 1)
            break;
    }
    return result;
}
bool CanGo(const Point& s, const Point& t, vector<Block>& blocks)
{
    Line l = { s,t };

    auto comp = [&s](const Point& a, const Point& b)
        { return Point::Dist(s, a) < Point::Dist(s, b); };
    map<Point, int, decltype(comp)> inters(comp);

    for (Block& block : blocks)
    {
        auto binter = block.GetInters(l);
        if (binter.size() > 1)
            return false;
        for (auto& p : binter)
        {
            inters[p]++;
            if (inters[p] > 1)
                return false;
        }
    }
    return true;
}

long double Theta(const Point& a, const Point& o, const Point& b)
{
    Point u = a - o, v = b - o;
    return atan2(u / v, u * v);
}

void MakeSimple(Point& o, vector<Point>& points, vector<Block>& blocks)
{
    sort(points.begin(), points.end(),
        [&o](const Point& a, const Point& b)
        {
            Point da = a - o, db = b - o;
            long double ta = atan2(da.y, da.x), tb = atan2(db.y, db.x);
            if (!IsZero(ta - tb)) return ta < tb;
            return Point::Dist(a, o) < Point::Dist(b, o);
        }
    );

    int n = points.size();
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j + 1 < n)
        {
            Point da = points[j + 1] - o, db = points[i] - o;
            long double ta = atan2(da.y, da.x), tb = atan2(db.y, db.x);
            if (IsZero(ta - tb))
                j++;
            else
                break;
        }

        if (j != i)
        {
            Point m = (points[i] + points[j]) * 0.5;
            Point v = points[j] - points[i];
            Point d = Point{ v.y,-v.x } *(1e-5);
            if (CanGo(o, m + d, blocks))
                reverse(points.begin() + i, points.begin() + j + 1);
            i = j;
        }
    }
}

long double Shadow(vector<vector<char>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();

    Point o;
    set<Point> points;
    vector<Block> blocks;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '*')
                o = { 1. * j,1. * i };
            if (grid[i][j] == '#')
                blocks.push_back(Block(j, i, points));
        }
    }
    int bcnt = blocks.size();
    for (int i = -1; i <= n; i++)
    {
        blocks.push_back(Block(-1, i, points));
        blocks.push_back(Block(m, i, points));
    }
    for (int j = -1; j <= m; j++)
    {
        blocks.push_back(Block(j, -1, points));
        blocks.push_back(Block(j, n, points));
    }

    set<Point> spoints;
    for (auto& p : points)
    {
        for (Point lp : LightPoint(o, p, blocks))
            spoints.insert(lp);
    }
    vector<Point> result(spoints.begin(), spoints.end());
    MakeSimple(o, result, blocks);

   /* cout << result.size() << '\n';
    for (auto [x, y] : result)
        cout << x << ' ' << y << '\n';*/

    return n * m - Area(result) - bcnt;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }
    printf("%.9llf\n", Shadow(grid));
}
#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
#include <set>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

struct Pos
{
    int r, c;
};

array<int, 9> dr = { 1,1,1,0,0,0,-1,-1,-1 };
array<int, 9> dc = { 1,0,-1,1,0,-1,1,0,-1 };

struct Edge
{
    Pos u, v;
};

const double EPS = 1e-4;
bool IsZero(double val) { return abs(val) < EPS; }

struct Point
{
    double x, y;

    friend auto operator <=> (const Point& a, const Point& b) = default;
    friend Point operator + (const Point& a, const Point& b) { return { a.x + b.x,a.y + b.y }; }
    friend Point operator - (const Point& a, const Point& b) { return { a.x - b.x,a.y - b.y }; }
    friend Point operator * (const Point& a, double d) { return { a.x * d,a.y * d }; }

    friend double operator * (const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
    friend double operator / (const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }

    static double Dist(const Point& a, const Point& b)
    {
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        return (dx * dx + dy * dy);
    }
    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        double ccw = (b - a) / (c - a);
        return (IsZero(ccw) ? 0 : (ccw > 0 ? +1 : -1));
    }
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
    static pair<int, Point> InterPoint(const Line& l0, const Line& l1)
    {
        auto& [a, b] = l0;
        auto& [c, d] = l1;

        if (OnLine(l0, c)) return { 2, c };
        if (OnLine(l0, d)) return { 2, d };
        if (OnLine(l1, a)) return { 2, a };
        if (OnLine(l1, b)) return { 2, b };

        int ab_cd = Point::CCW(a, b, c) * Point::CCW(a, b, d);
        int cd_ab = Point::CCW(c, d, a) * Point::CCW(c, d, b);

        if (ab_cd < 0 && cd_ab < 0)
            return { 1,a + (b - a) * (((c - a) / (d - c)) / ((b - a) / (d - c))) };
        return { 0,{0,0} };
    }
};
struct Rect
{
    int t;
    array<Line, 5> lines;

    Rect() : t(0) {}
    Rect(int t, int row, int col) : t(t)
    {
        double u = row - 0.5, d = row + 0.5;
        double l = col - 0.5, r = col + 0.5;
        Point lu = { l,u }, ru = { r,u };
        Point ld = { l,d }, rd = { r,d };
        Point c = { col,row };
        lines = { Line{lu,ru},{ru,rd},{rd,ld},{ld,lu},{c,c} };
    }
};

int RouteType(Pos ps0, Pos ps1, vector<vector<Rect>>& grid)
{
    if (ps0.r == ps1.r && ps0.c == ps1.c)
        return 0;

    int n = grid.size();
    int m = grid[0].size();

    Point p0 = { 1. * ps0.c,1. * ps0.r }, p1 = { 1. * ps1.c,1. * ps1.r };
    auto comp = [&p0](const auto& a, const auto& b)
        {
            double da = Point::Dist(p0, a.second);
            double db = Point::Dist(p0, b.second);

            if (!IsZero(da - db)) return da < db;
            return a.first < b.first;
        };

    pair<int, Point> close = { 5,{10'000,10'000} };
    Line l = { p0,p1 };
    int rs = max(min(ps0.r, ps1.r), 0);
    int re = min(max(ps0.r, ps1.r), n - 1);
    int cs = max(min(ps0.c, ps1.c), 0);
    int ce = min(max(ps0.c, ps1.c), m - 1);
    for (int i = rs; i <= re; i++)
    {
        for (int j = cs; j <= ce; j++)
        {
            if (grid[i][j].t == 0)
                continue;

            set<pair<int, Point>> inters;
            for (int k = 0; k < 5; k++)
            {
                auto inter = Line::InterPoint(grid[i][j].lines[k], l);
                if (inter.first != 0)
                    inters.insert(inter);
            }

            if (inters.empty()) continue;
            if (inters.size() == 1 && grid[i][j].t == 2 && inters.begin()->first == 2)
                continue;
            for (auto it = inters.begin(); it != inters.end(); it++)
                close = min(close, { grid[i][j].t,it->second }, comp);
        }
    }

    if (close.first == 5)
    {
        if (ps1.r < 0 || ps1.r >= n || ps1.c < 0 || ps1.c >= m)
            return 2;
        return 0;
    }
    return close.first;
}

int BFS(Pos s, Pos t, Pos sv, vector<vector<Rect>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<map<int, map<int, int>>>> dist(n, vector<map<int, map<int, int>>>(m));
    queue<Edge> Q;
    dist[s.r][s.c][sv.r][sv.c] = 0;
    Q.push({ s,sv });

    while (!Q.empty())
    {
        auto [u, uv] = Q.front();
        Q.pop();

        auto [r, c] = u;
        auto [vr, vc] = uv;

        int nd = dist[r][c][vr][vc] + 1;
        for (int i = 0; i < 9; i++)
        {
            int nvr = vr + dr[i];
            int nvc = vc + dc[i];
            int nr = r + nvr;
            int nc = c + nvc;

            int rt = RouteType(u, { nr,nc }, grid);
            if (rt == 1)
                return nd;
            if (rt == 2 || dist[nr][nc].count(nvr) != 0 && dist[nr][nc][nvr].count(nvc) != 0)
                continue;

            dist[nr][nc][nvr][nvc] = nd;
            Q.push({ {nr,nc},{nvr,nvc} });
        }
    }
    return INF;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<Rect>> grid(n, vector<Rect>(m));
    Pos s, t;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;

            grid[i][j].t = 0;
            if (c == 'S')
                s = { i,j };
            else if (c == 'F')
            {
                t = { i,j };
                grid[i][j] = Rect(1, i, j);
            }
            else if (c == 'X')
                grid[i][j] = Rect(2, i, j);
        }
    }

    int vr, vc;
    cin >> vr >> vc;

    int result = BFS(s, t, { vr,vc }, grid);
    if (result == INF)
        cout << -1 << '\n';
    else
        cout << result << '\n';
}
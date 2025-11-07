#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

struct Pos
{
    int r, c;
};

array<int, 9> dr = { -1,0,1,1,1,0,-1,-1,0 };
array<int, 9> dc = { 1,1,1,0,-1,-1,-1,0,0 };

struct Edge
{
    Pos u, v;
};

const double EPS = 1e-6;
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
        return sqrt(dx * dx + dy * dy);
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

        int ab_cd = Point::CCW(a, b, c) * Point::CCW(a, b, d);
        int cd_ab = Point::CCW(c, d, a) * Point::CCW(c, d, b);

        if (ab_cd < 0 && cd_ab < 0)
            return { 1,a + (b - a) * (((c - a) / (d - c)) / ((b - a) / (d - c))) };

        if (OnLine(l0, c)) return { 2, c };
        if (OnLine(l0, d)) return { 2, d };
        if (OnLine(l1, a)) return { 2, a };
        if (OnLine(l1, b)) return { 2, b };
        return { 0,{0,0} };
    }
};
struct Rect
{
    int t;
    array<Line, 4> lines;

    Rect() : t(0) {}
    Rect(int t, int row, int col) : t(t)
    {
        double u = row - 0.5, d = row + 0.5;
        double l = col - 0.5, r = col + 0.5;
        Point lu = { l,u }, ru = { r,u };
        Point ld = { l,d }, rd = { r,d };
        lines = { Line{lu,ru},{ru,rd},{rd,ld},{ld,lu} };
    }
};

int RouteType(Point p0, Point p1, vector<vector<Rect>>& grid)
{
    if (p0 == p1)
        return 0;

    int n = grid.size();
    int m = grid[0].size();

    pair<int, Point> close = { -1,{1'000,1'000} };
    auto comp = [&p0](const auto& a, const auto& b)
        {
            double da = Point::Dist(p0, a.second);
            double db = Point::Dist(p0, b.second);

            if (da != db) return da < db;
            return a.first < b.first;
        };

    Line l = { p0,p1 };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j].t == 0)
                continue;
            for (int k = 0; k < 4; k++)
            {
                auto inter = Line::InterPoint(grid[i][j].lines[k], l);
                if (inter.first == 0)
                    continue;
                if (grid[i][j].t == 2 && inter.first == 2)
                    continue;

                close = min(close, { grid[i][j].t, inter.second }, comp);
            }
        }
    }

    if (close.first == -1)
    {
        if (p1.x < 0 || p1.x >= m || p1.y < 0 || p1.y >= n)
            return 2;
        return 0;
    }
    return close.first;
}

int BFS(Pos s, Pos t, Pos v, vector<vector<Rect>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<unordered_map<int, unordered_map<int, int>>>> dist(n, vector<unordered_map<int, unordered_map<int, int>>>(m));
    queue<Edge> Q;
    dist[s.r][s.c][v.r][v.c] = 0;
    Q.push({ s,v });

    int result = INF;
    while (!Q.empty())
    {
        auto [u, v] = Q.front();
        Q.pop();

        auto [r, c] = u;
        auto [vr, vc] = v;

        for (int i = 0; i < 9; i++)
        {
            int nvr = vr + dr[i];
            int nvc = vc + dc[i];
            int nr = r + nvr;
            int nc = c + nvc;

            int nd = dist[r][c][vr][vc] + 1;
            int rt = RouteType({ 1. * c,1. * r }, { 1. * nc,1. * nr }, grid);

            if (rt == 1)
            {
                result = min(result, nd);
                continue;
            }
            if (rt == 2 || dist[nr][nc].count(nvr) == 1 && dist[nr][nc][nvr].count(nvc) == 1)
                continue;

            dist[nr][nc][nvr][nvc] = nd;
            Q.push({ nr,nc,nvr,nvc });
        }
    }
    return result;
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
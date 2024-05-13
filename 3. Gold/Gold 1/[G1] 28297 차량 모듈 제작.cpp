#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

#define PI 3.14159265359

struct Gear
{
    double x, y, r;
};

struct Edge
{
    int u, v;
    double w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w < b.w;
    }
};

double Dist(Gear& a, Gear& b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;

    double d = sqrt(dx * dx + dy * dy);
    double r1 = max(a.r, b.r);
    double r2 = min(a.r, b.r);

    if (d <= r1 + r2)
        return 0;

    double dr = r1 - r2;
    double l = sqrt(d * d - dr * dr);

    double t = acos(dr / d);

    double result = (l * 2) + (r1 * 2 * (PI - t)) + (r2 * 2 * t);
    return result;
}

int Find(int u, vector<int>& p)
{
    if (p[u] == -1)
        return u;
    return p[u] = Find(p[u], p);
}

void Union(int u, int v, vector<int>& p)
{
    p[Find(v, p)] = Find(u, p);
}

double MinBelt(int n, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end());

    vector<int> p(n, -1);
    double result = 0;
    for (Edge& edge : edges)
    {
        int u = edge.u;
        int v = edge.v;

        if (Find(u, p) == Find(v, p))
            continue;

        Union(u, v, p);
        result += edge.w;
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Gear> gears(n);
    for (int i = 0; i < n; i++)
    {
        double x, y, r;
        cin >> x >> y >> r;

        gears[i] = { x,y,r };
    }

    vector<Edge> edges;
    for (int u = 0; u < n - 1; u++)
    {
        for (int v = u + 1; v < n; v++)
        {
            double w = Dist(gears[u], gears[v]);
            edges.push_back({ u,v,w });
        }
    }

    double result = MinBelt(n, edges);
    lf(6);
    cout << result << '\n';
}
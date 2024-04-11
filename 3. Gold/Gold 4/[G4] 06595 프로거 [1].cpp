#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cfloat>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int x, y;

    friend double Dist(Pos& a, Pos& b)
    {
        int dx = a.x - b.x;
        int dy = a.y - b.y;

        return sqrt(dx * dx + dy * dy);
    }
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

int Find(int u, vector<int>& p)
{
    if (p[u] == -1)
        return u;
    return p[u] = Find(p[u], p);
}

void Union(int u, int v, vector<int>& p)
{
    p[v] = u;
}

double GetMinJump(vector<Pos>& pos)
{
    int n = pos.size();

    vector<Edge> edges;
    for (int u = 0; u < n - 1; u++)
    {
        for (int v = u + 1; v < n; v++)
            edges.push_back({ u,v,Dist(pos[u], pos[v]) });
    }
    sort(edges.begin(), edges.end());

    vector<int> p(n, -1);
    double result = 0;
    for (Edge& edge : edges)
    {
        int u = Find(edge.u, p);
        int v = Find(edge.v, p);

        if (u != v)
        {
            Union(u, v, p);
            result = max(result, edge.w);

            if (Find(0, p) == Find(1, p))
                break;
        }
    }
    return result;
}

int main()
{
    FastIO;

    int tc = 0;
    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        vector<Pos> pos(n);
        for (int i = 0; i < n; i++)
            cin >> pos[i].x >> pos[i].y;

        double result = GetMinJump(pos);
        printf("Scenario #%d\n", ++tc);
        printf("Frog Distance = %.3lf\n\n", result);
    }
}
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define EPSILON 1

struct Edge
{
    int u, v;
    int c, t;
};

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

array<long long, 2> MST(int n, vector<Edge>& edges)
{
    vector<int> p(n, -1);

    array<long long, 2> result = { 0,0 };
    for (Edge& edge : edges)
    {
        int u = edge.u;
        int v = edge.v;

        if (Find(u, p) == Find(v, p))
            continue;

        Union(u, v, p);
        result[0] += edge.c;
        result[1] += edge.t;
    }
    return result;
}

double MaxEarnPerTime(int n, int f, vector<Edge>& edges)
{
    double start = 0, end = f;
    double result = 0;
    while (abs(end - start) > EPSILON)
    {
        double mid = (start + end) / 2;

        sort(edges.begin(), edges.end(),
            [mid](const Edge& a, const Edge& b)
            {
                return mid * a.t + a.c < mid * b.t + b.c;
            }
        );

        array<long long, 2> ct = MST(n, edges);
        double earnPerTime = (double)(f - ct[0]) / ct[1];
        if (earnPerTime > mid)
            start = mid;
        else
        {
            result = max(result, earnPerTime);
            end = mid;
        }
    }
    return result;
}

int main()
{
    FastIO;

    int n, m, f;
    cin >> n >> m >> f;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, c, t;
        cin >> u >> v >> c >> t;
        u--, v--;

        edges[i] = { u,v,c,t };
    }

    double result = MaxEarnPerTime(n, f, edges);
    printf("%.4lf\n", result);
}
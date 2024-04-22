#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int u, v, w, t;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        if (a.w != b.w)
            return a.w < b.w;
        return a.t < b.t;
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

vector<long long> MinRail(int n, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end());

    vector<int> p(n + 1, -1);
    vector<long long> result = { 0,0 };
    int cnt = 0;
    for (Edge& edge : edges)
    {
        int u = Find(edge.u, p);
        int v = Find(edge.v, p);

        if (u == v)
            continue;

        Union(u, v, p);
        result[0] = max(result[0], (long long)edge.t);
        result[1] += edge.w;
        cnt++;

        if (cnt == n - 1)
            return result;
    }
    return { -1 };
}

int main()
{
    FastIO;

    int n, q;
    cin >> n >> q;

    vector<Edge> edges(q);
    for (int i = 0; i < q; i++)
    {
        int u, v, w, t;
        cin >> u >> v >> w >> t;
        u--, v--;

        edges[i] = { u,v,w,t };
    }

    vector<long long> result = MinRail(n, edges);
    for (long long x : result)
        cout << x << ' ';
    cout << '\n';
}
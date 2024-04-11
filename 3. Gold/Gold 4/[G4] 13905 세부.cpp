#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int u, v, w;

    friend bool operator>(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
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

int GetMaxBBR(int s, int e, int n, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end(), greater<Edge>());

    vector<int> p(n, -1);
    int result = INT_MAX;
    for (Edge& edge : edges)
    {
        int u = Find(edge.u, p);
        int v = Find(edge.v, p);

        if (u != v)
        {
            Union(u, v, p);
            result = min(result, edge.w);

            if (Find(s, p) == Find(e, p))
                break;
        }
    }
    result = (Find(s, p) == Find(e, p) ? result : 0);

    return result;
}

int main()
{
    FastIO;

    int n, m, s, e;
    cin >> n >> m >> s >> e;
    s--, e--;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        edges[i] = { u,v,w };
    }

    int result = GetMaxBBR(s, e, n, edges);
    cout << result << '\n';
}
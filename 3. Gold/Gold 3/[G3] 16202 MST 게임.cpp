#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int u, v, w;
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

int MST(int s, int n, vector<Edge>& edges)
{
    int m = edges.size();

    vector<int> p(n, -1);
    int result = 0;
    int cnt = 0;
    for (int i = s; i < m; i++)
    {
        Edge& edge = edges[i];

        int u = Find(edge.u, p);
        int v = Find(edge.v, p);

        if (u == v)
            continue;

        Union(u, v, p);
        result += edge.w;
        cnt++;

        if (cnt == n - 1)
            return result;
    }
    return 0;
}

int main()
{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        edges[i] = { u,v,i + 1 };
    }

    for (int i = 0; i < k; i++)
    {
        int result = MST(i, n, edges);
        cout << result << ' ';
    }
    cout << '\n';
}
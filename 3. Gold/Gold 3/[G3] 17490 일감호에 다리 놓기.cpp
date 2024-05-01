#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int u, v, w;

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

bool CanBridge(long long k, int n, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end());

    vector<int> p(n, -1);
    long long result = 0;
    int cnt = 0;
    for (Edge& edge : edges)
    {
        int u = Find(edge.u, p);
        int v = Find(edge.v, p);

        if (u == v)
            continue;

        Union(u, v, p);
        result += edge.w;
        cnt += (v != n - 1);

        if (cnt == n - 2)
            return (result <= k);
    }
    return false;
}

int main()
{
    FastIO;

    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<Edge> edges;
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;

        edges.push_back({ i,n,s });
    }

    vector<bool> noEdges(n, false);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        if (!(u == n - 1 && v == 0) && u > v)
            swap(u, v);

        noEdges[u] = true;
    }

    for (int i = 0; i < n; i++)
    {
        if (!noEdges[i])
            edges.push_back({ i,(i + 1) % n,0 });
    }

    string result = (CanBridge(k, n + 1, edges) ? "YES" : "NO");
    cout << result << '\n';
}
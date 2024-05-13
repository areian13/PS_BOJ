#include <iostream>
#include <vector>
#include <algorithm>

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
    p[Find(v, p)] = Find(u, p);
}

long long MST(int n, vector<Edge>& edges, vector<vector<Edge>>& tree)
{
    sort(edges.begin(), edges.end(), greater<Edge>());

    vector<int> p(n, -1);
    long long result = 0;
    for (Edge& edge : edges)
    {
        int u = edge.u;
        int v = edge.v;

        if (Find(u, p) == Find(v, p))
            continue;

        Union(u, v, p);
        result += edge.w;

        tree[u].push_back({ -1,v,edge.w });
        tree[v].push_back({ -1,u,edge.w });
    }
    return result;
}

long long DFS(int cur, int pre, vector<vector<Edge>>& tree)
{
    long long result = 0;
    for (Edge& edge : tree[cur])
    {
        int nxt = edge.v;
        int w = edge.w;

        if (nxt == pre)
            continue;

        result = max(result, DFS(nxt, cur, tree) + w);
    }
    return result;
}

long long  MaxDist(int s, vector<vector<Edge>>& tree)
{
    int n = tree.size();
    return DFS(s, -1, tree);
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        edges[i] = { u,v,w };
    }

    int s;
    cin >> s;
    s--;

    vector<vector<Edge>> tree(n);

    long long result = MST(n, edges, tree) * 2;
    result -= MaxDist(s, tree);
    cout << result << '\n';
}
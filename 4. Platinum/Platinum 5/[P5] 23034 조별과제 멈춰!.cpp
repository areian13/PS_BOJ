#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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
    p[Find(v, p)] = Find(u, p);
}

int MinContactCost(int n, vector<Edge>& edges, vector<vector<Edge>>& tree)
{
    sort(edges.begin(), edges.end());

    vector<int> p(n, -1);
    int result = 0;
    for (Edge& edge : edges)
    {
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;

        if (Find(u, p) == Find(v, p))
            continue;

        Union(u, v, p);
        result += w;

        tree[u].push_back({ -1,v,w });
        tree[v].push_back({ -1,u,w });
    }
    return result;
}

int MaxEdge(int x, int y, vector<vector<int>>& dist, vector<vector<Edge>>& tree)
{
    if (dist[x][y] != -1)
        return dist[x][y];

    dist[x][x] = 0;

    queue<Edge> Q;
    Q.push({ -1,x,0 });

    while (!Q.empty())
    {
        int cur = Q.front().v;
        int w = Q.front().w;
        Q.pop();

        for (Edge& edge : tree[cur])
        {
            int nxt = edge.v;
            int nw = max(edge.w, w);

            if (dist[x][nxt] != -1)
                continue;

            dist[x][nxt] = nw;
            Q.push({ -1,nxt,nw });
        }
    }
    return dist[x][y];
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

    vector<vector<Edge>> tree(n);
    int mst = MinContactCost(n, edges, tree);

    int q;
    cin >> q;

    vector<vector<int>> dist(n, vector<int>(n, -1));
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;

        int result = mst - MaxEdge(x, y, dist, tree);
        cout << result << '\n';
    }
}
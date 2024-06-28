#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <set>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int u, v, w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
    friend bool operator>(const Edge& a, const Edge& b)
    {
        if (a.u != b.u)
            return a.u < b.u;
        return a.v < b.v;
    }
};

void RestoreNetwork(vector<vector<Edge>>& graph, set<Edge, greater<Edge>>& result)
{
    int n = graph.size();

    vector<Edge> dist(n, { -1,-1,INT_MAX });
    dist[0] = { -1,0,0 };

    priority_queue<Edge> PQ;
    PQ.push(dist[0]);

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        int w = PQ.top().w;
        PQ.pop();

        if (dist[u].w < w)
            continue;

        for (Edge& edge : graph[u])
        {
            int v = edge.v;
            int nw = w + edge.w;

            if (dist[v].w < nw)
                continue;

            dist[v] = { u,v,nw };
            PQ.push(dist[v]);
        }
    }

    for (int i = 1; i < n; i++)
    {
        Edge x = dist[i];
        while (x.u != -1 && result.count(x) == 0)
        {
            result.insert(x);
            x = dist[x.u];
        }
    }
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;
    
    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        graph[u].push_back({ u,v,w });
        graph[v].push_back({ v,u,w });
    }

    set<Edge, greater<Edge>> result;
    RestoreNetwork(graph, result);

    cout << result.size() << '\n';
    for (set<Edge>::iterator it = result.begin(); it != result.end(); it++)
        cout << it->u + 1 << ' ' << it->v + 1 << '\n';
}
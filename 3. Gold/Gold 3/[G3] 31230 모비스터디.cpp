#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v;
    long long w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

void DFS(int u, vector<vector<int>>& tree, set<int>& result)
{
    result.insert(u);

    for (int v : tree[u])
    {
        if (v == -1)
            continue;

        DFS(v, tree, result);
    }
}

void MeetCity(int s, int t, vector<vector<Edge>>& graph, set<int>& result)
{
    int n = graph.size();

    vector<long long> dist(n, LLONG_MAX);
    dist[s] = 0;

    vector<vector<int>> par(n);
    par[s].push_back(-1);

    priority_queue<Edge> PQ;
    PQ.push({ s,0 });

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        long long w = PQ.top().w;
        PQ.pop();

        if (dist[u] < w)
            continue;

        for (Edge& edge : graph[u])
        {
            int v = edge.v;
            long long nw = w + edge.w;

            if (dist[v] < nw)
                continue;

            if (dist[v] == nw)
            {
                par[v].push_back(u);
                continue;
            }

            par[v].clear();
            par[v].push_back(u);
            
            dist[v] = nw;
            PQ.push({ v,nw });
        }
    }

    DFS(t, par, result);
}

int main()
{
    FastIO;

    int n, m, a, b;
    cin >> n >> m >> a >> b;
    a--, b--;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        graph[u].push_back({ v,w });
        graph[v].push_back({ u,w });
    }

    set<int> result;
    MeetCity(a, b, graph, result);

    cout << result.size() << '\n';
    for (int x : result)
        cout << x + 1 << ' ';
    cout << '\n';
}
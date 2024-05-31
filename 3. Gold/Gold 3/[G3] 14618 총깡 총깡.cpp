#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v, w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

vector<string> AorBDist(int s, vector<int>& a, vector<int>& b, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    vector<int> dist(n, INT_MAX);
    dist[s] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ s,0 });

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        int w = PQ.top().w;
        PQ.pop();

        if (dist[u] < w)
            continue;

        for (Edge& edge : graph[u])
        {
            int v = edge.v;
            int nw = w + edge.w;

            if (dist[v] <= nw)
                continue;

            dist[v] = nw;
            PQ.push({ v,nw });
        }
    }

    char ab = 'A';
    int minDist = INT_MAX;

    for (int x : a)
    {
        if (minDist > dist[x])
        {
            minDist = dist[x];
            ab = 'A';
        }
    }

    for (int x : b)
    {
        if (minDist > dist[x])
        {
            minDist = dist[x];
            ab = 'B';
        }
    }

    if (minDist == INT_MAX)
        return { "-1" };
    return { string(1, ab),to_string(minDist)};
}

int main()
{
    FastIO;

    int n, m, j, k;
    cin >> n >> m >> j >> k;
    j--;

    vector<int> a(k);
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
        a[i]--;
    }

    vector<int> b(k);
    for (int i = 0; i < k; i++)
    {
        cin >> b[i];
        b[i]--;
    }

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        graph[u].push_back({ v,w });
        graph[v].push_back({ u,w });
    }

    vector<string> result = AorBDist(j, a, b, graph);
    for (string& x : result)
        cout << x << '\n';
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct pair_hash
{
    template <class T1, class T2>
    size_t operator () (const std::pair<T1, T2>& p) const
    {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);

        return h1 << 2 ^ h2;
    }
};

struct Edge
{
    int v;
    int w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

int NextW(int u, int v, int w,
    unordered_map<pair<int, int>, pair<int, int>, pair_hash>& gTime)
{
    if (gTime.count({ u,v }) == 0)
        return 0;

    pair<int, int>& time = gTime[{ u,v }];
    if (time.first <= w && w < time.second)
        return time.second - w;
    return 0;
}

int DeliveryTime(int s, int t, int k, vector<vector<Edge>>& graph,
    unordered_map<pair<int, int>, pair<int, int>, pair_hash>& gTime)
{
    int n = graph.size();

    vector<int> dist(n, INT_MAX);
    dist[s] = k;

    priority_queue<Edge> PQ;
    PQ.push({ s,k });

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
            int nw = w + edge.w + NextW(u, v, w, gTime);

            if (dist[v] <= nw)
                continue;

            dist[v] = nw;
            PQ.push({ v,nw });
        }
    }

    return dist[t] - k;
}

int main()
{
    FastIO;

    int n, m, a, b, k, g;
    cin >> n >> m >> a >> b >> k >> g;
    a--, b--;

    vector<int> gRoute(g);
    for (int i = 0; i < g; i++)
    {
        cin >> gRoute[i];
        gRoute[i]--;
    }

    vector<vector<Edge>> graph(n);
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        graph[u].push_back({ v,w });
        graph[v].push_back({ u,w });

        matrix[u][v] = w;
        matrix[v][u] = w;
    }

    unordered_map<pair<int, int>, pair<int, int>, pair_hash> gTime;
    int sum = 0;
    for (int i = 0; i < g - 1; i++)
    {
        int u = gRoute[i];
        int v = gRoute[i + 1];
        
        gTime[{ u,v }] = { sum,sum + matrix[u][v] };
        gTime[{ v,u }] = { sum,sum + matrix[v][u] };
        sum += matrix[u][v];
    }

    int result = DeliveryTime(a, b, k, graph, gTime);
    cout << result << '\n';
}
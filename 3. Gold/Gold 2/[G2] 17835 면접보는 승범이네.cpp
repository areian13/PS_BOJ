#include <iostream>
#include <vector>
#include <array>
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

array<long long, 2> FarthestCity(vector<int>& s, vector<vector<Edge>>& graph)
{
    int n = graph.size();
    int k = s.size();

    vector<long long> dist(n, LLONG_MAX);
    priority_queue<Edge> PQ;
    for (int i = 0; i < k; i++)
    {
        dist[s[i]] = 0;
        PQ.push({ s[i],0 });
    }

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

            if (dist[v] <= nw)
                continue;

            dist[v] = nw;
            PQ.push({ v,nw });
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (dist[result] < dist[i])
            result = i;
    }

    return { result,dist[result] };
}

int main()

{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        graph[v].push_back({ u,w });
    }

    vector<int> s(k);
    for (int i = 0; i < k; i++)
    {
        cin >> s[i];
        s[i]--;
    }

    array<long long, 2> result = FarthestCity(s, graph);
    cout << result[0] + 1 << '\n' << result[1] << '\n';
}
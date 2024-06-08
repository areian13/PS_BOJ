#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

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

void Dijstra(int s, vector<long long>& dist, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    dist[s] = 0;

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

            if (dist[v] <= nw)
                continue;

            dist[v] = nw;
            PQ.push({ v,nw });
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

        graph[u].push_back({ v,w });
        graph[v].push_back({ u,w });
    }

    vector<int> seq(10);
    for (int i = 0; i < 10; i++)
    {
        cin >> seq[i];
        seq[i]--;
    }

    vector<long long> yDist(10, -1);
    yDist[0] = 0;
    for (int i = 1; i < 10; i++)
    {
        int cnt = 1;
        vector<long long> dist(n, LLONG_MAX);
        Dijstra(seq[i - cnt], dist, graph);
        while (i < 10)
        {
            if (dist[seq[i]] != LLONG_MAX)
            {
                yDist[i] = yDist[i - cnt] + dist[seq[i]];
                break;
            }
            i++;
            cnt++;
        }
    }

    int s;
    cin >> s;
    s--;

    vector<long long> dist(n, LLONG_MAX);
    Dijstra(s, dist, graph);

    int result = INT_MAX;
    for (int i = 0; i < 10; i++)
    {
        if (yDist[i] == LLONG_MAX)
            continue;
        if (dist[seq[i]] == LLONG_MAX)
            continue;

        if (yDist[i] >= dist[seq[i]])
            result = min(result, seq[i]);
    }
    result = (result == INT_MAX ? -1 : result + 1);
    cout << result << '\n';
}
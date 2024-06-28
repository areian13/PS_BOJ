#include <iostream>
#include <vector>
#include <unordered_map>
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

void Dijkstra(int s, vector<long long>& dist, vector<vector<Edge>>& graph)
{
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

    int x, z;
    cin >> x >> z;
    x--, z--;

    int p;
    cin >> p;

    vector<int> ys(p + 1);
    ys[0] = x;

    unordered_map<int, int> seq;
    seq[ys[0]] = 0;

    for (int i = 1; i <= p; i++)
    {
        cin >> ys[i];
        ys[i]--;
        seq[ys[i]] = i;
    }

    vector<vector<long long>> dists(p + 1, vector<long long>(n, LLONG_MAX));
    for (int i = 0; i <= p; i++)
        Dijkstra(ys[i], dists[i], graph);

    long long result = LLONG_MAX;
    for (int i = 1; i <= p; i++)
    {
        long long d1 = dists[seq[ys[0]]][ys[i]];
        if (d1 == LLONG_MAX)
            continue;

        for (int j = 1; j <= p; j++)
        {
            if (i == j)
                continue;

            long long d2 = dists[seq[ys[i]]][ys[j]];
            if (d2 == LLONG_MAX)
                continue;

            for (int k = 1; k <= p; k++)
            {
                if (i == j || j == k || k == i)
                    continue;

                long long d3 = dists[seq[ys[j]]][ys[k]];
                if (d3 == LLONG_MAX)
                    continue;

                long long d4 = dists[seq[ys[k]]][z];
                if (d4 == LLONG_MAX)
                    continue;

                result = min(result, d1 + d2 + d3 + d4);
            }
        }
    }

    result = (result == LLONG_MAX ? -1 : result);
    cout << result << '\n';
}
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define COOL 5
#define MAX 100

struct Edge
{
    int v, w, t;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

int MinTime(int s, int t, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    vector<vector<int>> dist(MAX + 1, vector<int>(n, INT_MAX));
    dist[0][s] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ s,0,0 });

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        int w = PQ.top().w;
        int t = PQ.top().t;
        PQ.pop();

        if (dist[t][u] < w)
            continue;

        for (int i = 0; i < 2; i++)
        {
            for (Edge& edge : graph[u])
            {
                int v = edge.v;
                int nw = w + edge.w + (COOL * i);
                int nt = (i == 0 ? t : 0) + edge.w;

                if (nt > MAX || dist[nt][v] <= nw)
                    continue;

                dist[nt][v] = nw;
                PQ.push({ v,nw,nt });
            }
        }
    }
    
    int result = INT_MAX;
    for (int i = 0; i <= MAX; i++)
        result = min(result, dist[i][t]);
    return result;
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;
    n += 2;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < k; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({ v,w });
        graph[v].push_back({ u,w });
    }

    int result = MinTime(0, n - 1, graph);
    cout << result << '\n';
}
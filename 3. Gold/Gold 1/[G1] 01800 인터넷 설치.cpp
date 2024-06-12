#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v, w, c;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

int MinCost(int k, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
    dist[0][k] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ 0,0,k });

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        int w = PQ.top().w;
        int c = PQ.top().c;
        PQ.pop();

        if (dist[u][c] < w)
            continue;

        for (int i = 0; i < 2; i++)
        {
            if (i == 1 && c == 0)
                break;

            for (Edge& edge : graph[u])
            {
                int v = edge.v;
                int nw = max(w, (i == 1 ? 0 : edge.w));
                int nc = c - i;

                if (dist[v][nc] <= nw)
                    continue;

                dist[v][nc] = nw;
                PQ.push({ v,nw,nc });
            }
        }
    }

    int result = *min_element(dist[n - 1].begin(), dist[n - 1].end());
    if (result == INT_MAX)
        return -1;
    return result;
}

int main()
{
    FastIO;

    int n, p, k;
    cin >> n >> p >> k;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < p; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        graph[u].push_back({ v,w });
        graph[v].push_back({ u,w });
    }

    int result = MinCost(k, graph);
    cout << result << '\n';
}
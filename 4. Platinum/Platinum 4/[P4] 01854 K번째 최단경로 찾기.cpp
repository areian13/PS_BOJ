#include <iostream>
#include <vector>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

struct Edge
{
    int v, w;
};

void KthSSSP(int s, int k, vector<vector<Edge>>& graph, vector<priority_queue<int>>& dist)
{
    int n = graph.size();

    auto comp = [](const Edge& a, const Edge& b) { return a.w > b.w; };
    priority_queue<Edge, vector<Edge>, decltype(comp)> PQ(comp);
    dist[s].push(0);
    PQ.push({ s,0 });

    while (!PQ.empty())
    {
        auto [u, w] = PQ.top();
        PQ.pop();

        for (auto& [v, vw] : graph[u])
        {
            int nw = w + vw;
            if (dist[v].size() < k)
            {
                dist[v].push(nw);
                PQ.push({ v,nw });
            }
            else if (dist[v].top() > nw)
            {
                dist[v].pop();
                dist[v].push(nw);
                PQ.push({ v,nw });
            }
        }
    }
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

        graph[u].push_back({ v,w });
    }

    vector<priority_queue<int>> result(n);
    KthSSSP(0, k, graph, result);
    for (int i = 0; i < n; i++)
    {
        if (result[i].size() != k)
            cout << -1 << '\n';
        else
            cout << result[i].top() << '\n';
    }
}
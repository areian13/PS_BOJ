#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define INF 1'000'000'000

struct Node
{
    int v, d;

    friend bool operator<(const Node& a, const Node& b)
    {
        return a.d > b.d;
    }
};

int main()
{
    FastIO;

    int v, e, k;
    cin >> v >> e >> k;
    k--;

    vector<vector<Node>> graph(v);
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        graph[u].push_back({ v,w });
    }

    vector<int> dist(v, INT_MAX);
    dist[k] = 0;

    priority_queue<Node> PQ;
    PQ.push({ k,0 });

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        int d = PQ.top().d;
        PQ.pop();

        for (Node& node : graph[u])
        {
            int v = node.v;
            int nd = d + node.d;

            if (dist[v] <= nd)
                continue;

            dist[v] = nd;
            PQ.push({ v,nd });
        }
    }

    for (int i = 0; i < v; i++)
    {
        if (dist[i] != INT_MAX)
            cout << dist[i] << '\n';
        else
            cout << "INF" << '\n';
    }
}
#include <iostream>
#include <vector>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v, d;
};

void BFS(int s, vector<vector<int>>& dist, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    dist[s][s] = 0;

    queue<Edge> Q;
    Q.push({ s,INT_MAX });

    while (!Q.empty())
    {
        int u = Q.front().v;
        int d = Q.front().d;
        Q.pop();

        for (Edge& nxt : graph[u])
        {
            int v = nxt.v;
            int nd = min(d, nxt.d);

            if (dist[s][v] != -1)
                continue;

            dist[s][v] = nd;
            Q.push({ v,nd });
        }
    }
}

int main()
{
    FastIO;

    int n, q;
    cin >> n >> q;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < n - 1; i++)
    {
        int p, q, r;
        cin >> p >> q >> r;
        p--, q--;

        graph[p].push_back({ q,r });
        graph[q].push_back({ p,r });
    }

    vector<vector<int>> dist(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
        BFS(i, dist, graph);

    while (q--)
    {
        int k, v;
        cin >> k >> v;
        v--;

        int result = 0;
        for (int i = 0; i < n; i++)
            result += (dist[v][i] >= k);
        cout << result << '\n';
    }
}
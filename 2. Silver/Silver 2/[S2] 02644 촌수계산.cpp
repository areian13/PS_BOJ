#include <iostream>
#include <vector>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int BFS(int s, int e, vector<vector<int>>& graph)
{
    int n = graph.size();

    vector<int> dist(n, -1);
    dist[s] = 0;

    queue<int> Q;
    Q.push(s);

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int v : graph[u])
        {
            if (dist[v] != -1)
                continue;

            dist[v] = dist[u] + 1;
            Q.push(v);
        }
    }
    return dist[e];
}

int main()
{
    FastIO;

    int n, s, e, m;
    cin >> n >> s >> e >> m;
    s--, e--;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int result = BFS(s, e, graph);
    cout << result << '\n';
}
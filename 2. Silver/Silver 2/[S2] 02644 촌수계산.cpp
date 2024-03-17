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
        int cur = Q.front();
        Q.pop();

        for (int nxt : graph[cur])
        {
            if (dist[nxt] != -1)
                continue;

            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
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
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void BFS(int s, vector<int>& dist, vector<vector<int>>& graph)
{
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
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int a, u, v;
        cin >> a >> u >> v;
        u--, v--;

        if (a == 1)
        {
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        else
        {
            vector<int>::iterator it = remove(graph[u].begin(), graph[u].end(), v);
            graph[u].resize(it - graph[u].begin());

            it = remove(graph[v].begin(), graph[v].end(), u);
            graph[v].resize(it - graph[v].begin());
        }

        vector<int> result(n, -1);
        BFS(0, result, graph);

        for (int i = 0; i < n; i++)
            cout << result[i] << ' ';
        cout << '\n';
    }
}
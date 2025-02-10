#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int BuildTime(int w, vector<int>& d, vector<int>& indegree,
    vector<vector<int>>& graph)
{
    int n = graph.size();
    vector<int> dist(n, 0);
    queue<int> Q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            dist[i] = d[i];
            Q.push(i);
        }
    }

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int v : graph[u])
        {
            indegree[v]--;
            dist[v] = max(dist[v], dist[u] + d[v]);

            if (indegree[v] == 0)
                Q.push(v);
        }
    }
    return dist[w];
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n, k;
        cin >> n >> k;

        vector<vector<int>> graph(n);
        vector<int> d(n), indegree(n, 0);
        for (int i = 0; i < n; i++)
            cin >> d[i];

        for (int i = 0; i < k; i++)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;

            graph[u].push_back(v);
            indegree[v]++;
        }

        int w;
        cin >> w;
        w--;

        int result = BuildTime(w, d, indegree, graph);
        cout << result << '\n';
    }
}
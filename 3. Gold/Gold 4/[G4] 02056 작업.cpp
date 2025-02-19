#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int MinTime(vector<int>& w, vector<int>& indegree, vector<vector<int>>& graph)
{
    int n = graph.size();
    vector<int> dist(n, 0);
    queue<int> Q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            dist[i] = w[i];
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
            dist[v] = max(dist[v], dist[u] + w[v]);

            if (indegree[v] == 0)
                Q.push(v);
        }
    }
    return *max_element(dist.begin(), dist.end());
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> graph(n);
    vector<int> w(n), indegree(n, 0);
    for (int u = 0; u < n; u++)
    {
        cin >> w[u] >> indegree[u];

        for (int i = 0; i < indegree[u]; i++)
        {
            int v;
            cin >> v;
            v--;

            graph[v].push_back(u);
        }
    }

    int result = MinTime(w, indegree, graph);
    cout << result << '\n';
}
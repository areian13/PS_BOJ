#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int MinTime(vector<int>& w, vector<int>& indegree,
    vector<vector<int>>& graph)
{
    int n = graph.size();

    queue<int> Q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            Q.push(i);
    }

    vector<int> dist(n, 0);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        dist[u] += w[u];

        for (int v : graph[u])
        {
            dist[v] = max(dist[v], dist[u]);
            indegree[v]--;

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
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> w[i] >> k;

        for (int j = 0; j < k; j++)
        {
            int b;
            cin >> b;
            b--;

            graph[i].push_back(b);
            indegree[b]++;
        }
    }

    int result = MinTime(w, indegree, graph);
    cout << result << '\n';
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void PrintHeightOrder(vector<int> indegree, vector<vector<int>>& graph)
{
    int n = graph.size();
    queue<int> Q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            Q.push(i);
    }

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        cout << u + 1 << ' ';

        for (int v : graph[u])
        {
            indegree[v]--;

            if (indegree[v] == 0)
                Q.push(v);
        }
    }
    cout << '\n';
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        graph[u].push_back(v);
        indegree[v]++;
    }

    PrintHeightOrder(indegree, graph);
}
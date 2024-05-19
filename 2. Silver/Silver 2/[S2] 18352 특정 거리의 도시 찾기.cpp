#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void KCity(int x, int k, vector<vector<int>>& graph, vector<int>& result)
{
    int n = graph.size();

    vector<int> dist(n, -1);
    dist[x] = 0;

    queue<int> Q;
    Q.push(x);

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        if (dist[u] == k)
            result.push_back(u + 1);

        for (int v : graph[u])
        {
            if (dist[v] != -1)
                continue;

            dist[v] = dist[u] + 1;
            Q.push(v);
        }
    }
    sort(result.begin(), result.end());

    if (result.empty())
        result.push_back(-1);
}

int main()
{
    FastIO;

    int n, m, k, x;
    cin >> n >> m >> k >> x;
    x--;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        graph[u].push_back(v);
    }

    vector<int> result;
    KCity(x, k, graph, result);

    for (int x : result)
        cout << x << '\n';
}
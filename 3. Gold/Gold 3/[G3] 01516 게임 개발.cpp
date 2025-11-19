#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> graph(n);
    vector<int> t(n), ind(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];

        while (true)
        {
            int u;
            cin >> u;
            if (u == -1)
                break;
            ind[i]++;
            graph[u - 1].push_back(i);
        }
    }

    vector<int> dist(n, 0);
    queue<int> Q;
    for (int i = 0; i < n; i++)
    {
        if (ind[i] != 0)
            continue;
        dist[i] = t[i];
        Q.push(i);
    }

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int v : graph[u])
        {
            dist[v] = max(dist[v], dist[u]);
            if (--ind[v] == 0)
            {
                dist[v] += t[v];
                Q.push(v);
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << dist[i] << '\n';
}
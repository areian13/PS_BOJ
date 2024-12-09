#include <iostream>
#include <vector>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        graph[a].push_back(b);
        indegree[b]++;
    }

    vector<int> result(n);
    queue<int> Q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            Q.push(i);
            result[i] = 1;
        }
    }

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int v : graph[u])
        {
            if (indegree[v] == 0)
                continue;
            indegree[v]--;

            if (indegree[v] == 0)
            {
                result[v] = result[u] + 1;
                Q.push(v);
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << result[i] << ' ';
    cout << '\n';
}
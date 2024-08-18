#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int BFS(int s, vector<vector<int>>& graph)
{
    int n = graph.size();

    vector<int> isVisited(n, false);
    isVisited[s] = true;

    queue<int> Q;
    Q.push(s);

    int result = 1;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int v : graph[u])
        {
            if (isVisited[v])
                continue;

            result++;
            isVisited[v] = true;
            Q.push(v);
        }
    }
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;

        graph[b].push_back(a);
    }

    vector<int> cnt(n, 0);
    int maxHacking = 0;
    for (int i = 0; i < n; i++)
    {
        cnt[i] = BFS(i, graph);
        maxHacking = max(maxHacking, cnt[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (maxHacking == cnt[i])
            cout << i + 1 << ' ';
    }
    cout << '\n';
}
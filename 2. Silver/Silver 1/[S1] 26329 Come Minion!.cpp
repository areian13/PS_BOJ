#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CanGo(int s, int t, vector<vector<int>>& graph)
{
    int n = graph.size();

    vector<bool> isVisited(n, false);
    isVisited[s] = true;

    queue<int> Q;
    Q.push(s);

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int v : graph[u])
        {
            if (isVisited[v])
                continue;

            isVisited[v] = true;
            Q.push(v);
        }
    }

    return isVisited[t];
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int t;
        cin >> t;

        unordered_map<string, bool> cant;
        for (int i = 0; i < t; i++)
        {
            string w;
            cin >> w;

            cant[w] = true;
        }

        int n, m;
        cin >> n >> m;

        vector<vector<int>> graph(n);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            string w;
            cin >> u >> v >> w;

            if (cant[w])
                continue;

            graph[u].push_back(v);
        }

        bool result = CanGo(0, n - 1, graph);
        cout << result << '\n';
    }
}
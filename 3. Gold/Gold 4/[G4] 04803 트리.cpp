#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void IsTree(int p, int u, vector<bool>& isVisited,
    vector<vector<int>>& graph, bool& isTree)
{
    isVisited[u] = true;

    for (int v : graph[u])
    {
        if (v == p)
            continue;
        if (isVisited[v])
        {
            isTree = false;
            continue;
        }

        IsTree(u, v, isVisited, graph, isTree);
    }
}

int main()
{
    FastIO;

    int tc = 0;
    while (true)
    {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        vector<vector<int>> graph(n);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<bool> isVisited(n, false);
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            if (isVisited[i])
                continue;

            bool isTree = true;
            IsTree(-1, i, isVisited, graph, isTree);
            result += isTree;
        }

        printf("Case %d: ", ++tc);
        if (result == 0)
            printf("No trees.\n");
        else if (result == 1)
            printf("There is one tree.\n");
        else
            printf("A forest of %d trees.\n", result);
    }
}
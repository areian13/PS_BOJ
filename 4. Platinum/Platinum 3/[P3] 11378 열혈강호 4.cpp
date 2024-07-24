#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CanMatch(int u, vector<bool>& isVisited,
    vector<int>& a, vector<int>& b, vector<vector<int>>& graph)
{
    isVisited[u] = true;

    for (int v : graph[u])
    {
        if (b[v] == -1 ||
            !isVisited[b[v]] && CanMatch(b[v], isVisited, a, b, graph))
        {
            a[u] = v;
            b[v] = u;
            return true;
        }
    }
    return false;
}

int MaxWork(int n, int m, vector<vector<int>>& graph)
{
    vector<int> a(n, -1), b(m, -1);
    int result = 0;
    for (int u = 0; u < n; u++)
    {
        if (a[u] != -1)
            continue;

        vector<bool> isVisited(n, false);
        result += CanMatch(u, isVisited, a, b, graph);
    }
    return result;
}

int main()
{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> graph(n + k);
    vector<bool> isLinked(m, false);
    for (int u = 0; u < n; u++)
    {
        int s;
        cin >> s;

        for (int i = 0; i < s; i++)
        {
            int v;
            cin >> v;
            v--;

            graph[u].push_back(v);

            if (isLinked[v])
                continue;

            for (int j = n; j < n + k; j++)
                graph[j].push_back(v);
            isLinked[v] = true;
        }
    }

    int result = MaxWork(n + k, m, graph);
    cout << result << '\n';
}
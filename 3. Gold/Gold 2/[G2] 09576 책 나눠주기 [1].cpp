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
            !isVisited[b[v]] && CanMatch(b[v], isVisited, a, b, graph)
            )
        {
            a[u] = v;
            b[v] = u;
            return true;
        }
    }
    return false;
}

int MaxBook(int n, int m, vector<vector<int>>& graph)
{
    vector<int> a(n, -1), b(m, -1);
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != -1)
            continue;

        vector<bool> isVisited(n, false);
        result += CanMatch(i, isVisited, a, b, graph);
    }
    return result;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> graph(n);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;

            for (int j = a; j <= b; j++)
                graph[j].push_back(i);
        }

        int result = MaxBook(n, m, graph);
        cout << result << '\n';
    }
}
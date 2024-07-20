#include <iostream>
#include <vector>
#include <algorithm>

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

int MaxWork(int n, int m, int k, vector<vector<int>>& graph)
{
    vector<int> a(n * 2, -1), b(m, -1);
    int result = 0;
    for (int i = 0; i < 2; i++)
    {
        int work = 0;
        for (int u = 0; u < n; u++)
        {
            if (a[u * 2 + i] != -1)
                continue;

            vector<bool> isVisited(n * 2, false);
            work += CanMatch(u * 2 + i, isVisited, a, b, graph);

            if (i == 1 && work == k)
                break;
        }
        result += work;
    }
    return result;
}

int main()
{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> graph(n * 2);
    for (int u = 0; u < n; u++)
    {
        int s;
        cin >> s;

        for (int i = 0; i < s; i++)
        {
            int v;
            cin >> v;
            v--;

            graph[u * 2].push_back(v);
            graph[u * 2 + 1].push_back(v);
        }
    }

    int result = MaxWork(n, m, k, graph);
    cout << result << '\n';
}
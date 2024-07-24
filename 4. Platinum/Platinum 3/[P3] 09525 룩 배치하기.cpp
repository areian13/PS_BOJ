#include <iostream>
#include <vector>
#include <climits>
#include <queue>
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

int MaxFlow(int n, int m, vector<vector<int>>& graph)
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

int MaxRook(vector<vector<char>>& map)
{
    int n = map.size();

    vector<vector<int>> u(n, vector<int>(n));
    int m = 0;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (map[y][x] == 'X')
            {
                m++;
                continue;
            }
            u[y][x] = m;
        }
        m++;
    }

    vector<vector<int>> graph(m);
    int k = 0;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            if (map[y][x] == 'X')
            {
                k++;
                continue;
            }
            graph[u[y][x]].push_back(k);
        }
        k++;
    }

    return MaxFlow(m, k, graph);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<char>> map(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    }

    int result = MaxRook(map);
    cout << result << '\n';
}
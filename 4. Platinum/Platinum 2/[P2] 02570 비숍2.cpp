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

int MaxBishop(vector<vector<char>>& map)
{
    int n = map.size();

    vector<vector<int>> u(n, vector<int>(n));
    int m = 0;
    for (int i = 0; i < n * 2 - 1; i++)
    {
        int y = 0, x = i;
        for (int j = 0; j < n; j++)
        {
            if (0 <= y && y < n && 0 <= x && x < n)
            {
                if (map[y][x] == 'X')
                    m++;
                else
                    u[y][x] = m;
            }
            y++, x--;
        }
        m++;
    }

    vector<vector<int>> graph(m);
    int k = 0;
    for (int i = 0; i < n * 2 - 1; i++)
    {
        int y = 0, x = i - n + 1;
        for (int j = 0; j < n; j++)
        {
            if (0 <= y && y < n && 0 <= x && x < n)
            {
                if (map[y][x] == 'X')
                    k++;
                else
                    graph[u[y][x]].push_back(k);
            }
            y++, x++;
        }
        k++;
    }

    return MaxFlow(m, k, graph);
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<char>> map(n, vector<char>(n, ' '));
    for (int i = 0; i < m; i++)
    {
        int r, c;
        cin >> r >> c;
        r--, c--;

        map[r][c] = 'X';
    }

    int result = MaxBishop(map);
    cout << result << '\n';
}
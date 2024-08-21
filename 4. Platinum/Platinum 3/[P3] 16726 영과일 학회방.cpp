#include <iostream>
#include <vector>
#include <array>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { 1,0,-1,0 };

void MakeLevel(vector<bool>& isUsed, vector<int>& level,
    vector<int>& b, vector<vector<int>>& graph)
{
    int n = graph.size();

    queue<int> Q;
    for (int u = 0; u < n; u++)
    {
        if (isUsed[u])
            continue;

        level[u] = 0;
        Q.push(u);
    }

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int v : graph[u])
        {
            if (b[v] == -1 || level[b[v]] != INT_MAX)
                continue;

            level[b[v]] = level[u] + 1;
            Q.push(b[v]);
        }
    }
}

bool CanMatch(int u, vector<bool>& isUsed, vector<int>& level,
    vector<int>& a, vector<int>& b, vector<vector<int>>& graph)
{
    int n = graph.size();

    for (int v : graph[u])
    {
        if (b[v] != -1)
        {
            if (level[b[v]] != level[u] + 1)
                continue;
            if (!CanMatch(b[v], isUsed, level, a, b, graph))
                continue;
        }

        a[u] = v;
        b[v] = u;
        return isUsed[u] = true;
    }
    return false;
}

int MaxMatch(vector<int>& a, vector<int>& b, vector<vector<int>>& graph)
{
    int n = a.size();
    int m = b.size();

    vector<bool> isUsed(n, false);
    int result = 0;
    while (true)
    {
        vector<int> level(n, INT_MAX);
        MakeLevel(isUsed, level, b, graph);

        int match = 0;
        for (int u = 0; u < n; u++)
            match += (!isUsed[u] && CanMatch(u, isUsed, level, a, b, graph));

        if (match == 0)
            break;

        result += match;
    }
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<char>> map(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    }

    vector<vector<int>> graph(n * m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i + j) % 2 == 1)
                continue;
            if (map[i][j] == 'X')
                continue;

            int u = i * m + j;
            for (int k = 0; k < 4; k++)
            {
                int ny = i + dy[k];
                int nx = j + dx[k];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                    continue;
                if (map[ny][nx] == 'X')
                    continue;

                int v = ny * m + nx;
                graph[u].push_back(v);
            }
        }
    }

    vector<int> a(n * m, -1), b(n * m, -1);
    int result = MaxMatch(a, b, graph);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 'X')
                continue;

            int u = i * m + j;
            if ((i + j) % 2 == 0)
                result += (a[u] == -1);
            else
                result += (b[u] == -1);
        }
    }
    cout << result << '\n';
}
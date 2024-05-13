#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int u, v, w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w < b.w;
    }
};

array<int, 4> dy = { 1,0,-1,0 };
array<int, 4> dx = { 0,1,0,-1 };

void DFS(int y, int x, int num, vector<vector<bool>>& isVisited, vector<vector<int>>& map)
{
    int n = map.size();
    int m = map[0].size();

    isVisited[y][x] = true;
    map[y][x] = num;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;
        if (map[ny][nx] != -1 || isVisited[ny][nx])
            continue;

        DFS(ny, nx, num, isVisited, map);
    }
}

int CountIsland(vector<vector<int>>& map)
{
    int n = map.size();
    int m = map[0].size();

    vector<vector<bool>> isVisited(n, vector<bool>(m, false));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] != -1 || isVisited[i][j])
                continue;

            DFS(i, j, cnt, isVisited, map);
            cnt++;
        }
    }
    return cnt;
}

void MakeBridge(int k, vector<Edge>& edges, vector<vector<int>>& map)
{
    int n = map.size();
    int m = map[0].size();

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m - 1; x++)
        {
            if (map[y][x] < 0)
                continue;
            if (map[y][x] == map[y][x + 1])
                continue;

            for (int nx = x + 1; nx < m; nx++)
            {
                if (map[y][nx] == map[y][x])
                    break;
                if (map[y][nx] >= 0)
                {
                    int w = nx - x - 1;
                    if (w >= 2)
                        edges.push_back({ map[y][x],map[y][nx],w });
                    break;
                }
            }
        }
    }

    for (int x = 0; x < m; x++)
    {
        for (int y = 0; y < n - 1; y++)
        {
            if (map[y][x] < 0)
                continue;
            if (map[y][x] == map[y + 1][x])
                continue;

            for (int ny = y + 1; ny < n; ny++)
            {
                if (map[ny][x] == map[y][x])
                    break;
                if (map[ny][x] >= 0)
                {
                    int w = ny - y - 1;
                    if (w >= 2)
                        edges.push_back({ map[y][x],map[ny][x],w });
                    break;
                }
            }
        }
    }
}

int Find(int u, vector<int>& p)
{
    if (p[u] == -1)
        return u;
    return p[u] = Find(p[u], p);
}

void Union(int u, int v, vector<int>& p)
{
    p[v] = u;
}

int MinBridge(vector<vector<int>>& map)
{
    int k = CountIsland(map);

    vector<Edge> edges;
    MakeBridge(k, edges, map);
    sort(edges.begin(), edges.end());

    vector<int> p(k, -1);
    int result = 0;
    int cnt = 0;
    for (Edge& edge : edges)
    {
        int u = Find(edge.u, p);
        int v = Find(edge.v, p);

        if (u == v)
            continue;

        Union(u, v, p);
        result += edge.w;
        cnt++;

        if (cnt == k - 1)
            return result;
    }
    return -1;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            map[i][j] -= 2;
        }
    }

    int result = MinBridge(map);
    cout << result << '\n';
}
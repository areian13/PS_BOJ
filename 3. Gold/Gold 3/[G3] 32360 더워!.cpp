#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 5> dr = { 1,0,-1,0,0 };
array<int, 5> dc = { 0,-1,0,1,0 };

struct Pos
{
    int r, c;
};

struct Edge
{
    Pos v;
    int w;
};

int MinDist(int d, int u, vector<vector<char>>& map)
{
    int n = map.size();
    int m = map[0].size();

    Pos s = { -1,-1 };
    Pos t = { -1,-1 };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 'S')
                s = { i,j };
            if (map[i][j] == 'E')
                t = { i,j };
        }
    }

    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(100, INT_MAX)));
    dist[s.r][s.c][0] = 0;

    queue<Edge> Q;
    Q.push({ s,0 });

    while (!Q.empty())
    {
        int r = Q.front().v.r;
        int c = Q.front().v.c;
        int w = Q.front().w;
        Q.pop();

        for (int i = 0; i < 5; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;
            if (map[nr][nc] == '#')
                continue;

            int nw = w;
            if (map[nr][nc] == 'S' || map[nr][nc] == 'H')
                nw = max(nw - d, 0);
            else
                nw = min(nw + u, 100);

            int nd = dist[r][c][w] + 1;
            if (nw >= 100 || dist[nr][nc][nw] != INT_MAX)
                continue;

            dist[nr][nc][nw] = nd;
            Q.push({ nr,nc,nw });
        }
    }

    int result = INT_MAX;
    for (int i = 0; i < 100; i++)
        result = min(result, dist[t.r][t.c][i]);

    if (result == INT_MAX)
        return -1;
    return result;
}

int main()
{
    FastIO;

    int n, m, k, c;
    cin >> n >> m >> k >> c;

    vector<vector<char>> map(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    }

    int result = MinDist(k, c, map);
    cout << result << '\n';
}
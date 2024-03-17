#include <iostream>
#include <vector>
#include <queue>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int y, x;
};

array<int, 4> dy = { 1,0,-1,0 };
array<int, 4> dx = { 0,1,0,-1 };

int BFS(int k, vector<vector<char>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dist(n + k * 2, vector<int>(m + k * 2, -1));
    queue<Pos> Q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] != 'o')
                continue;

            dist[k + i][k + j] = 0;
            Q.push({ k + i,k + j });
        }
    }

    n = dist.size();
    m = dist[0].size();

    while (!Q.empty())
    {
        int y = Q.front().y;
        int x = Q.front().x;
        Q.pop();

        if (dist[y][x] >= k)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (dist[ny][nx] != -1)
                continue;

            dist[ny][nx] = dist[y][x] + 1;
            Q.push({ ny,nx });
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            result += (dist[i][j] >= 0);
    }
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }

    int k;
    cin >> k;

    int result = BFS(k, grid);
    cout << result << '\n';
}
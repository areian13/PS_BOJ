#include <iostream>
#include <vector>
#include <queue>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int r, c;
};

array<int, 2> dr = { 0,1 };
array<int, 2> dc = { 1,0 };

int Dist(Pos s, Pos t, vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<Pos> Q;
    dist[s.r][s.c] = 0;
    Q.push(s);

    while (!Q.empty())
    {
        auto [r, c] = Q.front();
        Q.pop();

        for (int i = 0; i < 2; i++)
        {
            for (int d = 1; d <= grid[r][c]; d++)
            {
                int nr = r + dr[i] * d;
                int nc = c + dc[i] * d;

                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;
                if (dist[nr][nc] != -1)
                    continue;

                dist[nr][nc] = dist[r][c] + 1;
                Q.push({ nr,nc });
            }
        }
    }
    return dist[t.r][t.c];
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }

    int result = Dist({ 0,0 }, { n - 1,m - 1 }, grid);
    cout << result << '\n';
}
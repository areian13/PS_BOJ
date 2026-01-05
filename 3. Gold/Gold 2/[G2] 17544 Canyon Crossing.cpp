#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

struct Pos
{
    int r, c;
};

array<int, 4> dr = { 1,0,-1,0 };
array<int, 4> dc = { 0,1,0,-1 };

bool CanGo(int h, int k, vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dist(n, vector<int>(m, INF));
    queue<Pos> q;
    for (int i = 0; i < m; i++)
    {
        dist[n - 1][i] = (grid[n - 1][i] < h);
        q.push({ n - 1,i });
    }

    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();

        if (dist[r][c] > k) continue;
        if (r == 0) return true;

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;
            int nd = dist[r][c] + (grid[nr][nc] < h);
            if (dist[nr][nc] <= nd)
                continue;

            dist[nr][nc] = nd;
            q.push({ nr,nc });
        }
    }
    return false;
}

int MinHeight(int k, vector<vector<int>>& grid)
{
    int s = 0, e = 1e+9;
    int result = 0;
    while (s <= e)
    {
        int m = (s + e) / 2;
        if (CanGo(m, k, grid))
        {
            s = m + 1;
            result = m;
        }
        else
            e = m - 1;
    }
    return result;
}

int main()
{
    FastIO;

    int r, c, k;
    cin >> r >> c >> k;

    vector<vector<int>> grid(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cin >> grid[i][j];
    }

    int result = MinHeight(k, grid);
    cout << result << '\n';
}
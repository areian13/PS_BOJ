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

array<int, 4> dr = { 0,1,0,-1 };
array<int, 4> dc = { 1,0,-1,0 };

int Sum(int sr, int sc, int er, int ec, vector<vector<int>>& ps)
{
    return ps[er][ec] - ps[er][sc - 1] - ps[sr - 1][ec] + ps[sr - 1][sc - 1];
}

bool BFS(Pos s, Pos t, Pos vs, Pos ve, vector<vector<char>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();

    queue<Pos> Q;
    vector<vector<bool>> visit(n, vector<bool>(m));
    visit[s.r][s.c] = true;
    Q.push(s);

    while (!Q.empty())
    {
        auto [r, c] = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;
            if (visit[nr][nc] || grid[nr][nc] == '#')
                continue;
            if (vs.r <= nr && nr <= ve.r && vs.c <= nc && nc <= ve.c)
                continue;

            visit[nr][nc] = true;
            Q.push({ nr,nc });
        }
    }
    return visit[t.r][t.c];
}

bool WorthBlocking(int r, int c, int l,
    vector<vector<int>>& pr, vector<vector<int>>& pc)
{
    int cnt = 0;
    cnt += pr[r - 1][c + l - 1] - pr[r - 1][c - 1];
    cnt += pr[r + l][c + l - 1] - pr[r + l][c - 1];
    cnt += pc[r + l - 1][c - 1] - pc[r - 1][c - 1];
    cnt += pc[r + l - 1][c + l] - pc[r - 1][c + l];
    return cnt >= 2;
}

vector<int> Type(int l, vector<vector<int>>& ps,
    vector<vector<int>>& pr, vector<vector<int>>& pc,
    vector<vector<char>>& grid)
{
    int n = grid.size() - 2;
    int m = grid[0].size() - 2;

    bool remain = false;
    for (int i = 1; i + l - 1 <= n; i++)
    {
        for (int j = 1; j + l - 1 <= m; j++)
        {
            if (i == 1 && j == 1 ||
                i + l - 1 == n && j + l - 1 == m)
                continue;
            if (Sum(i, j, i + l - 1, j + l - 1, ps) != l * l)
                continue;

            remain = true;

            if (WorthBlocking(i, j, l, pr, pc))
            {
                if (!BFS({ 1,1 }, { n,m }, { i,j }, { i + l - 1,j + l - 1 }, grid))
                    return { l,i,j };
            }
        }
    }

    return { remain ? -1 : -2 };
}

vector<int> Barrier(vector<vector<char>>& grid)
{
    int n = grid.size() - 2;
    int m = grid[0].size() - 2;

    vector<vector<int>> ps(n + 2, vector<int>(m + 2, 0)), pr, pc;
    pr = pc = ps;
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 1; j <= m + 1; j++)
        {
            ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + (grid[i][j] == '.');
            pr[i][j] = pr[i][j - 1] + (grid[i][j - 1] == '#' && grid[i][j] == '.');
        }
    }
    for (int j = 1; j <= m + 1; j++)
    {
        for (int i = 1; i <= n + 1; i++)
            pc[i][j] = pc[i - 1][j] + (grid[i - 1][j] == '#' && grid[i][j] == '.');
    }

    int l = 1, r = min(n, m);
    vector<int> result = { r + 1,-1,-1 };
    while (l <= r)
    {
        int m = (l + r) / 2;
        vector<int> t = Type(m, ps, pr, pc, grid);

        if (t[0] == -1)
            l = m + 1;
        else if (t[0] == -2)
            r = m - 1;
        else
        {
            result = min(result, t);
            r = m - 1;
        }
    }

    if (result[0] == min(n, m) + 1)
        return { -1 };
    return result;
}

int main()
{
    FastIO;

    int w, h;
    cin >> w >> h;

    vector<vector<char>> grid(h + 2, vector<char>(w + 2, '#'));
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
            cin >> grid[i][j];
    }

    vector<int> result = Barrier(grid);
    if (result[0] == -1)
        cout << "Impossible" << '\n';
    else
        cout << result[0] << ' ' << result[2] << ' ' << result[1] << '\n';
}
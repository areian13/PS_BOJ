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

bool BFS(Pos s, Pos t, Pos vs, Pos ve, vector<vector<char>>& grid, bool flag = false)
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

    if (!flag)
        return visit[t.r][t.c];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !visit[i][j])
                grid[i][j] = '#';
        }
    }
    return visit[t.r][t.c];
}
int Wall(int l, int r, int c, vector<vector<int>>& ps)
{
    int n = ps.size() - 1;
    int m = ps[0].size() - 1;

    int sum = 0;
    if (r == 1 || c == 1 || c + l - 1 == m ||
        Sum(r - 1, c - 1, r - 1, c + l, ps) != l + 2 ||
        Sum(r - 1, c - 1, r - 1, c + l, ps) != 0)
        sum++;
    if (r + l - 1 == n || c == 1 || c + l - 1 == m ||
        Sum(r + l, c - 1, r + l, c + l, ps) != l + 2 ||
        Sum(r + l, c - 1, r + l, c + l, ps) != 0)
        sum++;
    if (r == 1 || r + l - 1 == n || c == 1 ||
        Sum(r - 1, c - 1, r + l, c - 1, ps) != l + 2)
        sum++;
    if (r == 1 || r + l - 1 == n || c + l - 1 == m ||
        Sum(r - 1, c + l, r + l, c + l, ps) != l + 2)
        sum++;
    return sum;
}

vector<int> Type(int l, vector<vector<int>>& ps, vector<vector<char>>& grid)
{
    int n = grid.size() - 1;
    int m = grid[0].size() - 1;

    bool tried = false;
    for (int i = 1; i + l - 1 <= n; i++)
    {
        for (int j = 1; j + l - 1 <= m; j++)
        {
            if (i == 1 && j == 1 || i + l - 1 == n && j + l - 1 == m)
                continue;
            if (Sum(i, j, i + l - 1, j + l - 1, ps) != l * l)
                continue;
            if (Wall(l, i, j, ps) <= 1)
                continue;

            tried = true;
            if (!BFS({ 1,1 }, { n,m }, { i,j }, { i + l - 1,j + l - 1 }, grid))
                return { l,i,j };
        }
    }

    if (tried) return { -1 };
    return { -2 };
}

vector<int> Barrier(vector<vector<char>>& grid)
{
    int n = grid.size() - 1;
    int m = grid[0].size() - 1;

    BFS({ 1,1 }, { n,m }, { -1,-1 }, { -1,-1 }, grid, true);

    vector<vector<int>> ps(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + (grid[i][j] == '.');
    }

    int s = 1, e = min(n, m);
    vector<int> result = { e + 1,-1,-1 };
    while (s <= e)
    {
        int m = (s + e) / 2;
        vector<int> t = Type(m, ps, grid);

        if (t[0] == -1)
            s = m + 1;
        else if (t[0] == -2)
            e = m - 1;
        else
        {
            result = min(result, t);
            e = m - 1;
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

    vector<vector<char>> grid(h + 1, vector<char>(w + 1, '#'));
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
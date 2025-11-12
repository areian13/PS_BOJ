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

void BFS(Pos s, vector<vector<bool>>& visit, vector<vector<char>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();

    queue<Pos> Q;
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

            visit[nr][nc] = true;
            Q.push({ nr,nc });
        }
    }
}

int main()
{
    FastIO;

    int w, h;
    cin >> w >> h;

    vector<vector<char>> grid(h, vector<char>(w));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            cin >> grid[i][j];
    }

    vector<vector<bool>> visit(h, vector<bool>(w, false));
    BFS({ 0,0 }, visit, grid);

    vector<vector<int>> ps(h, vector<int>(w, 0));
    for (int i = 0; i < h; i++)
        ps[i][0] = visit[i][0];
    for (int j = 0; j < w; j++)
        ps[0][j] = visit[0][j];

    for (int i = 1; i < h; i++)
    {
        for (int j = 1; j < w; j++)
            ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + visit[i][j];
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            printf("%2d ", ps[i][j]);
        }
        cout << '\n';
    }
}
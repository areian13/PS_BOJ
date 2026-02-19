#include <iostream>
#include <vector>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MAX = 500;

struct Pos
{
    int r, c;
};

vector<int> dr = { 0,1,0,-1 };
vector<int> dc = { 1,0,-1,0 };

int BFS(Pos s, Pos t, vector<vector<bool>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<Pos> q;
    dist[s.r][s.c] = 0;
    q.push(s);

    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;
            if (grid[nr][nc] || dist[nr][nc] != -1)
                continue;

            dist[nr][nc] = dist[r][c] + 1;
            q.push({ nr,nc });
        }
    }
    return dist[t.r][t.c];
}

int main()
{
    FastIO;

    int x, y, n;
    cin >> x >> y >> n;

    vector<vector<bool>> grid(MAX * 2 + 1, vector<bool>(MAX * 2 + 1, false));
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        grid[b + MAX][a + MAX] = true;
    }

    int result = BFS({ MAX,MAX }, { y + MAX,x + MAX }, grid);
    cout << result << '\n';
}
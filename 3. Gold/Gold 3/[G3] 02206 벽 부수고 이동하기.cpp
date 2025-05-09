#include <iostream>
#include <vector>
#include <array>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int r, c, d;
};

array<int, 4> dr = { 0,1,0,-1 };
array<int, 4> dc = { 1,0,-1,0 };

int BFS(Pos s, Pos t, vector<vector<bool>>& map)
{
    int n = map.size();
    int m = map[0].size();

    vector<vector<vector<int>>> dist(2, vector<vector<int>>(n, vector<int>(m, INT_MAX)));
    dist[0][s.r][s.c] = 1;

    queue<Pos> Q;
    Q.push(s);

    while (!Q.empty())
    {
        auto [r, c, d] = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;

            int nd = d + (map[nr][nc] == 1);
            if (nd >= 2 || dist[nd][nr][nc] != INT_MAX)
                continue;

            dist[nd][nr][nc] = dist[d][r][c] + 1;
            Q.push({ nr,nc,nd });
        }
    }

    return min(dist[0][t.r][t.c], dist[1][t.r][t.c]);
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<bool>> map(n, vector<bool>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char a;
            cin >> a;

            map[i][j] = a - '0';
        }
    }

    int result = BFS({ 0,0 }, { n - 1,m - 1 }, map);
    if (result == INT_MAX)
        cout << -1 << '\n';
    else
        cout << result << '\n';
}
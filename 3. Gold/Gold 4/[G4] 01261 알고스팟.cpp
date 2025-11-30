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

array<int, 4> dr = { 0,-1,0,1 };
array<int, 4> dc = { 1,0,-1,0 };

int BFS(vector<vector<char>>& map)
{
    int n = map.size();
    int m = map[0].size();

    vector<vector<int>> dist(n, vector<int>(m, n * m));
    dist[0][0] = 0;

    queue<Pos> Q;
    Q.push({ 0,0 });

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

            int nd = dist[r][c] + (map[nr][nc] == '1');
            if (nd >= dist[nr][nc])
                continue;

            dist[nr][nc] = nd;
            Q.push({ nr,nc });
        }
    }

    return dist[n - 1][m - 1];
}

int main()
{
    FastIO;

    int m, n;
    cin >> m >> n;

    vector<vector<char>> map(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    }

    int result = BFS(map);
    cout << result << '\n';
}
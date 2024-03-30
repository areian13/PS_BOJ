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

array<int, 4> dy = { 0,-1,0,1 };
array<int, 4> dx = { 1,0,-1,0 };

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
        int y = Q.front().y;
        int x = Q.front().x;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;

            int nd = dist[y][x] + (map[ny][nx] == '1');
            if (nd >= dist[ny][nx])
                continue;

            dist[ny][nx] = nd;
            Q.push({ ny,nx });
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
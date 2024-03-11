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

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { -1,0,1,0, };

int main()
{
    FastIO;

    int n = 2, m;
    cin >> m;

    vector<vector<char>> map(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    }

    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<int> distCount(n * m, 0);
    queue<Pos> Q;

    if (map[0][0] == '.')
    {
        dist[0][0] = 0;
        distCount[0]++;
        Q.push({ 0,0 });
    }
    if (map[1][0] == '.')
    {
        dist[1][0] = 0;
        distCount[0]++;
        Q.push({ 1,0 });
    }

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
            if (dist[ny][nx] != -1 || map[ny][nx] == '#')
                continue;

            dist[ny][nx] = dist[y][x] + 1;
            distCount[dist[ny][nx]]++;
            Q.push({ ny,nx });
        }
    }

    int result = 0;
    for (int i = 0; i < 2 * m; i++)
        result += (distCount[i] > 1);
    result += (map[0][m - 1] == map[1][m - 1] && dist[0][m - 1] != dist[1][m - 1]);

    cout << result << '\n';
}
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int y, x;
};

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { 1,0,-1,0 };

int CountJump(int y1, int x1, int y2, int x2, vector<vector<char>>& map)
{
    int n = map.size();
    int m = map[0].size();

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[y1][x1] = 0;

    queue<Pos> Q;
    Q.push({ y1,x1 });

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
            
            int nd = dist[y][x] + (map[ny][nx] != '0');
            if (dist[ny][nx] <= nd)
                continue;

            dist[ny][nx] = nd;
            Q.push({ ny,nx });
        }
    }
    return dist[y2][x2];
}

int main()
{
    FastIO;

    int n, m, y1, x1, y2, x2;
    cin >> n >> m >> y1 >> x1 >> y2 >> x2;
    y1--, x1--, y2--, x2--;

    vector<vector<char>> map(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    }

    int result = CountJump(y1, x1, y2, x2, map);
    cout << result << '\n';
}
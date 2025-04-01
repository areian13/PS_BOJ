#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int y, x;
};

struct Info
{
    Pos pos;
    int key;
};

array<int, 4> dy = { 1,0,-1,0 };
array<int, 4> dx = { 0,-1,0,1 };

int BFS(Pos& start, vector<vector<char>>& map)
{
    int n = map.size();
    int m = map[0].size();

    array<int, 1 << 6> temp;
    fill(temp.begin(), temp.end(), -1);
    vector<vector<array<int, 1 << 6>>> dist(n, vector<array<int, 1 << 6>>(m, temp));
    dist[start.y][start.x][000000] = 0;

    queue<Info> Q;
    Q.push({ start, 000000 });

    while (!Q.empty())
    {
        int y = Q.front().pos.y;
        int x = Q.front().pos.x;
        int key = Q.front().key;
        Q.pop();

        if (map[y][x] == '1')
            return dist[y][x][key];

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nKey = key;

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (map[ny][nx] == '#' || dist[ny][nx][nKey] != -1)
                continue;

            if ('A' <= map[ny][nx] && map[ny][nx] <= 'F')
            {
                if (!(nKey & 1 << (map[ny][nx] - 'A')))
                    continue;
            }

            if ('a' <= map[ny][nx] && map[ny][nx] <= 'f')
                nKey |= (1 << (map[ny][nx] - 'a'));

            dist[ny][nx][nKey] = dist[y][x][key] + 1;
            Q.push({ ny,nx,nKey });
        }
    }
    return -1;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<char>> map(n, vector<char>(m));
    Pos start;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == '0')
            {
                start = { i,j };
                map[i][j] = '.';
            }
        }
    }

    int result = BFS(start, map);
    cout << result << '\n';
}
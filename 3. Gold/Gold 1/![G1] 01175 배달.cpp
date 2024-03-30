#include <iostream>
#include <vector>
#include <queue>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int y, x, d, k;
};

array<int, 4> dy = { 0,-1,0,1 };
array<int, 4> dx = { 1,0,-1,0 };

int BFS(Pos& s, vector<vector<char>>& map)
{
    int n = map.size();
    int m = map[0].size();

    vector<vector<vector<vector<int>>>> dist(n, vector<vector<vector<int>>>(m,
        vector<vector<int>>(4, vector<int>(3, -1))));
    queue<Pos> Q;

    for (int i = 0; i < 4; i++)
    {
        int ny = s.y + dy[i];
        int nx = s.x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;

        dist[s.y][s.x][i][0] = 0;
        Q.push({ s.y,s.y,i,0 });
    }

    while (!Q.empty())
    {
        int y = Q.front().y;
        int x = Q.front().x;
        int d = Q.front().d;
        int k = Q.front().k;
        Q.pop();

        if (k == 2)
            return dist[y][x][d][k];

        for (int i = 0; i < 4; i++)
        {
            if (d == i)
                continue;

            int ny = y + dy[i];
            int nx = x + dx[i];
            int nd = i;

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;

            int nk = k + (map[ny][nx] == 'S');
            if (map[ny][nx] == '#' || dist[ny][nx][nd][nk] != -1)
                continue;

            dist[ny][nx][nd][nk] = dist[y][x][d][k] + 1;
            Q.push({ ny,nx,nd,nk });
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
    Pos s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'S')
                s = { i,j };
        }
    }

    int result = BFS(s, map);
    cout << result << '\n';
}
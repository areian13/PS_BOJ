#include <iostream>
#include <vector>
#include <queue>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int y, x, d;

    friend istream& operator>>(istream& is, Pos& p)
    {
        is >> p.y >> p.x >> p.d;
        return is;
    }
};

array<int, 4> dy = { 0,0,1,-1 };
array<int, 4> dx = { 1,-1,0,0 };

int CountTurn(int d, int i)
{
    if (i == 0)
        return 0;

    return (d % 2 == 0 && i == 1) || (d % 2 == 1 && i == 3) ? 2 : 1;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    }
    Pos s, e;
    cin >> s >> e;
    s.y--; s.x--; s.d--;
    e.y--; e.x--; e.d--;

    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(4, -1)));
    dist[s.y][s.x][s.d] = 0;

    queue<Pos> Q;
    Q.push(s);

    while (!Q.empty())
    {
        int y = Q.front().y;
        int x = Q.front().x;
        int d = Q.front().d;
        Q.pop();

        for (int i = 1; i <= 3; i++)
        {
            int nd = (d + i) % 4;
            int ndis = dist[y][x][d] + CountTurn(d, i);
            if (dist[y][x][nd] != -1 && dist[y][x][nd] <= ndis)
                continue;

            dist[y][x][nd] = ndis;
            Q.push({ y,x,nd });
        }

        for (int i = 1; i <= 3; i++)
        {
            int ny = y + dy[d] * i;
            int nx = x + dx[d] * i;

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (dist[ny][nx][d] != -1 && dist[ny][nx][d] <= dist[y][x][d] + 1)
                continue;
            if (map[ny][nx] == 1)
                break;

            dist[ny][nx][d] = dist[y][x][d] + 1;
            Q.push({ ny,nx,d });
        }
    }

    int result = dist[e.y][e.x][e.d];
    cout << result << '\n';
}
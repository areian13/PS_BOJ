#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 4> dy = { 1,0,-1,0 };
array<int, 4> dx = { 0,-1,0,1 };

struct Pos
{
    int y, x;
};

struct Edge
{
    Pos v;
    int w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

Edge Next(int y, int x, int d, vector<vector<char>>& map)
{
    int n = map.size();
    int m = map[0].size();

    int w = 0;
    while (true)
    {
        int ny = y + dy[d];
        int nx = x + dx[d];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            return { -1,-1,INT_MAX };
        if (map[ny][nx] == 'H')
            return { -1,-1,INT_MAX };

        if (map[ny][nx] == 'E')
            return { ny,nx,w };
        if (map[ny][nx] == 'R')
            return { y,x,w };

        w += (map[ny][nx] - '0');
        y = ny;
        x = nx;
    }
    return { -1,-1,INT_MAX };
}

int MinTime(Pos& s, Pos& t, vector<vector<char>>& map)
{
    int n = map.size();
    int m = map[0].size();

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[s.y][s.x] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ s,dist[s.y][s.x] });

    while (!PQ.empty())
    {
        int y = PQ.top().v.y;
        int x = PQ.top().v.x;
        int w = PQ.top().w;
        PQ.pop();

        if (dist[y][x] < w)
            continue;

        for (int i = 0; i < 4; i++)
        {
            Edge edge = Next(y, x, i, map);

            int ny = edge.v.y;
            int nx = edge.v.x;

            if (ny == -1 && nx == -1)
                continue;

            int nw = w + edge.w;
            if (dist[ny][nx] <= nw || dist[t.y][t.x] <= nw)
                continue;

            dist[ny][nx] = nw;
            PQ.push({ ny,nx,nw });
        }
    }

    if (dist[t.y][t.x] == INT_MAX)
        return -1;
    return dist[t.y][t.x];
}

int main()
{
    FastIO;

    int m, n;
    cin >> m >> n;

    vector<vector<char>> map(n, vector<char>(m));
    Pos s = { -1,-1 };
    Pos t = { -1,-1 };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 'T')
            {
                s = { i,j };
                map[i][j] = '0';
            }
            if (map[i][j] == 'E')
                t = { i,j };
        }
    }

    int result = MinTime(s, t, map);
    cout << result << '\n';
}
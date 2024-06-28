#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 8> dy = { -1,0,1,1,1,0,-1,-1 };
array<int, 8> dx = { 1,1,1,0,-1,-1,-1,0 };

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

int MinFuel(Pos& s, Pos& t, vector<vector<char>>& map)
{
    int n = map.size();
    int m = map[0].size();

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[s.y][s.x] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ s,0 });

    while (!PQ.empty())
    {
        int y = PQ.top().v.y;
        int x = PQ.top().v.x;
        int w = PQ.top().w;
        PQ.pop();

        if (dist[y][x] < w)
            continue;

        for (int i = 0; i < 8; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nw = w + (i > 2);

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (map[ny][nx] == '#' || dist[ny][nx] <= nw)
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

    int h, w;
    cin >> h >> w;

    vector<vector<char>> map(h, vector<char>(w));
    Pos s = { -1,-1 };
    Pos t = { -1,-1 };
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 'K')
                s = { i,j };
            if (map[i][j] == '*')
                t = { i,j };
        }
    }

    int result = MinFuel(s, t, map);
    cout << result << '\n';
}
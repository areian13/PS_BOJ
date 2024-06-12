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

struct Edge
{
    Pos v;
    int d;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.d > b.d;
    }
};

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { 1,0,-1,0 };

bool IsAdjacent(int y, int x, vector<vector<char>>& map)
{
    int h = map.size();
    int w = map[0].size();

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= h || nx < 0 || nx >= w)
            continue;
        if (map[ny][nx] == '#')
            return true;
    }
    return false;
}

int Rucio(Pos& s, Pos& e, vector<vector<char>>& map)
{
    int h = map.size();
    int w = map[0].size();

    vector<vector<int>> dist(h, vector<int>(w, INT_MAX));
    dist[s.y][s.x] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ s,0 });

    while (!PQ.empty())
    {
        int y = PQ.top().v.y;
        int x = PQ.top().v.x;
        int d = PQ.top().d;
        PQ.pop();

        if (dist[y][x] < d)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];


            if (ny < 0 || ny >= h || nx < 0 || nx >= w)
                continue;
            if (map[ny][nx] == '#')
                continue;

            int nd = d + !(IsAdjacent(y, x, map) && IsAdjacent(ny, nx, map));
            if (dist[ny][nx] <= nd)
                continue;

            dist[ny][nx] = nd;
            PQ.push({ ny,nx,nd });
        }
    }

    return dist[e.y][e.x];
}

int main()
{
    FastIO;

    int h, w;
    cin >> h >> w;

    vector<vector<char>> map(h, vector<char>(w));
    Pos s, e;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 'S')
                s = { i,j };
            if (map[i][j] == 'E')
                e = { i,j };
        }
    }

    int result = Rucio(s, e, map);
    cout << result << '\n';
}
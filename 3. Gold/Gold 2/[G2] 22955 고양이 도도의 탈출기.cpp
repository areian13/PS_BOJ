#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { 1,0,-1,0 };

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

int EscapeDodo(Pos& s, Pos& t, vector<vector<char>>& map)
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

        if (map[y][x] == 'X')
        {
            int ny = y + 1;
            int nw = w + 10;

            while (map[ny][x] == 'X' && dist[ny][x] > nw)
            {
                dist[ny][x] = nw;
                ny++;
            }
            if (map[ny][x] != 'D' && dist[ny][x] > nw)
            {
                dist[ny][x] = nw;
                PQ.push({ ny,x,nw });
            }
            continue;
        }
        if (y > 0 && map[y][x] == 'L')
        {
            int ny = y - 1;
            int nw = w + 5;

            if (map[ny][x] != 'D' && dist[ny][x] > nw)
            {
                dist[ny][x] = nw;
                PQ.push({ ny,x,nw });
            }
        }
        if (y < n - 1 && map[y + 1][x] == 'L')
        {
            int ny = y + 1;
            int nw = w + 5;

            if (dist[ny][x] > nw)
            {
                dist[ny][x] = nw;
                PQ.push({ ny,x,nw });
            }
        }

        for (int i : { 0,2 })
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;

            int nw = w + 1;
            if (map[ny][nx] == 'D' || dist[ny][nx] <= nw)
                continue;

            dist[ny][nx] = nw;
            PQ.push({ ny,nx,nw });
        }
    }

    return dist[t.y][t.x];
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<char>> map(n, vector<char>(m));
    Pos s = { -1,-1 };
    Pos t = { -1,-1 };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 'C')
                s = { i,j };
            if (map[i][j] == 'E')
                t = { i,j };
        }
    }

    int result = EscapeDodo(s, t, map);
    if (result == INT_MAX)
        cout << "dodo sad" << '\n';
    else
        cout << result << '\n';
}
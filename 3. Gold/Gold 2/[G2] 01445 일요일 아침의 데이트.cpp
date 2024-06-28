#include <iostream>
#include <vector>
#include <array>
#include <climits>
#include <queue>

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
    array<int, 2> w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        if (a.w[0] != b.w[0])
            return a.w[0] > a.w[1];
        return a.w[1] > b.w[1];
    }
};

bool IsGarbageSide(int y, int x, vector<vector<char>>& map)
{
    int n = map.size();
    int m = map[0].size();

    if (map[y][x] != '.')
        return false;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;
        if (map[ny][nx] == 'g')
            return true;
    }
    return false;
}

array<int, 2> NextW(int y, int x, array<int, 2>& w, vector<vector<char>>& map)
{
    if (map[y][x] == 'g')
        return { w[0] + 1,w[1] };
    return { w[0],w[1] + IsGarbageSide(y, x, map) };
}

array<int, 2> MinGarbage(Pos& s, Pos& t, vector<vector<char>>& map)
{
    int n = map.size();
    int m = map[0].size();

    vector<vector<array<int, 2>>> dist(n, vector<array<int, 2>>(m, { INT_MAX,INT_MAX }));
    dist[s.y][s.x] = { 0,0 };

    priority_queue<Edge> PQ;
    PQ.push({ s,0,0 });

    while (!PQ.empty())
    {
        int y = PQ.top().v.y;
        int x = PQ.top().v.x;
        array<int, 2> w = PQ.top().w;
        PQ.pop();

        if (dist[y][x] < w)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;

            array<int, 2> nw = NextW(ny, nx, w, map);
            if (dist[ny][nx] <= nw)
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

            if (map[i][j] == 'S')
                s = { i,j };
            if (map[i][j] == 'F')
                t = { i,j };
        }
    }

    array<int, 2> result = MinGarbage(s, t, map);
    cout << result[0] << ' ' << result[1] << '\n';
}
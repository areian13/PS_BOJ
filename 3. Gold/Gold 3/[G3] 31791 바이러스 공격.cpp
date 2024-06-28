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

void SafeArea(int tg, int tb, vector<Pos>& s, vector<vector<char>>& map, vector<Pos>& result)
{
    int n = map.size();
    int m = map[0].size();

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    priority_queue<Edge> PQ;

    for (Pos& pos : s)
    {
        dist[pos.y][pos.x] = 0;
        PQ.push({ pos,0 });
    }

    while (!PQ.empty())
    {
        int y = PQ.top().v.y;
        int x = PQ.top().v.x;
        int w = PQ.top().w;
        PQ.pop();

        if (w >= tg)
            continue;

        if (dist[y][x] < w)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;

            int nw = dist[y][x] + 1 + (map[ny][nx] == '#' ? tb : 0);
            if (dist[ny][nx] <= nw)
                continue;

            dist[ny][nx] = nw;
            PQ.push({ ny,nx,nw });
        }
    }

    bool canSafe = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dist[i][j] > tg)
                result.push_back({ i,j });
        }
    }
}

int main()
{
    FastIO;

    int n, m, tg, tb, x, b;
    cin >> n >> m >> tg >> tb >> x >> b;

    vector<vector<char>> map(n, vector<char>(m));
    vector<Pos> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == '*')
                s.push_back({ i,j });
        }
    }

    vector<Pos> result;
    SafeArea(tg, tb, s, map, result);

    if (result.empty())
        cout << -1 << '\n';
    else
    {
        for (Pos& pos : result)
            cout << pos.y + 1 << ' ' << pos.x + 1 << '\n';
    }
}
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
    int k;
    int w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { 1,0,-1,0 };

int MinImpulse(Pos& s, Pos& t, vector<vector<int>>& map)
{
    int n = map.size();
    int m = map[0].size();

    vector<vector<vector<int>>> dist(3, vector<vector<int>>(n, vector<int>(m, INT_MAX)));
    dist[0][s.y][s.x] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ s,0,dist[0][s.y][s.x] });

    while (!PQ.empty())
    {
        int y = PQ.top().v.y;
        int x = PQ.top().v.x;
        int k = PQ.top().k;
        int w = PQ.top().w;
        PQ.pop();

        if (dist[k][y][x] < w)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nk = (k + 1) % 3;

            if (nk == 1 && (i % 2) != 1)
                continue;
            if (nk == 2 && (i % 2) != 0)
                continue;

            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;

            int nw = w + map[ny][nx];
            if (map[ny][nx] == -1 || dist[nk][ny][nx] <= nw)
                continue;

            dist[nk][ny][nx] = nw;
            PQ.push({ ny,nx,nk,nw });
        }
    }

    int result = INT_MAX;
    for (int i = 0; i < 3; i++)
        result = min(result, dist[i][t.y][t.x]);

    if (result == INT_MAX)
        return -1;
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    Pos s, t;
    cin >> s.y >> s.x >> t.y >> t.x;
    s.y--, s.x--, t.y--, t.x--;

    vector<vector<int>> map(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    }

    int result = MinImpulse(s, t, map);
    cout << result << '\n';
}
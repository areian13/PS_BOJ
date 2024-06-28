#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <array>
#include <cmath>

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

int ctoi(char c)
{
    if ('A' <= c && c <= 'Z')
        return c - 'A';
    return c - 'a' + 26;
}

void Dijkstra(bool isGo, int t, vector<vector<int>>& dist, vector<vector<int>>& map)
{
    int n = map.size();
    int m = map[0].size();

    dist[0][0] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ 0,0,0 });

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
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;

            int d = map[y][x] - map[ny][nx];
            int nw = w + ((isGo ? d >= 0 : d <= 0) ? 1 : d * d);
            if (abs(d) > t || dist[ny][nx] <= nw)
                continue;

            dist[ny][nx] = nw;
            PQ.push({ ny,nx,nw });
        }
    }
}

int MaxHeight(int t, int d, vector<vector<int>>& map)
{
    int n = map.size();
    int m = map[0].size();

    vector<vector<int>> goDist(n, vector<int>(m, INT_MAX));
    Dijkstra(true, t, goDist, map);

    vector<vector<int>> comeDist(n, vector<int>(m, INT_MAX));
    Dijkstra(false, t, comeDist, map);

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (goDist[i][j] == INT_MAX || comeDist[i][j] == INT_MAX)
                continue;
            if (goDist[i][j] + comeDist[i][j] <= d)
                result = max(result, map[i][j]);
        }
    }
    return result;
}

int main()
{
    FastIO;

    int n, m, t, d;
    cin >> n >> m >> t >> d;

    vector<vector<int>> map(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char m;
            cin >> m;

            map[i][j] = ctoi(m);
        }
    }

    int result = MaxHeight(t, d, map);
    cout << result << '\n';
}
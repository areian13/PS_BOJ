#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 4> dy = { 1,0,-1,0 };
array<int, 4> dx = { 0,1,0,-1 };

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
        return a.w < b.w;
    }
};

void BFS(vector<vector<int>>& dist, queue<Pos>& Q)
{
    int n = dist.size();
    int m = dist[0].size();

    while (!Q.empty())
    {
        int y = Q.front().y;
        int x = Q.front().x;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (dist[ny][nx] != INT_MAX)
                continue;

            dist[ny][nx] = dist[y][x] + 1;
            Q.push({ ny,nx });
        }
    }
}

int SafeRouteDist(Pos& s, Pos& t, vector<vector<char>>& map)
{
    int n = map.size();
    int m = map[0].size();

    vector<vector<int>> treeDist(n, vector<int>(m, INT_MAX));
    queue<Pos> Q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] != '+')
                continue;

            treeDist[i][j] = 0;
            Q.push({ i,j });
        }
    }
    BFS(treeDist, Q);

    vector<vector<int>> dist(n, vector<int>(m, 0));
    dist[s.y][s.x] = treeDist[s.y][s.x];

    priority_queue<Edge> PQ;
    PQ.push({ s,treeDist[s.y][s.x] });

    while (!PQ.empty())
    {
        int y = PQ.top().v.y;
        int x = PQ.top().v.x;
        int w = PQ.top().w;
        PQ.pop();

        if (dist[y][x] > w)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;

            int nw = min(w, treeDist[ny][nx]);
            if(dist[ny][nx] >= nw)
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

            if (map[i][j] == 'V')
                s = { i,j };
            if (map[i][j] == 'J')
                t = { i,j };
        }
    }

    int result = SafeRouteDist(s, t, map);
    cout << result << '\n';
}
#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int u, v, w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w < b.w;
    }
};

struct Pos
{
    int y, x;
};

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { 1,0,-1,0 };

void BFS(Pos s, vector<Edge>& edges, vector<vector<int>>& map)
{
    int n = map.size();

    vector<vector<int>> dist(n, vector<int>(n, -1));
    dist[s.y][s.x] = 0;

    queue<Pos> Q;
    Q.push(s);

    while (!Q.empty())
    {
        int y = Q.front().y;
        int x = Q.front().x;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                continue;
            if (map[ny][nx] == -1 || dist[ny][nx] != -1)
                continue;

            dist[ny][nx] = dist[y][x] + 1;
            Q.push({ ny,nx });

            if (map[ny][nx] != -2)
                edges.push_back({ map[s.y][s.x],map[ny][nx],dist[ny][nx] });
        }
    }
}

void MakeEdges(vector<Edge>& edges, vector<vector<int>>& map)
{
    int n = map.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] >= 0)
                BFS({ i,j }, edges, map);
        }
    }
}

int Find(int u, vector<int>& p)
{
    if (p[u] == -1)
        return u;
    return p[u] = Find(p[u], p);
}

void Union(int u, int v, vector<int>& p)
{
    p[v] = u;
}

int MinReplicaDist(int n, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end());

    vector<int> p(n + 1, -1);
    int result = 0;
    int cnt = 0;
    for (Edge& edge : edges)
    {
        int u = Find(edge.u, p);
        int v = Find(edge.v, p);

        if (u == v)
            continue;

        Union(u, v, p);
        result += edge.w;
        cnt++;

        if (cnt == n)
            return result;
    }
    return -1;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(n));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;

            if (c == '0' || c == '1')
                map[i][j] = (c - '0' - 2);
            else
                map[i][j] = cnt++;
        }
    }

    vector<Edge> edges;
    MakeEdges(edges, map);

    int result = MinReplicaDist(m, edges);
    cout << result << '\n';
}
#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int r, c;
};

array<int, 4> dr = { 0,1,0,-1 };
array<int, 4> dc = { 1,0,-1,0 };

void BFS(Pos s, int u, vector<vector<int>>& map)
{
    int n = map.size();
    int m = map[0].size();

    map[s.r][s.c] = u;
    queue<Pos> Q;
    Q.push(s);

    while (!Q.empty())
    {
        auto [r, c] = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;
            if (map[nr][nc] != -1)
                continue;

            map[nr][nc] = u;
            Q.push({ nr,nc });
        }
    }
}

int Numbering(vector<vector<int>>& map)
{
    int n = map.size();
    int m = map[0].size();

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == -1)
                BFS({ i,j }, k++, map);
        }
    }
    return k;
}

struct Edge
{
    int u, v, w;

    friend bool operator < (const Edge& a, const Edge& b) { return a.w < b.w; }
};

void MakeEdges(vector<vector<int>>& map, vector<Edge>& edges)
{
    int n = map.size();
    int m = map[0].size();

    for (int i = 0; i < n; i++)
    {
        int c = -1;
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == -2)
                continue;
            if (c == -1 || map[i][c] == map[i][j])
            {
                c = j;
                continue;
            }

            int w = j - c - 1;
            if (w > 1)
                edges.push_back({ map[i][c],map[i][j],w });
            c = j;
        }
    }
    for (int j = 0; j < m; j++)
    {
        int r = -1;
        for (int i = 0; i < n; i++)
        {
            if (map[i][j] == -2)
                continue;
            if (r == -1 || map[r][j] == map[i][j])
            {
                r = i;
                continue;
            }

            int w = i - r - 1;
            if (w > 1)
                edges.push_back({ map[r][j],map[i][j],w });
            r = i;
        }
    }
}

struct UF
{
    vector<int> p;
    UF(int n) { p.resize(n, -1); }
    int Find(int u) { return p[u] < 0 ? u : p[u] = Find(p[u]); }
    void Union(int u, int v)
    {
        u = Find(u), v = Find(v);
        if (u == v)
            return;
        if (p[u] > p[v])
            swap(u, v);
        p[u] += p[v], p[v] = u;
    }
};

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            map[i][j] -= 2;
        }
    }
    int k = Numbering(map);

    vector<Edge> edges;
    MakeEdges(map, edges);
    sort(edges.begin(), edges.end());

    UF uf(k);
    int result = 0;
    for (auto& [u, v, w] : edges)
    {
        if (uf.Find(u) == uf.Find(v))
            continue;

        uf.Union(u, v);
        result += w;
    }

    if (-uf.p[uf.Find(0)] != k)
        cout << -1 << '\n';
    else
        cout << result << '\n';
}
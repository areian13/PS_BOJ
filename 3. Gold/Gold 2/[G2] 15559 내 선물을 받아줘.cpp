#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct UnionFind
{
    vector<int> p;

    UnionFind(int n) { p.resize(n, -1); }
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

struct Pos
{
    int r, c;
};

array<int, 4> dr = { 0,1,0,-1 };
array<int, 4> dc = { 1,0,-1,0 };

int V(char c)
{
    if (c == 'E')
        return 0;
    if (c == 'S')
        return 1;
    if (c == 'W')
        return 2;
    return 3;
}

void DFS(int r, int c, vector<vector<char>>& map, UnionFind& uf)
{
    int nr = r + dr[V(map[r][c])];
    int nc = c + dc[V(map[r][c])];

    int m = map[0].size();
    int u = r * m + c, v = nr * m + nc;
    if (uf.Find(u) == uf.Find(v))
        return;

    uf.Union(u, v);
    DFS(nr, nc, map, uf);
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<char>> map(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    }

    UnionFind uf(n * m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            DFS(i, j, map, uf);
    }

    int result = 0;
    for (int i = 0; i < n * m; i++)
        result += (uf.p[i] < 0);
    cout << result << '\n';
}
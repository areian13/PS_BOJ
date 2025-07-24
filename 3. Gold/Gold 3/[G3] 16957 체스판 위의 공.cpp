#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 8> dr = { 0,0,1,1,1,-1,-1,-1 };
array<int, 8> dc = { 1,-1,0,1,-1,0,1,-1 };

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
        p[u] += p[v], p[v] = u;
    }
};

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));
    UnionFind uf(n * m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int mn = map[i][j];
            int r = i, c = j;
            for (int k = 0; k < 9; k++)
            {
                int nr = i + dr[k];
                int nc = j + dc[k];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                if (mn > map[nr][nc])
                {
                    mn = map[nr][nc];
                    r = nr, c = nc;
                }
            }
            uf.Union(r * m + c, i * m + j);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (uf.p[i * m + j] < 0)
                cout << -uf.p[i * m + j] << ' ';
            else
                cout << 0 << ' ';
        }
        cout << '\n';
    }
}
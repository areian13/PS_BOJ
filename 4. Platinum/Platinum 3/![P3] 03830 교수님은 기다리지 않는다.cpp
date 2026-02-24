#include <iostream>
#include <vector>
#include <climits>
#include <map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

struct MST
{
    vector<int> p;

    MST(int n) { p.resize(n, -1); }
    int Find(int u) { return p[u] < 0 ? u : p[u] = Find(p[u]); }
    void Union(int u, int v)
    {
        u = Find(u), v = Find(v);
        if (u == v) return;
        if (p[u] > p[v]) swap(u, v);
        p[u] += p[v], p[v] = u;
    }
};

int Gap(int p, int u, int t, vector<vector<int>>& graph,
    map<int, map<int, int>>& dp)
{
    if (dp[u].count(t) == 1)
        return dp[u][t];

    int result = 0;
    for (int v : graph[u])
    {
        if (v == p)
            continue;
        result += Gap(u, v, t, graph, dp) + dp[u][v];
    }
    return dp[u][t] = result;
}

int main()
{
    FastIO;

    while (true)
    {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        MST mst(n);
        vector<vector<int>> graph(n);
        for (int i = 0; i < m; i++)
        {
            char c;
            int u, v;
            cin >> c >> u >> v;
            u--, v--;

            if (c == '!')
            {
                int w;
                cin >> w;

                if (mst.Find(u) == mst.Find(v))
                    continue;

                mst.Union(u, v);
            }
            else
            {
                if (mst.Find(u) != mst.Find(v))
                    cout << "UNKNOWN" << '\n';
                else

            }
        }
    }
}
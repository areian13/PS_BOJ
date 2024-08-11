#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int u, v, w;
};

bool CanGoPast(int n, vector<Edge>& edges)
{
    vector<int> dist(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (Edge& edge : edges)
        {
            int u = edge.u;
            int v = edge.v;

            int nw = dist[u] + edge.w;
            if (dist[v] > nw)
            {
                if (i == n - 1)
                    return true;
                dist[v] = nw;
            }
        }
    }
    return false;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        vector<Edge> edges(m * 2 + k);
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;

            edges[i * 2] = { u,v,w };
            edges[i * 2 + 1] = { v,u,w };
        }

        for (int i = 0; i < k; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;

            edges[m * 2 + i] = { u,v,-w };
        }

        string result = CanGoPast(n, edges) ? "YES" : "NO";
        cout << result << '\n';
    }
}
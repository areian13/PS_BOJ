#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int u, v, w;
};

bool BF(int s, vector<long long>& dist, vector<Edge>& edges)
{
    int n = dist.size();

    dist[s] = 0;

    for (int i = 0; i < n; i++)
    {
        for (Edge& edge : edges)
        {
            int u = edge.u;
            int v = edge.v;

            if (dist[u] == LLONG_MAX)
                continue;

            long long nw = dist[u] + edge.w;
            if (dist[v] > nw)
            {
                if (i == n - 1)
                    return false;
                dist[v] = nw;
            }
        }
    }
    return true;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        edges[i] = { u,v,w };
    }

    vector<long long> dist(n, LLONG_MAX);

    if (!BF(0, dist, edges))
        cout << -1 << '\n';
    else
    {
        for (int i = 1; i < n; i++)
        {
            if (dist[i] == LLONG_MAX)
                cout << -1 << '\n';
            else
                cout << dist[i] << '\n';
        }
    }
}
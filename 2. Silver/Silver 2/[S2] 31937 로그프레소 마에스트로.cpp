#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int u, v, t;
};

int main()
{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> u(k);
    vector<bool> isInfected(n, false);
    for (int i = 0; i < k; i++)
    {
        cin >> u[i];
        u[i]--;

        isInfected[u[i]] = true;
    }

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        int t, u, v;
        cin >> t >> u >> v;
        u--, v--;

        edges[i] = { u,v,t };
    }
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b)
        {
            return a.t < b.t;
        }
    );

    int result = -1;
    for (int i = 0; i < k; i++)
    {
        vector<bool> isVisited(n, false);
        isVisited[u[i]] = true;

        int cnt = 1;
        for (Edge& edge : edges)
        {
            int u = edge.u;
            int v = edge.v;

            if (isVisited[u] && !isInfected[v])
                break;
            if (!isVisited[u] || isVisited[v] || !isInfected[v])
                continue;

            isVisited[v] = true;
            cnt++;
        }

        if (cnt == k)
        {
            result = u[i];
            break;
        }
    }

    cout << result + 1 << '\n';
}
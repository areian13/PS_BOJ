#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int u, v, d;
};

bool BF(bool isWrong, int n, vector<Edge>& edges)
{
    vector<int> dist(n + 1, INT_MAX);
    dist[1] = 0;
    for (int i = 0; i < n - isWrong - 1; i++)
    {
        for (Edge& edge : edges)
        {
            int u = edge.u;
            int v = edge.v;
            int d = edge.d;

            if (dist[u] != INT_MAX && dist[v] > dist[u] + d)
                dist[v] = dist[u] + d;
        }
    }

    for (Edge& edge : edges)
    {
        int u = edge.u;
        int v = edge.v;
        int d = edge.d;

        if (dist[u] != INT_MAX && dist[v] > dist[u] + d)
            return false;
    }

    return true;
}

int main()
{
    FastIO;

    int n = 50;
    int m = n;

    vector<Edge> edges(m);
    for (int i = 0; i < m - 1; i++)
        edges[i] = { m - i - 1,m - i, -1 };
    edges[m - 1] = { 1,n,-1 };

    bool correct = BF(false, n, edges);
    bool wrong = BF(true, n, edges);

    if (correct != wrong)
    {
        cout << n << ' ' << m << '\n';
        for (Edge& edge : edges)
            cout << edge.u << ' ' << edge.v << ' ' << edge.d << '\n';
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int y, x;
};

struct Edge
{
    int u;
    int v;
    int w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w < b.w;
    }
};

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

int MinNetworkCost(int r, int c, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end());

    vector<int> par(r * c, -1);
    int result = 0;
    for (Edge& edge : edges)
    {
        int u = Find(edge.u, par);
        int v = Find(edge.v, par);

        if (u == v)
            continue;

        Union(u, v, par);
        result += edge.w;
    }
    return result;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int r, c;
        cin >> r >> c;

        int k = r * c * 2 - r - c;
        vector<Edge> edges(k);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c - 1; j++)
            {
                int w;
                cin >> w;

                int u = i * c + j;
                int v = u + 1;
                edges[--k] = { u,v,w };
            }
        }
        for (int i = 0; i < r - 1; i++)
        {
            for (int j = 0; j < c; j++)
            {
                int w;
                cin >> w;

                int u = i * c + j;
                int v = u + c;
                edges[--k] = { u,v,w };
            }
        }

        int result = MinNetworkCost(r, c, edges);
        cout << result << '\n';
    }
}
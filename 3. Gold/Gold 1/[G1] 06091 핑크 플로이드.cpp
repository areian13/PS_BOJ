#include <iostream>
#include <vector>
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

void MakeTree(vector<Edge>& edges, vector<vector<int>>& result)
{
    int n = result.size();
    sort(edges.begin(), edges.end());

    vector<int> p(n, -1);
    for (Edge& edge : edges)
    {
        int u = Find(edge.u, p);
        int v = Find(edge.v, p);

        if (u == v)
            continue;

        Union(u, v, p);
        result[edge.u].push_back(edge.v);
        result[edge.v].push_back(edge.u);
    }
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Edge> edges;
    for (int u = 0; u < n - 1; u++)
    {
        for (int v = 1; v <= n - 1; v++)
        {
            if (u >= v)
                continue;

            int w;
            cin >> w;

            edges.push_back({ u,v,w });
        }
    }

    vector<vector<int>> result(n);
    MakeTree(edges, result);

    for (int i = 0; i < n; i++)
    {
        int m = result[i].size();
        sort(result[i].begin(), result[i].end());

        cout << m << ' ';
        for (int j = 0; j < m; j++)
            cout << result[i][j] + 1 << ' ';
        cout << '\n';
    }
}
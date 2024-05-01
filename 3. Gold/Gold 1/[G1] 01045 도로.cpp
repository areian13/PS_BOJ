#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int u, v;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        if (a.u != b.u)
            return a.u < b.u;
        return a.v < b.v;
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

vector<int> RoadPriority(int n, int m, vector<Edge>& edges)
{
    int k = edges.size();

    vector<int> p(n, -1);
    vector<bool> isUsed(k, false);
    vector<int> result(n, 0);
    int cnt = 0;
    for (int i = 0; i < k; i++)
    {
        Edge& edge = edges[i];

        int u = Find(edge.u, p);
        int v = Find(edge.v, p);

        if (u == v)
            continue;

        Union(u, v, p);
        result[edge.u]++;
        result[edge.v]++;
        isUsed[i] = true;
        cnt++;

        if (cnt == n - 1)
            break;
    }

    if (cnt != n - 1)
        return { -1 };

    for (int i = 0; i < k && cnt < m; i++)
    {
        if (isUsed[i])
            continue;

        Edge& edge = edges[i];
        result[edge.u]++;
        result[edge.v]++;
        cnt++;
    }

    if (cnt != m)
        return { -1 };
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    for (int u = 0; u < n; u++)
    {
        for (int v = 0; v < n; v++)
        {
            char c;
            cin >> c;

            if (u >= v || c != 'Y')
                continue;

            edges.push_back({ u,v });
        }
    }

    vector<int> result = RoadPriority(n, m, edges);
    for (int x : result)
        cout << x << ' ';
    cout << '\n';
}
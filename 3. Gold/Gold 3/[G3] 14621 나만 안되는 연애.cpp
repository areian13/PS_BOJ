#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int u, v, d;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.d < b.d;
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

int MinMeetingRoute(int n, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end());

    vector<int> p(n, -1);
    int result = 0;
    int cnt = 0;
    for (Edge& edge : edges)
    {
        int u = Find(edge.u, p);
        int v = Find(edge.v, p);

        if (u == v)
            continue;

        Union(u, v, p);
        result += edge.d;
        cnt++;

        if (cnt == n - 1)
            return result;
    }
    return -1;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<char> g(n);
    for (int i = 0; i < n; i++)
        cin >> g[i];

    vector<Edge> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        u--, v--;

        if (g[u] == g[v])
            continue;

        edges.push_back({ u,v,d });
    }

    int result = MinMeetingRoute(n, edges);
    cout << result << '\n';
}
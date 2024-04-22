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
    friend bool operator>(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
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

int Fatigue(bool type, int n, vector<Edge>& edges)
{
    if (type == false)
        sort(edges.begin(), edges.end(), less<Edge>());
    else
        sort(edges.begin(), edges.end(), greater<Edge>());

    vector<int> p(n, -1);
    int result = 0;
    for (Edge& edge : edges)
    {
        int u = Find(edge.u, p);
        int v = Find(edge.v, p);

        if (u == v)
            continue;

        Union(u, v, p);
        result += edge.w;
    }
    result *= result;

    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;
    n++, m++;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        w = !w;

        edges[i] = { u,v,w };
    }

    int result = Fatigue(true, n, edges) - Fatigue(false, n, edges);
    cout << result << '\n';
}
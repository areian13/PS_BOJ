#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

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
    p[Find(v, p)] = Find(u, p);
}

int MinTravelCost(int n, vector<int>& c, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end());

    vector<int> p(n, -1);
    int result = *min_element(c.begin(), c.end());
    for (Edge& edge : edges)
    {
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;

        if (Find(u, p) == Find(v, p))
            continue;

        Union(u, v, p);
        result += w;
    }
    return result;
}

int main()
{
    FastIO;

    int n, p;
    cin >> n >> p;

    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    vector<Edge> edges(p);
    for (int i = 0; i < p; i++)
    {
        int s, e, l;
        cin >> s >> e >> l;
        s--, e--;

        edges[i] = { s,e,l * 2 + c[s] + c[e] };
    }

    int result = MinTravelCost(n, c, edges);
    cout << result << '\n';
}
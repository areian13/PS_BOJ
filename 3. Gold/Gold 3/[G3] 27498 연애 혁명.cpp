#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int a, b, c, d;

    friend bool operator>(const Edge& a, const Edge& b)
    {
        if (a.d != b.d)
            return a.d > b.d;
        return a.c > b.c;
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

int MinLostLove(int n, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end(), greater<Edge>());

    vector<int> p(n, -1);
    int result = 0;
    for (Edge& edge : edges)
    {
        int u = Find(edge.a, p);
        int v = Find(edge.b, p);

        if (u == v)
        {
            result += edge.c;
            continue;
        }

        Union(u, v, p);
    }
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--;

        edges[i] = { a,b,c,d };
    }

    int result = MinLostLove(n, edges);
    cout << result << '\n';
}
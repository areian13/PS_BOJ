#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int a, b, c;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.c < b.c;
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

long long SaveMoney(int n, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end());

    vector<int> p(n, -1);
    long long result = 0;
    int cnt = 0;
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
        cnt++;
    }

    result = (cnt == n - 1 ? result : -1);
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
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;

        edges[i] = { a,b,c };
    }

    long long result = SaveMoney(n, edges);
    cout << result << '\n';
}
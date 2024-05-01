#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int x, y;
    char z;
    long long w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        if (a.z != b.z)
            return a.z < b.z;
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

vector<string> MinSignAndCost(int n, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end());

    vector<int> p(n, -1);
    string sign = "";
    long long cost = 0;
    int cnt = 0;
    for (Edge& edge : edges)
    {
        int u = Find(edge.x, p);
        int v = Find(edge.y, p);

        if (u == v)
            continue;

        Union(u, v, p);
        sign += edge.z;
        cost += edge.w;
        cnt++;

        if (cnt == n - 1)
            return { sign,to_string(cost) };
    }
    return { "-1" };
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        char z;
        long long w;
        cin >> x >> y >> z >> w;
        x--, y--;

        edges[i] = { x,y,z,w };
        
    }

    vector<string> result = MinSignAndCost(n, edges);
    for (string& x : result)
        cout << x << ' ';
    cout << '\n';
}
#include <iostream>
#include <vector>>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct W
{
    int c, t;

    friend bool operator<(const W& a, const W& b)
    {
        return a.c < b.c && a.t < b.t;
    }
    friend bool operator>(const W& a, const W& b)
    {
        return a.c > b.c && a.t > b.t;
    }
};

struct Edge
{
    int v;
    W w;
};

int main()
{
    FastIO;

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, c, t;
        cin >> u >> v >> c >> t;
        u--, v--;

        graph[u].push_back({ v,c,t });
        graph[v].push_back({ u,c,t });
    }


}
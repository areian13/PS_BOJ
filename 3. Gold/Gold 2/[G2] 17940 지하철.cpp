#include <iostream>
#include <vector>
#include <array>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct W
{
    int k, d;

    friend bool operator>(const W& a, const W& b)
    {
        if (a.k != b.k)
            return a.k > b.k;
        return a.d > b.d;
    }
    friend bool operator<(const W& a, const W& b)
    {
        if (a.k != b.k)
            return a.k < b.k;
        return a.d < b.d;
    }
    friend bool operator<=(const W& a, const W& b)
    {
        if (a.k != b.k)
            return a.k < b.k;
        return a.d <= b.d;
    }
    friend W operator+(const W& a, const W& b)
    {
        return { a.k + b.k,a.d + b.d };
    }
};

struct Edge
{
    int v;
    W w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

W BestSubway(int s, int t, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    vector<W> dist(n, { INT_MAX,INT_MAX });
    dist[s] = { 0,0 };

    priority_queue<Edge> PQ;
    PQ.push({ s,dist[s] });

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        W w = PQ.top().w;
        PQ.pop();

        if (dist[u] < w)
            continue;

        for (Edge& edge : graph[u])
        {
            int v = edge.v;
            W nw = w + edge.w;

            if (dist[v] <= nw)
                continue;

            dist[v] = nw;
            PQ.push({ v,nw });
        }
    }
    return dist[t];
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    vector<vector<Edge>> graph(n);
    for (int u = 0; u < n; u++)
    {
        for (int v = 0; v < n; v++)
        {
            int w;
            cin >> w;

            if (u >= v || w == 0)
                continue;

            graph[u].push_back({ v,c[u] != c[v],w });
            graph[v].push_back({ u,c[u] != c[v],w });
        }
    }

    W result = BestSubway(0, m, graph);
    cout << result.k << ' ' << result.d << '\n';
}
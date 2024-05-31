#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v, w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

int NearestHome(vector<int>& h, vector<int>& c, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    vector<int> dist(n, INT_MAX);
    priority_queue<Edge> PQ;
    for (int x : c)
    {
        dist[x] = 0;
        PQ.push({ x,0 });
    }

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        int w = PQ.top().w;
        PQ.pop();

        if (dist[u] < w)
            continue;

        for (Edge& edge : graph[u])
        {
            int v = edge.v;
            int nw = w + edge.w;

            if (dist[v] <= nw)
                continue;

            dist[v] = nw;
            PQ.push({ v,nw });
        }
    }

    int result = -1;
    sort(h.begin(), h.end());
    for (int x : h)
    {
        if (result == -1 || dist[x] < dist[result])
            result = x;
    }
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        graph[u].push_back({ v,w });
        graph[v].push_back({ u,w });
    }

    int p, q;
    cin >> p >> q;

    vector<int> h(p);
    for (int i = 0; i < p; i++)
    {
        cin >> h[i];
        h[i]--;
    }

    vector<int> c(q);
    for (int i = 0; i < q; i++)
    {
        cin >> c[i];
        c[i]--;
    }

    int result = NearestHome(h, c, graph);
    cout << result + 1 << '\n';
}
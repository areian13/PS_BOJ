#include <iostream>
#include <vector>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v;
    long long w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

void Dijkstra(vector<int>& s, vector<long long>& dist, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    priority_queue<Edge> PQ;
    for (int i : s)
    {
        dist[i] = 0;
        PQ.push({ i,0 });
    }

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        long long w = PQ.top().w;
        PQ.pop();

        if (dist[u] < w)
            continue;

        for (Edge& edge : graph[u])
        {
            int v = edge.v;
            long long nw = w + edge.w;

            if (dist[v] <= nw)
                continue;

            dist[v] = nw;
            PQ.push({ v,nw });
        }
    }
}

void GetCanGo(vector<long long>& pDist, vector<long long>& cDist, vector<int>& result)
{
    int n = pDist.size();

    for (int i = 1; i < n; i++)
    {
        if (pDist[i] < cDist[i])
            result.push_back(i);
    }
    if (result.empty())
        result.push_back(-1);
}

int main()
{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        graph[u].push_back({ v,w });
        graph[v].push_back({ u,w });
    }

    vector<int> p(1, 0);
    vector<long long> pDist(n, LLONG_MAX);
    Dijkstra(p, pDist, graph);

    vector<int> c(k);
    for (int i = 0; i < k; i++)
    {
        cin >> c[i];
        c[i]--;
    }

    vector<long long> cDist(n, LLONG_MAX);
    Dijkstra(c, cDist, graph);

    vector<int> result;
    GetCanGo(pDist, cDist, result);

    for (int x : result)
        cout << x + 1 << ' ';
    cout << '\n';
}
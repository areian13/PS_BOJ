#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int u, v;
    long long w;
    int k;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

long long MinTime(int s, int t, vector<vector<vector<Edge>>>& graph)
{
    int p = graph.size();
    int n = graph[0].size();

    vector<vector<long long>> dist(n, vector<long long>(p, LLONG_MAX));
    dist[s][0] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ -1,s,0,0 });

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        long long w = PQ.top().w;
        int k = PQ.top().k;
        PQ.pop();

        for (int i = k; i < p; i++)
        {
            int nk = i;

            if (nk >= p)
                break;

            for (Edge& edge : graph[nk][u])
            {
                int v = edge.v;
                long long nw = w + edge.w;

                if (dist[v][nk] <= nw)
                    continue;

                dist[v][nk] = nw;
                PQ.push({ u,v,nw,nk });
            }
        }
    }
    return *min_element(dist[t].begin(), dist[t].end());
}

int main()
{
    FastIO;

    int n, m, a, b;
    cin >> n >> m >> a >> b;
    a--, b--;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        edges[i] = { u,v,w,0 };
    }

    int k;
    cin >> k;

    vector<vector<vector<Edge>>> graph(k + 1, vector<vector<Edge>>(n));
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int w;

            if (i == 0)
                w = edges[j].w;
            else
                cin >> w;

            int u = edges[j].u;
            int v = edges[j].v;

            graph[i][u].push_back({ u,v,w,i });
            graph[i][v].push_back({ v,u,w,i });
        }
    }

    long long result = MinTime(a, b, graph);
    cout << result << '\n';
}
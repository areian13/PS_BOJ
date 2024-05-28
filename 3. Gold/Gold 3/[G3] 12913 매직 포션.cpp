#include <iostream>
#include <vector>
#include <cfloat>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

struct Edge
{
    int v;
    double w;
    int k;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

double MinDist(int s, int t, int k, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    vector<double> dist(n, DBL_MAX);
    dist[s] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ s,0,k });

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        double w = PQ.top().w;
        int k = PQ.top().k;
        PQ.pop();

        for (int i = 0; i < 2; i++)
        {
            if (i == 1 && k == 0)
                break;

            for (Edge& edge : graph[u])
            {
                int v = edge.v;
                double nw = w + edge.w * (i == 1 ? 0.5 : 1.0);
                int nk = k - (i == 1);

                if (dist[v] <= nw)
                    continue;

                dist[v] = nw;
                PQ.push({ v,nw,nk });
            }
        }
    }
    return dist[t];
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<vector<Edge>> graph(n);
    for (int u = 0; u < n; u++)
    {
        for (int v = 0; v < n; v++)
        {
            char c;
            cin >> c;

            if (u >= v)
                continue;

            double w = (c - '0');
            graph[u].push_back({ v,w });
            graph[v].push_back({ u,w });
        }
    }

    lf(9);
    double result = MinDist(0, 1, k, graph);
    cout << result << '\n';
}
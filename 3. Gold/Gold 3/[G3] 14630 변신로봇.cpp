#include <iostream>
#include <vector>
#include <string>
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

int Dist(string& a, string& b)
{
    int result = 0;
    int k = a.size();
    for (int i = 0; i < k; i++)
    {
        int d = (a[i] - '0') - (b[i] - '0');
        result += d * d;
    }
    return result;
}

int MinCost(int s, int t, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    vector<int> dist(n, INT_MAX);
    dist[s] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ s,0 });

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
    return dist[t];
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<string> state(n);
    for (int i = 0; i < n; i++)
        cin >> state[i];

    vector<vector<Edge>> graph(n);
    for (int u = 0; u < n - 1; u++)
    {
        for (int v = u + 1; v < n; v++)
        {
            int w = Dist(state[u], state[v]);

            graph[u].push_back({ v,w });
            graph[v].push_back({ u,w });
        }
    }

    int s, t;
    cin >> s >> t;
    s--, t--;

    int result = MinCost(s, t, graph);
    cout << result << '\n';
}
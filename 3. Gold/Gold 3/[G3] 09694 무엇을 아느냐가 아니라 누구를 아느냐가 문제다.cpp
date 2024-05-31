#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int u, v, w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

void MakeSeq(vector<vector<Edge>>& graph, vector<int>& result)
{
    int m = graph.size();

    vector<Edge> dist(m, { -1,-1,INT_MAX });
    dist[0] = { -1,0,0 };

    priority_queue<Edge> PQ;
    PQ.push(dist[0]);

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        int w = PQ.top().w;
        PQ.pop();

        if (dist[u].w < w)
            continue;

        for (Edge& edge : graph[u])
        {
            int v = edge.v;
            int nw = w + edge.w;

            if (dist[v].w <= nw)
                continue;

            dist[v] = { u,v,nw };
            PQ.push(dist[v]);
        }
    }

    if (dist[m - 1].w == INT_MAX)
    {
        result.push_back(-1);
        return;
    }

    int x = m - 1;
    while (dist[x].u != -1)
    {
        result.push_back(x);
        x = dist[x].u;
    }
    result.push_back(0);
    reverse(result.begin(), result.end());
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<Edge>> graph(m);
        for (int i = 0; i < n; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;

            graph[u].push_back({ u,v,w });
            graph[v].push_back({ v,u,w });
        }

        vector<int> result;
        MakeSeq(graph, result);

        printf("Case #%d: ", t);
        for (int x : result)
            printf("%d ", x);
        printf("\n");
    }
}
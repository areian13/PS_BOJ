#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v, w;
    bool isSaved;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        if (a.w != b.w)
            return a.w > b.w;
        return a.isSaved < b.isSaved;
    }
};

bool CanSave(int p, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    vector<Edge> dist(n, { -1,INT_MAX,false });
    dist[0] = { 0,0,p == 0 };

    priority_queue<Edge> PQ;
    PQ.push(dist[0]);

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        int w = PQ.top().w;
        bool wasSaved = PQ.top().isSaved;
        PQ.pop();

        if (dist[u].w < w)
            continue;

        for(Edge& edge : graph[u])
        {
            int v = edge.v;
            int nw = w + edge.w;
            bool isSaved = (wasSaved || v == p);

            if (dist[v].w < nw)
                continue;
            if (dist[v].w == nw && !isSaved)
                continue;

            dist[v] = { v,nw,isSaved };
            PQ.push(dist[v]);
        }
    }

    return dist[n - 1].isSaved;
}

int main()
{
    FastIO;

    int v, e, p;
    cin >> v >> e >> p;
    p--;

    vector<vector<Edge>> graph(v);
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        graph[u].push_back({ v,w });
        graph[v].push_back({ u,w });
    }

    string result = (CanSave(p, graph) ? "SAVE HIM" : "GOOD BYE");
    cout << result << '\n';
}
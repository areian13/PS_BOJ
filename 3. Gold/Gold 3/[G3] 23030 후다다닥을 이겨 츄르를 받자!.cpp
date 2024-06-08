#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Node
{
    int l, s;
};

struct Edge
{
    Node v;
    int w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

int MinTime(int t, int s1, int s2, int t1, int t2, vector<vector<vector<Edge>>>& graph)
{
    int n = graph.size();

    vector<vector<int>> dist(n);
    for (int i = 0; i < n; i++)
        dist[i].resize(graph[i].size(), INT_MAX);
    dist[s1][s2] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ s1,s2,0 });

    while (!PQ.empty())
    {
        int u1 = PQ.top().v.l;
        int u2 = PQ.top().v.s;
        int w = PQ.top().w;
        PQ.pop();

        if (dist[u1][u2] < w)
            continue;

        for (Edge& edge : graph[u1][u2])
        {
            int v1 = edge.v.l;
            int v2 = edge.v.s;
            int nw = w + (edge.w == -1 ? t : edge.w);

            if (dist[v1][v2] <= nw)
                continue;

            dist[v1][v2] = nw;
            PQ.push({ v1,v2,nw });
        }
    }
    return dist[t1][t2];
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<vector<Edge>>> graph(n);
    for (int l = 0; l < n; l++)
    {
        int c;
        cin >> c;

        graph[l].resize(c);

        for (int s = 0; s < c - 1; s++)
        {
            graph[l][s].push_back({ l,s + 1,1 });
            graph[l][s + 1].push_back({ l,s,1 });
        }
    }

    int m;
    cin >> m;

    while (m--)
    {
        int p1, p2, q1, q2;
        cin >> p1 >> p2 >> q1 >> q2;
        p1--, p2--, q1--, q2--;

        graph[p1][p2].push_back({ q1,q2,-1 });
        graph[q1][q2].push_back({ p1,p2,-1 });
    }

    int k;
    cin >> k;

    while (k--)
    {
        int t, u1, u2, v1, v2;
        cin >> t >> u1 >> u2 >> v1 >> v2;
        u1--, u2--, v1--, v2--;

        int result = MinTime(t, u1, u2, v1, v2, graph);
        cout << result << '\n';
    }
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v, w;
    bool isPassed;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

void CanGo(int s, vector<int>& x, vector<vector<Edge>>& graph, vector<int>& result)
{
    int n = graph.size();

    vector<vector<int>> dist(2, vector<int>(n, INT_MAX));
    dist[0][s] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ s,0,false });

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        int w = PQ.top().w;
        bool wasPassed = PQ.top().isPassed;
        PQ.pop();

        if (dist[wasPassed][u] < w)
            continue;

        for (int i = 0; i < 2; i++)
        {
            for (Edge& edge : graph[u])
            {
                int v = edge.v;
                int nw = w + edge.w;
                bool isPassed = wasPassed || (edge.isPassed) * i;

                if (dist[isPassed][v] <= nw)
                    continue;

                dist[isPassed][v] = nw;
                PQ.push({ v,nw,isPassed });
            }
        }
    }

    for (int t : x)
    {
        if (dist[0][t] == dist[1][t] && dist[1][t] != INT_MAX)
            result.push_back(t);
    }
    sort(result.begin(), result.end());
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, m, t, s, g, h;
        cin >> n >> m >> t >> s >> g >> h;
        s--, g--, h--;

        if (g > h)
            swap(g, h);

        vector<vector<Edge>> graph(n);
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;

            bool isPassed = (u == g && v == h);
            graph[u].push_back({ v,w,isPassed });
            graph[v].push_back({ u,w,isPassed });
        }

        vector<int> x(t);
        for (int i = 0; i < t; i++)
        {
            cin >> x[i];
            x[i]--;
        }

        vector<int> result;
        CanGo(s, x, graph, result);

        for (int x : result)
            cout << x + 1 << ' ';
        cout << '\n';
    }
}
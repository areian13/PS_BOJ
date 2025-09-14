#include <iostream>
#include <vector>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

struct Edge
{
    int v, w;

    friend bool operator < (const Edge& a, const Edge& b) { return a.w > b.w; }
};

void Dijkstra(int s, vector<int>& dist, vector<vector<Edge>>& graph)
{
    dist[s] = 0;
    priority_queue<Edge> PQ;
    PQ.push({ s,0 });

    while (!PQ.empty())
    {
        auto [u, d] = PQ.top();
        PQ.pop();

        if (dist[u] < d)
            continue;

        for (auto& [v, w] : graph[u])
        {
            int nd = d + w;
            if (dist[v] <= nd)
                continue;

            dist[v] = nd;
            PQ.push({ v,nd });
        }
    }
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n, d, c;
        cin >> n >> d >> c;
        c--;

        vector<vector<Edge>> graph(n);
        for (int i = 0; i < d; i++)
        {
            int a, b, s;
            cin >> a >> b >> s;
            a--, b--;

            graph[b].push_back({ a,s });
        }

        vector<int> dist(n, INF);
        Dijkstra(c, dist, graph);

        int cnt = 0, last = 0;
        for (int i = 0; i < n; i++)
        {
            if (dist[i] == INF)
                continue;

            cnt++;
            last = max(last, dist[i]);
        }

        cout << cnt << ' ' << last << '\n';
    }
}
#include <iostream>
#include <vector>
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

void Dijkstra(vector<int>& s, vector<int>& dist, vector<vector<Edge>>& graph)
{
    int n = graph.size();
    int m = s.size();

    priority_queue<Edge> PQ;
    for (int i = 0; i < m; i++)
    {
        dist[s[i]] = 0;
        PQ.push({ s[i],0 });
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
}

int GoodHome(int x, int y, vector<int>& mac, vector<int>& star, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    vector<int> macDist(n, INT_MAX);
    Dijkstra(mac, macDist, graph);

    vector<int> starDist(n, INT_MAX);
    Dijkstra(star, starDist, graph);

    int result = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (macDist[i] > x || starDist[i] > y)
            continue;
        if (macDist[i] == 0 || starDist[i] == 0)
            continue;

        result = min(result, macDist[i] + starDist[i]);
    }

    if (result == INT_MAX)
        return -1;
    return result;
}

int main()
{
    FastIO;

    int v, e;
    cin >> v >> e;

    vector<vector<Edge>> graph(v);
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        graph[u].push_back({ v,w });
        graph[v].push_back({ u,w });
    }

    int m, x;
    cin >> m >> x;

    vector<int> mac(m);
    for (int i = 0; i < m; i++)
    {
        cin >> mac[i];
        mac[i]--;
    }

    int s, y;
    cin >> s >> y;

    vector<int> star(s);
    for (int i = 0; i < s; i++)
    {
        cin >> star[i];
        star[i]--;
    }

    int result = GoodHome(x, y, mac, star, graph);
    cout << result << '\n';
}
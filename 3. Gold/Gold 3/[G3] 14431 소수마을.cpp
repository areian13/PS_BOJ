#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int x, y;

    static double Dist(const Pos& a, const Pos& b)
    {
        int dx = a.x - b.x;
        int dy = a.y - b.y;

        return sqrt(dx * dx + dy * dy);
    }
};

struct Edge
{
    int v, w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

int MinDist(int s, int t, vector<vector<Edge>>& graph)
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

    if (dist[n - 1] == INT_MAX)
        return -1;
    return dist[n - 1];
}

int main()
{
    FastIO;

    vector<bool> isPrime(10'000, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < 10'000; i++)
    {
        if (!isPrime[i])
            continue;
        for (int j = i * 2; j < 10'000; j += i)
            isPrime[j] = false;
    }

    Pos a, b;
    cin >> a.x >> a.y >> b.x >> b.y;

    int n;
    cin >> n;

    vector<Pos> pos(n + 2);
    pos[0] = a;
    for (int i = 1; i <= n; i++)
        cin >> pos[i].x >> pos[i].y;
    pos[n + 1] = b;
    n += 2;

    vector<vector<Edge>> graph(n);
    for (int u = 0; u < n - 1; u++)
    {
        for (int v = u + 1; v < n; v++)
        {
            int w = Pos::Dist(pos[u], pos[v]);

            if (!isPrime[w])
                continue;

            graph[u].push_back({ v,w });
            graph[v].push_back({ u,w });
        }
    }

    int result = MinDist(0, n - 1, graph);
    cout << result << '\n';
}
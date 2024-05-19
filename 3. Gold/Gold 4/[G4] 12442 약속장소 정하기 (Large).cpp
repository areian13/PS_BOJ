#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Human
{
    int x, v;
};

struct Edge
{
    int v;
    long long d;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.d > b.d;
    }
};

void Dijkstra(Human& human, vector<long long>& dist, vector<vector<Edge>>& graph)
{
    dist[human.x] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ human.x,0 });

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        long long d = PQ.top().d;
        PQ.pop();

        if (dist[u] < d)
            continue;

        for (Edge& edge : graph[u])
        {
            int v = edge.v;
            long long nd = d + edge.d * human.v;

            if (dist[v] <= nd)
                continue;

            dist[v] = nd;
            PQ.push({ v,nd });
        }
    }
}

int FastestTime(vector<Human>& humans, vector<vector<Edge>>& graph)
{
    int n = graph.size();
    int p = humans.size();

    vector<vector<long long>> dists(p, vector<long long>(n, LLONG_MAX));
    for (int i = 0; i < p; i++)
        Dijkstra(humans[i], dists[i], graph);

    long long result = LLONG_MAX;
    for (int j = 0; j < n; j++)
    {
        long long time = 0;
        for (int i = 0; i < p; i++)
        {
            if (dists[i][j] == LLONG_MAX)
            {
                time = LLONG_MAX;
                break;
            }

            time = max(time, dists[i][j]);
        }
        result = min(result, time);
    }
    return result;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        int n, p, m;
        cin >> n >> p >> m;

        vector<Human> humans(p);
        for (int i = 0; i < p; i++)
        {
            int x, v;
            cin >> x >> v;
            x--;

            humans[i] = { x,v };
        }

        vector<vector<Edge>> graph(n);
        for (int i = 0; i < m; i++)
        {
            int d, l, c;
            cin >> d >> l >> c;
            c--;

            for (int j = 0; j < l - 1; j++)
            {
                int k;
                cin >> k;
                k--;

                graph[c].push_back({ k,d });
                graph[k].push_back({ c,d });
                c = k;
            }

        }

        int result = FastestTime(humans, graph);
        printf("Case #%d: %d\n", t, result);
    }
}
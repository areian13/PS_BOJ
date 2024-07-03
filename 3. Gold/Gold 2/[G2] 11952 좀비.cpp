#include <iostream>
#include <vector>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v;
    long long w, d;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

void BFS(vector<int>& s, vector<int>& dist, vector<vector<int>>& graph)
{
    int k = s.size();
    queue<int> Q;
    for (int i = 0; i < k; i++)
    {
        dist[s[i]] = 0;
        Q.push(s[i]);
    }

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int v : graph[u])
        {
            if (dist[v] != INT_MAX)
                continue;

            dist[v] = dist[u] + 1;
            Q.push(v);
        }
    }
}

long long MinCost(int s, int t, int k, int p, int q,
    vector<int>& zDist, vector<vector<int>>& graph)
{
    int n = graph.size();

    vector<long long> dist(n, LLONG_MAX);
    dist[s] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ s,0,0 });
    
    while (!PQ.empty())
    {
        int u = PQ.top().v;
        long long w = PQ.top().w;
        long long d = PQ.top().d;
        PQ.pop();

        if (dist[u] < w)
            continue;

        for (int v : graph[u])
        {
            if (zDist[v] == 0)
                continue;

            long long nd = d + 1;
            long long nw = w + (zDist[v] > k ? p : q);
            if (dist[v] <= nw)
                continue;

            dist[v] = nw;
            PQ.push({ v,nw,nd });
        }
    }

    return dist[t] - (zDist[t] > k ? p : q);
}

int main()
{
    FastIO;

    int n, m, k, s, p, q;
    cin >> n >> m >> k >> s >> p >> q;

    vector<int> z(k);
    for (int i = 0; i < k; i++)
    {
        cin >> z[i];
        z[i]--;
    }

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> zDist(n, INT_MAX);
    BFS(z, zDist, graph);

    long long result = MinCost(0, n - 1, s, p, q, zDist, graph);
    cout << result << '\n';
}
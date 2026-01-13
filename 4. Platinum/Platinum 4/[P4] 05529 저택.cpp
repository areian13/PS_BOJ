#include <iostream>
#include <vector>
#include <climits>
#include <array>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const long long INF = LLONG_MAX;

struct Pos
{
    int r, c, i;
};

struct Edge
{
    int v;
    long long w;
};

void MakeGraph(Pos s, Pos t, vector<Pos>& button, vector<vector<Edge>>& graph)
{
    int k = button.size();
    for (int i = 0; i < k; i++)
    {
        graph[i].push_back({ i + k,1 });
        graph[i + k].push_back({ i,1 });

        auto& [r, c, ui] = button[i];
        if (c == s.c) graph[s.i].push_back({ ui,abs(s.r - r) });
        if (c == t.c) graph[ui].push_back({ t.i,abs(t.r - r) });
        if (r == t.r) graph[ui + k].push_back({ t.i,abs(t.c - c) });
    }
    sort(button.begin(), button.end(),
        [](const Pos& a, const Pos& b)
        {
            if (a.c != b.c) return a.c < b.c;
            return a.r < b.r;
        }
    );

    for (int i = 0; i < k - 1; i++)
    {
        auto& [ur, uc, ui] = button[i];
        auto& [vr, vc, vi] = button[i + 1];

        if (uc != vc)
            continue;

        int w = vr - ur;
        graph[ui].push_back({ vi,w });
        graph[vi].push_back({ ui,w });
    }
    sort(button.begin(), button.end(),
        [](const Pos& a, const Pos& b)
        {
            if (a.r != b.r) return a.r < b.r;
            return a.c < b.c;
        }
    );
    for (int i = 0; i < k - 1; i++)
    {
        auto& [ur, uc, ui] = button[i];
        auto& [vr, vc, vi] = button[i + 1];

        if (ur != vr)
            continue;

        int w = vc - uc;
        graph[ui + k].push_back({ vi + k,w });
        graph[vi + k].push_back({ ui + k,w });
    }
}

long long Escape(int s, int t, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    auto comp = [](const Edge& a, const Edge& b) { return a.w > b.w; };
    vector<long long> dist(n, INF);
    priority_queue<Edge, vector<Edge>, decltype(comp)> pq(comp);
    dist[s] = 0;
    pq.push({ s,0 });

    while (!pq.empty())
    {
        auto [u, d] = pq.top();
        pq.pop();

        if (dist[u] < d)
            continue;

        for (auto& [v, w] : graph[u])
        {
            long long nw = d + w;
            if (dist[v] <= nw)
                continue;

            dist[v] = nw;
            pq.push({ v,nw });
        }
    }

    return dist[t];
}

int main()
{
    FastIO;

    int m, n, k;
    cin >> m >> n >> k;

    vector<Pos> button(k);
    for (int i = 0; i < k; i++)
    {
        cin >> button[i].c >> button[i].r;
        button[i].i = i;
    }

    vector<vector<Edge>> graph(k * 2 + 2);
    int s = k * 2, t = s + 1;
    MakeGraph({ 1,1,s }, { n,m,t }, button, graph);

    long long result = Escape(s, t, graph);
    if (result == INF)
        cout << -1 << '\n';
    else
        cout << result << '\n';
}
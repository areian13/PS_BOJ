#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 52

int ctoi(char c)
{
    if ('A' <= c && c <= 'Z')
        return c - 'A';
    return c - 'a' + 26;
}

int MaxFlow(int s, int t, array<array<int, MAX>, MAX>& c, array<vector<int>, MAX>& graph)
{
    array<array<int, MAX>, MAX> f = { 0, };

    int result = 0;
    while (true)
    {
        array<int, MAX> p;
        fill(p.begin(), p.end(), -1);

        queue<int> Q;
        Q.push(s);
        while (!Q.empty() && p[t] == -1)
        {
            int u = Q.front();
            Q.pop();

            for (int v : graph[u])
            {
                if (f[u][v]  >= c[u][v] || p[u] != -1)
                    continue;

                p[u] = v;
                Q.push(u);

                if (u == t)
                    break;
            }
        }

        if (p[t] == -1)
            break;

        int flow = INT_MAX;
        for (int i = t; i != s; i = p[i])
            flow = min(flow, c[p[i]][i] - f[p[i]][i]);
        for (int i = t; i != s; i = p[i])
        {
            f[p[i]][i] += flow;
            f[i][p[i]] -= flow;
        }
        result += flow;
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    array<vector<int>, MAX> graph;
    array<array<int, MAX>, MAX> c = { 0, };
    for (int i = 0; i < n; i++)
    {
        char u, v;
        int w;
        cin >> u >> v >> w;

        u = ctoi(u);
        v = ctoi(v);

        c[u][v] += w;
        c[v][u] += w;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int s = ctoi('A');
    int t = ctoi('Z');
    int result = MaxFlow(s, t, c, graph);
    cout << result << '\n';
}
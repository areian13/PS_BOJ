#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

struct MF
{
    int n;
    vector<vector<int>> graph, capacity, flow;
    MF(int n) : n(n)
    {
        graph.resize(n);
        capacity.resize(n, vector<int>(n, 0));
        flow.resize(n, vector<int>(n, 0));
    }

    int Spare(int u, int v)
    {
        if (capacity[u][v] == INF && flow[u][v] != INF)
            return INF;
        return capacity[u][v] - flow[u][v];
    }
    void AddFlow(int u, int v, int f)
    {
        flow[u][v] += f;
        flow[v][u] -= f;
    }

    int GetMF(int s, int t)
    {
        int result = 0;
        while (true)
        {
            vector<int> level(n, -1);
            if (!CanGo(s, t, level))
                break;

            vector<int> work(n, 0);
            while (true)
            {
                int flow = GetFlow(s, t, INF, work, level);
                if (flow == 0)
                    break;
                result += flow;
            }
        }
        return result;
    }
    bool CanGo(int s, int t, vector<int>& level)
    {
        level[s] = 0;
        queue<int> Q;
        Q.push(s);

        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();

            for (int v : graph[u])
            {
                if (Spare(u, v) <= 0 || level[v] != -1)
                    continue;

                level[v] = level[u] + 1;
                Q.push(v);
            }
        }
        return level[t] != -1;
    }
    int GetFlow(int u, int t, int flow, vector<int>& work, vector<int>& level)
    {
        if (u == t)
            return flow;

        for (int& i = work[u]; i < graph[u].size(); i++)
        {
            int v = graph[u][i];

            if (Spare(u, v) <= 0 || level[v] != level[u] + 1)
                continue;

            int tFlow = GetFlow(v, t, min(flow, Spare(u, v)), work, level);
            if (tFlow > 0)
            {
                AddFlow(u, v, tFlow);
                return tFlow;
            }
        }
        return 0;
    }

    void AddEdge(int u, int v, int c)
    {
        capacity[u][v] = c;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    void ChangeFlow(int s, int t)
    {
        vector<int> parent(n, -1);
        queue<int> q;
        q.push(s);

        while (!q.empty() && parent[t] == -1)
        {
            int u = q.front();
            q.pop();

            if (u < s)
                continue;

            for (int v : graph[u])
            {
                if ((u == s && v < t) || Spare(u, v) <= 0 || parent[v] != -1)
                    continue;

                parent[v] = u;
                q.push(v);
            }
        }

        if (parent[t] == -1)
            return;

        flow[s][t] = 0;
        for (int i = t; i != s; i = parent[i])
            flow[parent[i]][i]++, flow[i][parent[i]]--;
    }
};

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    MF mf(n + m + 2);
    int s = n + m, t = s + 1;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        int u = i;
        mf.AddEdge(s, u, a);

        for (int j = 0; j < m; j++)
        {
            int v = j + n;
            mf.AddEdge(u, v, 1);
        }
    }

    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        sum += a;

        int v = i + n;
        mf.AddEdge(v, t, a);
    }

    if (mf.GetMF(s, t) != sum)
        cout << -1 << '\n';
    else
    {
        for (int u = 0; u < n; u++)
        {
            for (int v = n; v < n + m; v++)
            {
                if (mf.flow[u][v] == 0)
                    continue;
                mf.ChangeFlow(u, v);
            }
        }

        for (int u = 0; u < n; u++)
        {
            for (int v = n; v < n + m; v++)
                cout << mf.flow[u][v];
            cout << '\n';
        }
    }
}
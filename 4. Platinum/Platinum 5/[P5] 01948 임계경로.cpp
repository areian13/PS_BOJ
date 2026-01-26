#include <iostream>
#include <vector>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v, w;
};

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    vector<int> in(n, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        in[v]++;
        graph[u].push_back({ v,w });
    }

    int s, t;
    cin >> s >> t;
    s--, t--;

    vector<pair<int, vector<int>>> time(n);
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto& [v, w] : graph[u])
        {
            int nt = time[u].first + w;
            if (nt > time[v].first)
                time[v] = { nt,{u} };
            else if (nt == time[v].first)
                time[v].second.push_back(u);

            if (--in[v] == 0)
                q.push(v);
        }
    }

    int cnt = 0;
    vector<bool> counted(n, false);
    q.push(t);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (counted[u])
            continue;

        for (int v : time[u].second)
        {
            cnt++;
            q.push(v);
        }

        counted[u] = true;
    }

    cout << time[t].first << '\n';
    cout << cnt << '\n';
}
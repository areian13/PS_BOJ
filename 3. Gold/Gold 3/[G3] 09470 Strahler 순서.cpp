#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int k, m, p;
        cin >> k >> m >> p;

        vector<vector<int>> graph(m);
        vector<int> indegree(m, 0);
        for (int i = 0; i < p; i++)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;

            graph[u].push_back(v);
            indegree[v]++;
        }

        vector<int> dist(m, -1);
        queue<int> Q;
        for (int i = 0; i < m; i++)
        {
            if (indegree[i] == 0)
            {
                dist[i] = 1;
                Q.push(i);
            }
        }

        vector<pair<int, int>> cnt(m, { 0,0 });
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();

            for (int v : graph[u])
            {
                indegree[v]--;
                if (cnt[v].first < dist[u])
                {
                    cnt[v].first = dist[u];
                    cnt[v].second = 0;
                }
                cnt[v].second += (dist[u] == cnt[v].first);

                if (indegree[v] == 0)
                {
                    dist[v] = cnt[v].first + (cnt[v].second >= 2);
                    Q.push(v);
                }
            }
        }

        int result = *max_element(dist.begin(), dist.end());
        cout << k << ' ' << result << '\n';
    }
}
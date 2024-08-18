#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> dist(n, -1);
        dist[i] = 0;

        queue<int> Q;
        Q.push(i);

        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();

            for (int v : graph[u])
            {
                if (dist[v] != -1)
                    continue;

                dist[v] = dist[u] + 1;
                cnt[i] += dist[v];
                Q.push(v);
            }
        }
    }

    int result = min_element(cnt.begin(), cnt.end()) - cnt.begin() + 1;
    cout << result << '\n';
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int t, u, v;

    friend bool operator>(const Edge& a, const Edge& b)
    {
        return a.t < b.t;
    }
};

int FirstInfect(vector<int>& infect, vector<bool>& isInfected, vector<Edge>& edges)
{
    int n = isInfected.size();
    int k = infect.size();

    sort(edges.begin(), edges.end(), greater<Edge>());

    vector<vector<Edge>> graph(n);
    for (Edge& edge : edges)
        graph[edge.u].push_back(edge);

    int result = -1;
    for (Edge& edge : edges)
    {
        if (!isInfected[edge.u])
            continue;

        int cnt = 1;
        vector<bool> isCounted(n, false);
        isCounted[edge.u] = true;

        queue<Edge> Q;
        Q.push({ edge.t - 1,-1,edge.u });

        while (!Q.empty())
        {
            int t = Q.front().t;
            int u = Q.front().v;
            Q.pop();

            for (Edge& edge : graph[u])
            {
                if (edge.t <= t)
                    continue;

                cnt += isInfected[edge.v] * !isCounted[edge.v];
                isCounted[edge.v] = true;
                Q.push(edge);
            }


        }

        if (cnt == k)
            return edge.u;
    }
    return -1;
}

int main()
{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> infect(k);
    vector<bool> isInfected(n, false);
    for (int i = 0; i < k; i++)
    {
        cin >> infect[i];
        infect[i]--;

        isInfected[infect[i]] = true;
    }

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        int t, u, v;
        cin >> t >> u >> v;
        u--, v--;

        edges[i] = { t,u,v };
    }

    int result = FirstInfect(infect, isInfected, edges);
    cout << result + 1 << '\n';
}
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct SCC
{
    vector<vector<int>> groups;
    vector<int> nthGroup;
    int g = 0;

    SCC(vector<vector<int>>& graph)
    {
        int n = graph.size();
        nthGroup.resize(n);
        vector<int> depth(n, -1);
        vector<bool> finish(n, false);
        stack<int> stk;
        int d = 0;
        for (int u = 0; u < n; u++)
        {
            if (depth[u] == -1)
                DFS(u, d, depth, finish, stk, graph);
        }
    }

    int DFS(int u, int& d, vector<int>& depth, vector<bool>& finish,
        stack<int>& stk, vector<vector<int>>& graph)
    {
        depth[u] = d++;
        stk.push(u);

        int p = depth[u];
        for (int v : graph[u])
        {
            if (depth[v] == -1)
                p = min(p, DFS(v, d, depth, finish, stk, graph));
            else if (!finish[v])
                p = min(p, depth[v]);
        }

        if (p == depth[u])
        {
            vector<int> group;
            while (true)
            {
                int t = stk.top();
                stk.pop();

                group.push_back(t);
                nthGroup[t] = g;
                finish[t] = true;

                if (t == u)
                    break;
            }
            groups.push_back(group);
            g++;
        }
        return p;
    }
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char v;
            cin >> v;
            if (v == 'Y')
                graph[i].push_back(j);
        }
    }

    SCC scc(graph);
    vector<int> ind(scc.g, 0);
    vector<vector<int>> c2(scc.g);
    for (int u = 0; u < n; u++)
    {
        c2[scc.nthGroup[u]].push_back(c[u]);
        for (int v : graph[u])
            ind[scc.nthGroup[v]] += (scc.nthGroup[u] != scc.nthGroup[v]);
    }

    vector<int> unuses;
    int sum = 0, cnt = 0;
    for (int i = 0; i < scc.g; i++)
    {
        sort(c2[i].begin(), c2[i].end());
        for (int j = 0; j < c2[i].size(); j++)
        {
            if (j == 0 && ind[i] == 0)
                sum += c2[i][j], cnt++;
            else
                unuses.push_back(c2[i][j]);
        }
    }

    sort(unuses.begin(), unuses.end());
    for (int unuse : unuses)
    {
        if (sum <= unuse * cnt)
            break;
        sum += unuse, cnt++;
    }

    printf("%.9llf\n", 1.l * sum / cnt);
}
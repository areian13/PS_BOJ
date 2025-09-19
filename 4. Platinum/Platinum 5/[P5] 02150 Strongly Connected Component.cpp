#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

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

    int v, e;
    cin >> v >> e;

    vector<vector<int>> graph(v);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        graph[a].push_back(b);
    }

    SCC scc(graph);
    for (auto& group : scc.groups)
        sort(group.begin(), group.end());
    sort(scc.groups.begin(), scc.groups.end());

    cout << scc.g << '\n';
    for (auto& group : scc.groups)
    {
        for (int u : group)
            cout << u + 1 << ' ';
        cout << -1 << '\n';
    }
}
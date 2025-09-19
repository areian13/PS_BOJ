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
        vector<int> nthDFS(n, -1);
        vector<bool> finish(n, false);
        stack<int> stk;
        int d = 0;
        for (int u = 0; u < n; u++)
        {
            if (nthDFS[u] == -1)
                DFS(u, d, nthDFS, finish, stk, graph);
        }
    }

    int DFS(int u, int& d, vector<int>& nthDFS, vector<bool>& finish,
        stack<int>& stk, vector<vector<int>>& graph)
    {
        nthDFS[u] = d++;
        stk.push(u);

        int p = nthDFS[u];
        for (int v : graph[u])
        {
            if (nthDFS[v] == -1)
                p = min(p, DFS(v, d, nthDFS, finish, stk, graph));
            else if (!finish[v])
                p = min(p, nthDFS[v]);
        }

        if (p == nthDFS[u])
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

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        graph[u].push_back(v);
    }

    SCC scc(graph);
    vector<int> ind(scc.g);
    for (int u = 0; u < n; u++)
    {
        for (int v : graph[u])
            ind[scc.nthGroup[v]] += (scc.nthGroup[v] != scc.nthGroup[u]);
    }

    int result = 0;
    for (int i : ind)
        result += (i == 0);
    cout << result << '\n';
}
#include <iostream>
#include <vector>
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

    while (true)
    {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        vector<vector<int>> graph(m * 2);
        for (int i = 0; i < n; i++)
        {
            int l, r;
            cin >> l >> r;

            l = (l < 0 ? -(l + 1) * 2 : l * 2 - 1);
            r = (r < 0 ? -(r + 1) * 2 : r * 2 - 1);

            graph[l % 2 == 0 ? l + 1 : l - 1].push_back(r);
            graph[r % 2 == 0 ? r + 1 : r - 1].push_back(l);
        }

        SCC scc(graph);
        bool result = true;
        for (int i = 0; i < m; i++)
            result &= (scc.nthGroup[i * 2] != scc.nthGroup[i * 2 + 1]);
        cout << result << '\n';
    }
}
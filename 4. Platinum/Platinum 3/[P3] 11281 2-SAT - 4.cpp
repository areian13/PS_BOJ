#include <iostream>
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

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n * 2);
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;

        l = (l < 0 ? -(l + 1) * 2 : l * 2 - 1);
        r = (r < 0 ? -(r + 1) * 2 : r * 2 - 1);

        graph[l & 1 ? l - 1 : l + 1].push_back(r);
        graph[r & 1 ? r - 1 : r + 1].push_back(l);
    }

    SCC scc(graph);
    bool result = true;
    for (int i = 0; i < n; i++)
        result &= (scc.nthGroup[i * 2] != scc.nthGroup[i * 2 + 1]);
    cout << result << '\n';

    if (result)
    {
        vector<int> state(n, -1);
        vector<pair<int, int>> p(n * 2);
        for (int i = 0; i < n * 2; i++)
            p[i] = { scc.nthGroup[i], i };
        sort(p.begin(), p.end());

        for (int i = n * 2 - 1; i >= 0; i--)
        {
            int idx = p[i].second;
            if (state[idx / 2] == -1)
                state[idx / 2] = ~idx & 1;
        }

        for (int i = 0; i < n; i++)
            cout << state[i] << ' ';
        cout << '\n';
    }
}
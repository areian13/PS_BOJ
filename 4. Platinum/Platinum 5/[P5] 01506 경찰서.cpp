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

            if (v == '1')
                graph[i].push_back(j);
        }
    }

    SCC scc(graph);
    int result = 0;
    for (auto& group : scc.groups)
    {
        int w = 1'000'000;
        for (int u : group)
            w = min(w, c[u]);
        result += w;
    }
    cout << result << '\n';
}
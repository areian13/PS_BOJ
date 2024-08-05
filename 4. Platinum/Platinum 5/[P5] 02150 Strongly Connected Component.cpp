#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int DFS(int u, int& cnt, vector<int>& nthDFS, vector<bool>& isFinished,
    stack<int>& S, vector<vector<int>>& SCC, vector<vector<int>>& graph)
{
    nthDFS[u] = cnt++;
    S.push(u);

    int result = nthDFS[u];
    for (int v : graph[u])
    {
        if (nthDFS[v] == -1)
            result = min(result, DFS(v, cnt, nthDFS, isFinished, S, SCC, graph));
        else if (!isFinished[v])
            result = min(result, nthDFS[v]);
    }

    if (result == nthDFS[u])
    {
        vector<int> curSCC;

        while (true)
        {
            int top = S.top();
            S.pop();

            curSCC.push_back(top);
            isFinished[top] = true;

            if (top == u)
                break;
        }

        SCC.push_back(curSCC);
    }

    return result;
}

void MakeSCC(vector<vector<int>>& scc, vector<vector<int>>& graph)
{
    int v = graph.size();

    vector<int> nthDFS(v, -1);
    vector<bool> isFinished(v, false);
    stack<int> S;
    int cnt;

    for (int i = 0; i < v; i++)
    {
        if (nthDFS[i] == -1)
            DFS(i, cnt, nthDFS, isFinished, S, scc, graph);
    }
}

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

    vector<vector<int>> result;
    MakeSCC(result, graph);
    
    int k = result.size();
    for (int i = 0; i < k; i++)
        sort(result[i].begin(), result[i].end());
    sort(result.begin(), result.end());

    cout << k << '\n';
    for (int i = 0; i < k; i++)
    {
        for (int u : result[i])
            cout << u + 1 << ' ';
        cout << -1 << '\n';
    }
}
#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void DFS(int u, int p, int& k, vector<bool>& isVisited, vector<vector<int>>& graph)
{
    isVisited[u] = true;
    k++;

    for (int v : graph[u])
    {
        if (isVisited[v])
            continue;

        DFS(v, u, k, isVisited, graph);
    }
}

long long DividedCase(vector<vector<int>>& graph)
{
    int n = graph.size();

    vector<int> s;
    for (int i = 0; i < n; i++)
    {
        if (graph[i].size() == 3)
            s.push_back(i);
    }

    vector<bool> isVisited(n, false);
    isVisited[s[0]] = isVisited[s[1]] = true;

    vector<int> cnt;
    for (int v : graph[s[0]])
    {
        if (v == s[1])
            continue;

        int k = 1;
        DFS(v, s[0], k, isVisited, graph);
        cnt.push_back(k);
    }

    long long result = 0;
    for (int x : cnt)
        result += (long long)x * (x - 1) / 2;
    return result;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        int n;
        cin >> n;

        vector<vector<int>> graph(n);
        for (int i = 0; i < n + 1; i++)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        long long result = DividedCase(graph);
        cout << "Case #" << t << endl;
        cout << result << endl;
    }
}
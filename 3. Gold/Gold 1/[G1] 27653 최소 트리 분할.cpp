#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long DFS(int u, int p, vector<vector<int>>& graph, vector<int>& a)
{
    long long result = 0;
    for (int v : graph[u])
    {
        if (v == p)
            continue;
        result += DFS(v, u, graph, a) + max(a[v] - a[u], 0);
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    long long result = DFS(0, -1, graph, a) + a[0];
    cout << result << '\n';
}
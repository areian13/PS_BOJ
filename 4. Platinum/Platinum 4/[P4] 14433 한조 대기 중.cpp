#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CanMatch(int u, vector<bool>& isVisited,
    vector<int>& a, vector<int>& b, vector<vector<int>>& graph)
{
    isVisited[u] = true;

    for (int v : graph[u])
    {
        if(b[v] == -1 ||
            !isVisited[b[v]] && CanMatch(b[v], isVisited, a, b, graph))
        {
            a[u] = v;
            b[v] = u;
            return true;
        }
    }
    return false;
}

int MaxTroll(int n, int m, vector<vector<int>>& graph)
{
    vector<int> a(n, -1), b(m, -1);
    int result = 0;
    for (int u = 0; u < n; u++)
    {
        if (a[u] != -1)
            continue;

        vector<bool> isVisited(n, false);
        result += CanMatch(u, isVisited, a, b, graph);
    }
    return result;
}

int main()
{
    FastIO;

    int n, m;
    vector<int> k(2);
    cin >> n >> m >> k[0] >> k[1];

    vector<vector<vector<int>>> graph(2, vector<vector<int>>(n));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < k[i]; j++)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;

            graph[i][u].push_back(v);
        }
    }

    int a = MaxTroll(n, m, graph[0]);
    int b = MaxTroll(n, m, graph[1]);
    string result = (a < b ? "네 다음 힐딱이" : "그만 알아보자");
    cout << result << '\n';
}
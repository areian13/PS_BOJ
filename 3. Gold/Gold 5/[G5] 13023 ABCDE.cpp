#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool BT(int cur, int d, vector<bool>& isVisited, vector<vector<int>>& graph)
{
    if (d == 5)
        return true;

    for (int nxt : graph[cur])
    {
        if (isVisited[nxt])
            continue;

        isVisited[nxt] = true;
        if (BT(nxt, d + 1, isVisited, graph))
            return true;
        isVisited[nxt] = false;
    }

    return false;
}

bool IsTakenABCDE(vector<vector<int>>& graph)
{
    int n = graph.size();

    vector<bool> isVisited(n, false);
    for (int i = 0; i < n; i++)
    {
        isVisited[i] = true;
        if (BT(i, 1, isVisited, graph))
            return true;
        isVisited[i] = false;
    }
    return false;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bool result = IsTakenABCDE(graph);
    cout << result << '\n';
}
#include <iostream>
#include <vector>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v, d;
};

int DFS(int cur, int k, int pre, vector<vector<Edge>>& graph)
{
    int result = 1;
    for (Edge& edge : graph[cur])
    {
        if (edge.v == pre)
            continue;
        if (edge.d < k)
            continue;

        result += DFS(edge.v, k, cur, graph);
    }
    return result;
}

int main()
{
    FastIO;

    int n, q;
    cin >> n >> q;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < n - 1; i++)
    {
        int p, q, r;
        cin >> p >> q >> r;
        p--, q--;

        graph[p].push_back({ q,r });
        graph[q].push_back({ p,r });
    }

    while (q--)
    {
        int k, v;
        cin >> k >> v;
        v--;

        int result = DFS(v, k, -1, graph) - 1;
        cout << result << '\n';
    }
}
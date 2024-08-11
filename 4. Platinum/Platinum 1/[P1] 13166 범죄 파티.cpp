#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Edge
{
    int v, w;
};

void BFS(vector<bool>& isUsed, vector<int>& level,
    vector<int>& b, vector<vector<Edge>>& graph)
{
    int n = graph.size();

    queue<int> Q;
    for (int u = 0; u < n; u++)
    {
        if (isUsed[u])
            continue;

        level[u] = 0;
        Q.push(u);
    }

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (Edge& edge : graph[u])
        {
            int v = edge.v;

            if (b[v] == -1 || level[b[v]] != INT_MAX)
                continue;

            level[b[v]] = level[u] + 1;
            Q.push(b[v]);
        }
    }
}

bool CanMatch(int u, int k, vector<bool>& isUsed, vector<int>& level,
    vector<int>& a, vector<int>& b, vector<vector<Edge>>& graph)
{
    for (Edge& edge : graph[u])
    {
        if (k < edge.w)
            continue;
        
        int v = edge.v;

        if (b[v] != -1)
        {
            if (level[b[v]] != level[u] + 1)
                continue;
            if (!CanMatch(b[v], k, isUsed, level, a, b, graph))
                continue;
        }

        a[u] = v;
        b[v] = u;
        return isUsed[u] = true;
    }
    return false;
}

int MaxMatch(int n, int m, int k, vector<vector<Edge>>& graph)
{
    vector<int> a(n, -1), b(m, -1);
    vector<bool> isUsed(n, false);
    int result = 0;
    while (true)
    {
        vector<int> level(n, INT_MAX);
        BFS(isUsed, level, b, graph);

        int flow = 0;
        for (int u = 0; u < n; u++)
            flow += (!isUsed[u] && CanMatch(u, k, isUsed, level, a, b, graph));

        if (flow == 0)
            break;

        result += flow;
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<Edge>> graph(n);
    vector<int> ks(n * 2);
    for (int u = 0; u < n; u++)
    {
        int a, b;
        cin >> a >> ks[u * 2] >> b >> ks[u * 2 + 1];
        a--, b--;

        graph[u].push_back({ a,ks[u * 2] });
        graph[u].push_back({ b,ks[u * 2  + 1] });
    }
    sort(ks.begin(), ks.end());

    int start = 0, end = n * 2 - 1;
    int result = INT_MAX;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int k = ks[mid];

        int match = MaxMatch(n, n * 2, k, graph);
        if (match < n)
            start = mid + 1;
        else
        {
            result = min(result, k);
            end = mid - 1;
        }
    }

    if (result == INT_MAX)
        result = -1;
    cout << result << '\n';
}
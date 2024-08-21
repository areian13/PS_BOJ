#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

enum Type
{
    D, B
};

void DBFS(Type type, int start, vector<vector<int>>& graph)
{
    int n = graph.size();
    for (int i = 0; i < n; i++)
    {
        if (type == D)
            sort(graph[i].begin(), graph[i].end(), greater<int>());
        else if (type == B)
            sort(graph[i].begin(), graph[i].end(), less<int>());
    }

    vector<bool> isVisited(n, false);

    deque<int> DQ;
    DQ.push_back(start - 1);

    while (!DQ.empty())
    {
        int u = (type == D ? DQ.back() : DQ.front());
        type == D ? DQ.pop_back() : DQ.pop_front();

        if (isVisited[u])
            continue;

        cout << u + 1 << ' ';
        isVisited[u] = true;

        for (int v : graph[u])
        {
            if (isVisited[v])
                continue;

            DQ.push_back(v);
        }
    }
    cout << '\n';
}

void DFS(int start, vector<vector<int>>& graph)
{
    DBFS(D, start, graph);
}
void BFS(int start, vector<vector<int>>& graph)
{
    DBFS(B, start, graph);
}

int main()
{
    FastIO;

    int n, m, v;
    cin >> n >> m >> v;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    DFS(v, graph);
    BFS(v, graph);
}
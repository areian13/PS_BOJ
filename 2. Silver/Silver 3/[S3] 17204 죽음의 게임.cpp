#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Bosung(int k, vector<int>& graph)
{
    int n = graph.size();
    vector<bool> visited(n, false);

    int result = 0;
    int u = 0;
    while (true)
    {
        visited[u] = true;
        result++;

        int v = graph[u];
        if (v == k) return result;
        if (visited[v]) return -1;

        u = v;
    }
    return -1;
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<int> graph(n);
    for (int i = 0; i < n; i++)
        cin >> graph[i];

    int result = Bosung(k, graph);
    cout << result << '\n';
}
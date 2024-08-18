#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 10'000

struct Edge
{
    int v, d;
};

int main()
{
    FastIO;

    int n, d;
    cin >> n >> d;

    vector<vector<Edge>> graph(MAX + 1);
    for (int i = 0; i < n; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;

        graph[s].push_back({ e,w });
    }

    vector<int> dist(MAX + 1, INT_MAX);
    for (int i = 0; i <= MAX; i++)
    {
        dist[i] = min(dist[i], (i == 0 ? 0 : dist[i - 1] + 1));

        for (Edge& edge : graph[i])
            dist[edge.v] = min(dist[edge.v], dist[i] + edge.d);
    }

    int result = dist[d];
    cout << result << '\n';
}
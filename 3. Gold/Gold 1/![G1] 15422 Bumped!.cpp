#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define INF 1'000'000'000

struct Route
{
    int v, w;
    bool isUsedAir;
};

int main()
{
    FastIO;

    int n, m, f, s, t;
    cin >> n >> m >> f >> s >> t;

    vector<vector<Route>> node(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        node[u].push_back({ v,w });
        node[v].push_back({ u,w });
    }

}
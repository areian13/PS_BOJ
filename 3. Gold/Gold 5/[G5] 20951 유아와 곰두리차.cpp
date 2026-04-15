#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MOD = 1'000'000'007;
const int LEN = 7;

int Path(int d, int u, vector<vector<int>>& dp,
    vector<vector<int>>& graph)
{
    int& result = dp[d][u];
    if (result != -1) return result;
    if (d == LEN) return result = 1;

    result = 0;
    for (int v : graph[u])
        result = (result + Path(d + 1, v, dp, graph)) % MOD;
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<vector<int>> dp(LEN + 1, vector<int>(n, -1));
    int result = 0;
    for (int i = 0; i < n; i++)
        result = (result + Path(0, i, dp, graph)) % MOD;
    cout << result << '\n';
}
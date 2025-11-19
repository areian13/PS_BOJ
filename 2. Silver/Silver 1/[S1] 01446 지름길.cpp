#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MAX = 10'000;
const int INF = INT_MAX;

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

        graph[e].push_back({ s,w });
    }

    vector<int> dp(MAX + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= d; i++)
    {
        dp[i] = min(dp[i], dp[i - 1] + 1);
        for (auto& [v, d] : graph[i])
            dp[i] = min(dp[i], dp[v] + d);
    }
    cout << dp[d] << '\n';
}
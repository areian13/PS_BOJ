#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MOD = 1'000'000'007;

vector<vector<int>> graph = {
    {1, 2},
    {0, 2, 7},
    {0, 1, 7, 4},
    {7, 4, 6},
    {2, 7, 3, 5},
    {4, 6},
    {5, 3},
    {1, 2, 4, 3}
};

int Walk(int u, int d, vector<vector<int>>& dp)
{
    if (d == 0) return u == 0;
    if (dp[u][d] != -1) return dp[u][d];

    dp[u][d] = 0;
    for (int v : graph[u])
    {
        dp[u][d] += Walk(v, d - 1, dp);
        dp[u][d] %= MOD;
    }
    return dp[u][d];
}

int main()
{
    FastIO;

    int d;
    cin >> d;

    vector<vector<int>> dp(8, vector<int>(d + 1, -1));
    int result = Walk(0, d, dp);
    cout << result << '\n';
}
#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = 1e+9;

int Energy(int d, bool v, int k, vector<vector<int>>& e, vector<vector<int>>& dp)
{
    int n = e.size();
    if (d > n) return INF;
    if (d == n) return 0;
    if (dp[d][v] != -1) return dp[d][v];

    dp[d][v] = INF;
    if (!v)
        dp[d][v] = Energy(d + 3, true, k, e, dp) + k;
    for (int i = 0; i < 2; i++)
        dp[d][v] = min(dp[d][v], Energy(d + 1 + i, v, k, e, dp) + e[d][i]);
    return dp[d][v];
}

int main()
{
    FastIO;

    int n;
    cin >> n;
    n--;

    vector<vector<int>> e(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> e[i][0] >> e[i][1];

    int k;
    cin >> k;

    vector<vector<int>> dp(n, vector<int>(2, -1));
    int result = Energy(0, false, k, e, dp);
    cout << result << '\n';
}
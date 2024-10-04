#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int DP(int x, vector<int>& dp)
{
    if (dp[x] != INT_MAX)
        return dp[x];
    if (x == 1)
        return dp[x] = 0;

    if (x % 3 == 0)
        dp[x] = min(dp[x], DP(x / 3, dp) + 1);
    if (x % 2 == 0)
        dp[x] = min(dp[x], DP(x / 2, dp) + 1);
    dp[x] = min(dp[x], DP(x - 1, dp) + 1);
    return dp[x];
}

int main()
{
    FastIO;

    int x;
    cin >> x;

    vector<int> dp(x + 1, INT_MAX);
    int result = DP(x, dp);
    cout << result << '\n';
}
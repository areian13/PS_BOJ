#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CountMinCoins(int k, vector<int>& coins, vector<int>& dp)
{
    if (k < 0)
        return INT_MAX;
    if (dp[k] != -1)
        return dp[k];
    if (k == 0)
        return dp[0] = 0;

    int result = INT_MAX;
    for (int coin : coins)
        result = min(result, CountMinCoins(k - coin, coins, dp));

    if (result == INT_MAX)
        return dp[k] = INT_MAX;
    return dp[k] = result + 1;
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    vector<int> dp(k + 1, -1);
    int result = CountMinCoins(k, coins, dp);
    if (result == INT_MAX)
        cout << -1 << '\n';
    else
        cout << result << '\n';
}
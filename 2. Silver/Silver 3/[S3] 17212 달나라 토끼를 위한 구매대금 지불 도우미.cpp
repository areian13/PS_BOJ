#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

int MinCoins(int n, vector<int>& dp, vector<int>& coins)
{
    if (n < 0)
        return INF;
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    int result = INF;
    for (int coin : coins)
        result = min(result, MinCoins(n - coin, dp, coins));
    result++;

    return dp[n] = result;
}

int main()
{
    FastIO;

    vector<int> coins = { 7,5,2,1 };

    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);
    int result = MinCoins(n, dp, coins);
    cout << result << '\n';
}
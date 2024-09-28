#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int DP(int x, vector<int>& dp)
{
    if (x == 1)
        return 0;
    if (dp[x] != -1)
        return dp[x];

    int result = INT_MAX;
    if (x % 3 == 0)
        result = min(result, DP(x / 3, dp) + 1);
    if (x % 2 == 0)
        result = min(result, DP(x / 2, dp) + 1);
    result = min(result, DP(x - 1, dp) + 1);
    return dp[x] = result;
}

int main()
{
    FastIO;

    int x;
    cin >> x;

    vector<int> dp(x + 1, -1);
    int result = DP(x, dp);
    cout << result << '\n';
}
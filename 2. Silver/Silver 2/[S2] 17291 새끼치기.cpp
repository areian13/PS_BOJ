#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);
    dp[1] = 1, dp[2] = 2, dp[3] = 4, dp[4] = 7;
    for (int i = 5; i <= n; i++)
        dp[i] = dp[i - 1] * 2 - (~i & 1 ? dp[i - 4] + dp[i - 5] : 0);

    cout << dp[n] << '\n';
}
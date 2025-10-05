#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MOD 1'000'000'007

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
    }

    cout << dp[n][n] << ' ' << n * n << '\n';
}
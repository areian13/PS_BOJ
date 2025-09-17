#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MOD 10'007

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
    }

    cout << dp[n][k] << '\n';
}
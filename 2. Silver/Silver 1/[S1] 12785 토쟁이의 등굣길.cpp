#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MOD = 1'000'007;

int Route(int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m, 1));
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
    }
    return dp[n - 1][m - 1];
}

int main()
{
    FastIO;

    int w, h, x, y;
    cin >> w >> h >> x >> y;

    int result = 1LL * Route(x, y) * Route(w - x + 1, h - y + 1) % MOD;
    cout << result << '\n';
}
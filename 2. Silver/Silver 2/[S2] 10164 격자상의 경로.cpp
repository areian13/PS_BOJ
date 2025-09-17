#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;
    k--;

    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    for (int j = 0; j < m; j++)
        dp[0][j] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }

    int r = k / m, c = k % m;
    int result = dp[r][c] * dp[m - r - 1]
}
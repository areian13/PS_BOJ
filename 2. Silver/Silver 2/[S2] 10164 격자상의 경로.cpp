#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> dp(n, vector<int>(m, 1));
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }


    if (k == 0)
        cout << dp[n - 1][m - 1] << '\n';
    else
    {
        k--;
        int r = k / m, c = k % m;
        int result = dp[r][c] * dp[n - r - 1][m - c - 1];
        cout << result << '\n';
    }
}
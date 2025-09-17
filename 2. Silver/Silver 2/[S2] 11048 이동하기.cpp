#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int c;
            cin >> c;

            dp[i][j] = max({ dp[i - 1][j],dp[i][j - 1],dp[i - 1][j - 1] }) + c;
        }
    }

    cout << dp[n][m] << '\n';
}
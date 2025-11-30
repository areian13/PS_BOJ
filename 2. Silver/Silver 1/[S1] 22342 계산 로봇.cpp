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

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            grid[i][j] = c - '0';
        }
    }

    vector<vector<int>> dp(n, vector<int>(m));
    int result = 0;
    for (int j = 0; j < m - 1; j++)
    {
        for (int i = 0; i < n; i++)
        {
            int a, b, c;
            if (j == 0)
                a = b = c = 0;
            else
            {
                a = (i == 0 ? 0 : dp[i - 1][j - 1]);
                b = dp[i][j - 1];
                c = (i == n - 1 ? 0 : dp[i + 1][j - 1]);
            }
            dp[i][j] = max({ a,b,c }) + grid[i][j];
            result = max(result, dp[i][j]);
        }
    }
    cout << result << '\n';
}
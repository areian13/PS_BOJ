#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        vector<vector<int>> sticker(2, vector<int>(n + 1));
        for (int i = 0; i < 2; i++)
        {
            for (int j = 1; j <= n; j++)
                cin >> sticker[i][j];
        }

        vector<vector<int>> dp(2, vector<int>(2));
        for (int i = 1; i <= n; i++)
        {
            bool idx = i % 2;
            for (int j = 0; j < 2; j++)
                dp[j][idx] = max(dp[j][!idx], dp[!j][!idx] + sticker[j][i]);
        }

        int result = max(dp[0][n % 2], dp[1][n % 2]);
        cout << result << '\n';
    }
}
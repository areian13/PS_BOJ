#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> r(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> r[i][0] >> r[i][1];

    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0] = r[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + abs(r[i - 1][!k] - r[i][!j]) + r[i][j]);
        }
    }

    int result = max(dp[n - 1][0], dp[n - 1][1]);
    cout << result << '\n';
}
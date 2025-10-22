#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> rs(n, vector<int>(2)), dp(n, vector<int>(2, 0));
    for (auto& r : rs)
        cin >> r[0] >> r[1];

    dp[0] = rs[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + abs(rs[i - 1][!k] - rs[i][!j]) + rs[i][j]);
        }
    }

    cout << max(dp[n - 1][0], dp[n - 1][1]) << '\n';
}
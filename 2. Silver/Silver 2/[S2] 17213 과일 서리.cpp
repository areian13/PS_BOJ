#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<long long>> dp(m, vector<long long>(m, 1));
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < i; j++)
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]);
    }

    cout << dp[m - 1][n - 1] << '\n';
}
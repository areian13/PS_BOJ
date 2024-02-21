#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define SIZE 14

int DP(int k, int n, vector<vector<int>>& dp)
{
    if (dp[k][n] != -1)
        return dp[k][n];

    int result = 0;
    for (int i = 1; i <= n; i++)
        result += DP(k - 1, i, dp);
    return dp[k][n] = result;
}

int main()
{
    FastIO;

    vector<vector<int>> dp(SIZE + 1, vector<int>(SIZE + 1, -1));

    for (int i = 0; i <= SIZE; i++)
        dp[0][i] = i;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int k, n;
        cin >> k >> n;

        int result = DP(k, n, dp);
        cout << result << '\n';
    }
}
#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MOD = 1'000'000'000;

int Stair(int d, int k, vector<vector<int>>& dp)
{
    if (d == 1) return 1;
    if (dp[d][k] != -1) return dp[d][k];

    int result = 0;
    if (k < 9) result += Stair(d - 1, k + 1, dp);
    if (k > 0) result += Stair(d - 1, k - 1, dp);
    return dp[d][k] = result % MOD;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> dp(n + 1, vector<int>(10, -1));
    int result = 0;
    for (int i = 1; i <= 9; i++)
        result += Stair(n, i, dp), result %= MOD;
    cout << result << '\n';
}
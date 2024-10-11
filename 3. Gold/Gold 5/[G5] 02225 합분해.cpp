#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MOD 1'000'000'000

int CountSum(int n, int k)
{
    static vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

    if (dp[n][k] != -1)
        return dp[n][k];
    if (k == 1)
        return dp[n][k] = 1;
    if (n == 1)
        return dp[n][k] = k;

    return dp[n][k] = (CountSum(n - 1, k) + CountSum(n, k - 1)) % MOD;
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    int result = CountSum(n, k);
    cout << result << '\n';
}
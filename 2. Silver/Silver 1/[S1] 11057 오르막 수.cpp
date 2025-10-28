#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 1'000
vector<vector<long long>> dp(MAX + 1, vector<long long>(10, -1));
#define MOD 10'007

long long DP(int n, int d)
{
    if (n == 0) return 1;
    if (dp[n][d] != -1) return dp[n][d];

    dp[n][d] = 0;
    for (int i = 0; i <= d; i++)
        dp[n][d] += DP(n - 1, i), dp[n][d] %= MOD;
    return dp[n][d];
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    long long result = DP(n, 9);
    cout << result << '\n';
}
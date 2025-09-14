#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = 100'001;

int MinSqr(int n, vector<int>& dp)
{
    if (n == 0) return dp[0] = 0;
    if (dp[n] != INF) return dp[n];

    for (int i = 1; i * i <= n; i++)
        dp[n] = min(dp[n], MinSqr(n - i * i, dp) + 1);
    return dp[n];
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> dp(n + 1, INF);
    int result = MinSqr(n, dp);
    cout << result << '\n';
}
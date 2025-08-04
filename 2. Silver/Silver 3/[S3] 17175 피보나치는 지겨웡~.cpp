#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MOD 1'000'000'007

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> dp(n + 1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - 2] + 1) % MOD;

    cout << dp[n] << '\n';
}
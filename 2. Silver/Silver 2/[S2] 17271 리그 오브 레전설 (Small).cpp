#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MOD 1'000'000'007;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> dp(n + 1, 1);
    for (int i = m; i <= n; i++)
        dp[i] = (dp[i - 1] + dp[i - m]) % MOD;
    cout << dp[n] << '\n';
}
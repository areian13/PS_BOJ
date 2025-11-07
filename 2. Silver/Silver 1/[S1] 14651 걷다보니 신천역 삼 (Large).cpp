#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MOD = 1'000'000'009;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);
    if (n >= 2) dp[2] = 2;
    for (int i = 3; i <= n; i++)
        dp[i] = 1LL * dp[i - 1] * 3 % MOD;
    cout << dp[n] << '\n';
}
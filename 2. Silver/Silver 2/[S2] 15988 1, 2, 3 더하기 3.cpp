#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 1'000'000
#define MOD 1'000'000'009

int main()
{
    FastIO;

    vector<int> dp(MAX + 1);
    dp[1] = 1, dp[2] = 2, dp[3] = 4;
    for (int i = 4; i <= MAX; i++)
        dp[i] = (1LL * dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        cout << dp[n] << '\n';
    }
}
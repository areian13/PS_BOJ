#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 191'229
#define MOD 1'000'000'007

int main()
{
    FastIO;

    vector<int> dp(MAX + 1);
    dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= MAX; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        cout << dp[n] << '\n';
    }
}
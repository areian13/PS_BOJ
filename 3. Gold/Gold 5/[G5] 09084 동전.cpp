#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        vector<int> coins(n);
        for (int i = 0; i < n; i++)
            cin >> coins[i];

        int m;
        cin >> m;

        vector<int> dp(m + 1, 0);
        dp[0] = 1;
        for (int coin : coins)
        {
            for (int i = coin; i <= m; i++)
                dp[i] += dp[i - coin];
        }
        cout << dp[m] << '\n';
    }
}
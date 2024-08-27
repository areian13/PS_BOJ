#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin>>n;

    vector<vector<int>> dp(n + 1, { 1'000'000'000 ,0 });
    dp[0][0] = 0;

    int c = 1;
    int p = 2;
    while (p <= n)
    {
        for (int i = p; i <= n; i++)
        {
            dp[i][0] = min(dp[i][0], dp[i - p][0] + c);
            dp[i][1] = max(dp[i][1], dp[i - p][1] + c);
        }
        p += c;
        c = p - c;
    }
    cout << dp[n][0] << ' ' << dp[n][1] << '\n';
}
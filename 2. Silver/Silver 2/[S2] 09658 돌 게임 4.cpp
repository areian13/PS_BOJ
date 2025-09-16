#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<bool> dp(n + 1);
    dp[1] = dp[3] = 0, dp[2] = dp[4] = 1;
    for (int i = 5; i <= n; i++)
        dp[i] = !dp[i - 1] || !dp[i - 3] || !dp[i - 4];
    
    cout << (dp[n] ? "SK" : "CY") << '\n';
}
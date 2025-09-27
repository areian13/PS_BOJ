#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> a[i] >> a[i];

    vector<vector<int>> dp(n, vector<int>(2));
    dp[0] = { 0,a[0] };
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = i == 1 ? 0 : max(dp[i - 2][0], dp[i - 2][1]) + a[i];
    }

    int result = max(dp[n - 1][0], dp[n - 1][1]);
    cout << result << '\n';
}
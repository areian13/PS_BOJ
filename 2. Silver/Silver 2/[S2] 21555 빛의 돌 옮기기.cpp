#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vector<vector<long long>> dp(n, vector<long long>(2));
    dp[0] = { a[0],b[0] };
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + k) + a[i];
        dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + k) + b[i];
    }

    long long result = min(dp[n - 1][0], dp[n - 1][1]);
    cout << result << '\n';
}
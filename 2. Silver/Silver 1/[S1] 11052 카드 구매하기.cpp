#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int MaxPrice(int d, vector<int>& p, vector<int>& dp)
{
    if (dp[d] != -1) return dp[d];

    dp[d] = p[d];
    for (int i = 1; i < d; i++)
        dp[d] = max(dp[d], MaxPrice(d - i, p, dp) + p[i]);
    return dp[d];
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    vector<int> dp(n + 1, -1);
    int result = MaxPrice(n, p, dp);
    cout << result << '\n';
}
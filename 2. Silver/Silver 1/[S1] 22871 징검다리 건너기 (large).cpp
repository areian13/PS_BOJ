#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const long long INF = LLONG_MAX;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<long long> dp(n, INF);
    dp[0] = 0;
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < j; i++)
        {
            long long k = 1LL * (j - i) * (1 + abs(a[i] - a[j]));
            dp[j] = min(dp[j], max(dp[i], k));
        }
    }
    cout << dp[n - 1] << '\n';
}
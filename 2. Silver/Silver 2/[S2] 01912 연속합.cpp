#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> dp(n, 0);
    int result = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        dp[i] = max(i == 0 ? 0 : dp[i - 1], 0) + a[i];
        result = max(result, dp[i]);
    }
    cout << result << '\n';
}
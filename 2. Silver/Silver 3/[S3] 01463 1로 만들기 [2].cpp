#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int x;
    cin >> x;

    vector<int> dp(x + 1, INT_MAX);
    dp[1] = 0;
    for (int i = 1; i < x; i++)
    {
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        if (i * 3 <= x)
            dp[i * 3] = min(dp[i * 3], dp[i] + 1);
        if (i * 2 <= x)
            dp[i * 2] = min(dp[i * 2], dp[i] + 1);
    }

    int result = dp[x];
    cout << result << '\n';
}
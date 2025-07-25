#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int d, p;
    cin >> d >> p;

    vector<int> dp(d + 1, INT_MIN);
    dp[0] = INT_MAX;

    while (p--)
    {
        int l, c;
        cin >> l >> c;

        for (int i = d; i >= l; i--)
        {
            if (dp[i - l] == INT_MIN)
                continue;

            dp[i] = max(dp[i], min(dp[i - l], c));
        }
    }

    cout << dp[d] << '\n';
}
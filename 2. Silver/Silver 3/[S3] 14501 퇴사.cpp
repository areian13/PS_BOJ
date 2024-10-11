#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX_T 5

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> t(n), p(n);
    for (int i = 0; i < n; i++)
        cin >> t[i] >> p[i];

    vector<int> dp(n, 0);
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (i + t[i] > n)
            continue;

        int maxValue = 0;
        for (int j = 1; j <= i; j++)
        {
            if (t[i - j] <= j)
                maxValue = max(maxValue, dp[i - j]);
        }
        dp[i] = maxValue + p[i];
        result = max(result, dp[i]);
    }

    cout << result << '\n';
}
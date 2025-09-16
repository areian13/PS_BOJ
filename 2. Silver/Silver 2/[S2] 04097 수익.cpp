#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        vector<int> dp(n + 1, 0);
        int result = -10'001;
        for (int i = 1; i <= n; i++)
        {
            int p;
            cin >> p;

            dp[i] = max(dp[i - 1] + p, p);
            result = max(result, dp[i]);
        }
        cout << result << '\n';
    }
}
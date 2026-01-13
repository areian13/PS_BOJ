#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    long long k;
    cin >> n >> k;

    vector<vector<long long>> dp(n + 1, vector<long long>(1 << 3, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < (1 << 3); j++)
        {
            for (int d = 0; d < 3; d++)
                dp[i][j] += dp[i - 1][j ^ (1 << d)];
        }
    }

    int pre = 0;
    for (int i = n; i >= 1; i--)
    {
        vector<long long> v(3, 0);
        for (int j = 0; j < 3; j++)
            v[j] = dp[i][pre ^ (1 << j)];

        for (int j = 2; j >= 0; j--)
        {
            if (v[j] <= k)
            {
                cout << 3 + j * 2 << ' ';
                k -= v[j];
                cout << k << ' ' << v[j] << '\n';
                pre ^= (1 << j);
                break;
            }
        }
    }
}
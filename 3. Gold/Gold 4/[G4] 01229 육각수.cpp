#include <iostream>
#include <array>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    array<int, 708> hexNum;
    hexNum[0] = 1;
    int idx;
    for (idx = 1; ; idx++)
    {
        hexNum[idx] = 6 * idx + hexNum[idx - 1] - (2 * idx - 1);
        if (hexNum[idx] > n)
            break;
    }
    vector<int> dp(n + 1, n + 1);
    dp[0] = 0;
    for (int i = 0; i < idx; i++)
    {
        for (int j = hexNum[i]; j <= n; j++)
            dp[j] = min(dp[j], dp[j - hexNum[i]] + 1);
    }

    int result = dp[n];
    cout << result << '\n';
}
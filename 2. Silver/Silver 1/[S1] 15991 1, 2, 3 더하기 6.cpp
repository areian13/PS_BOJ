#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MAX = 100'000;
const int MOD = 1'000'000'009;

int Sum123(int n)
{
    static vector<int> dp(MAX + 1, -1);
    dp[1] = 1, dp[2] = 2, dp[3] = 2;
    if (n == 0) return 1;
    if (dp[n] != -1) return dp[n];

    dp[n] = 0;
    for (int k : {3, 2, 1})
    {
        if (k * 2 > n) continue;
        dp[n] += Sum123(n - k * 2);
        dp[n] %= MOD;
    }
    return dp[n];
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        int result = Sum123(n);
        cout << result << '\n';
    }
}
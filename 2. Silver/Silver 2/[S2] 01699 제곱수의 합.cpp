#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = 100'001;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> dp(n + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int sqr = INF;
        for (int j = 1; j * j <= i; j++)
            sqr = min(sqr, dp[i - j * j]);
        dp[i] = sqr + 1;
    }
    cout << dp[n] << '\n';
}
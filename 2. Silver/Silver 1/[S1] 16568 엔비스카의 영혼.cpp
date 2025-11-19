#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

int main()
{
    FastIO;

    int n, a, b;
    cin >> n >> a >> b;

    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int d : {1, a + 1, b + 1})
        {
            if (d > i) continue;
            dp[i] = min(dp[i], dp[i - d] + 1);
        }
    }
    cout << dp[n] << '\n';
}
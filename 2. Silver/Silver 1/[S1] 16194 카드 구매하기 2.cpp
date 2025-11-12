#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= 1; j--)
            dp[i] = min(dp[i], dp[i - j] + p[j]);
    }
    cout << dp[n] << '\n';
}
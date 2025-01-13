#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> s;
    int t = 1;
    while (true)
    {
        int k = t * (t + 1) * (t + 2) / 6;

        if (k > n)
            break;

        s.push_back(k);
        t++;
    }

    vector<int> dp(n + 1, n);
    dp[0] = 0;
    for (int k : s)
    {
        for (int i = k; i <= n; i++)
            dp[i] = min(dp[i], dp[i - k] + 1);
    }
    cout << dp[n] << '\n';
}
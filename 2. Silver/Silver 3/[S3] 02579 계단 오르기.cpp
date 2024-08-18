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

    vector<int> s(n + 2);
    for (int i = 2; i <= n + 1; i++)
        cin >> s[i];

    vector<int> dp(n + 2, 0);
    for (int i = 2; i <= n + 1; i++)
        dp[i] = (i == 2 ? 0 : max(dp[i - 2], dp[i - 3] + s[i - 1])) + s[i];
    cout << dp[n + 1] << '\n';
}
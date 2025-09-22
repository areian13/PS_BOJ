#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> chapters(m);
    for (auto& [d, p] : chapters)
        cin >> d >> p;

    vector<int> dp(n + 1, 0);
    for (auto& [d, p] : chapters)
    {
        for (int i = n; i >= d; i--)
            dp[i] = max(dp[i], dp[i - d] + p);
    }
    cout << dp[n] << '\n';
}
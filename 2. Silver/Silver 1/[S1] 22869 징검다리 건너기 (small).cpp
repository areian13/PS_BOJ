#include <iostream>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CanGo(int d, int k, vector<int>& a, vector<int>& dp)
{
    int n = a.size();
    if (d == n - 1) return true;
    if (dp[d] != -1) return dp[d];

    dp[d] = false;
    for (int i = d + 1; i < n; i++)
    {
        int p = (i - d) * (1 + abs(a[i] - a[d]));
        if (p > k) continue;
        dp[d] |= CanGo(i, k, a, dp);
    }
    return dp[d];
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> dp(n - 1, -1);
    bool result = CanGo(0, k, a, dp);
    cout << (result ? "YES" : "NO") << '\n';
}
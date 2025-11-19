#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int MaxEnergy(int d, int k, vector<int>& f, vector<int>& dp)
{
    int n = f.size();
    if (d == n) return 0;
    if (dp[d] != -1) return dp[d];

    dp[d] = MaxEnergy(d + 1, k, f, dp);
    int s = 0, t = d;
    while (t < n && s < k)
        s += f[t++];
    return dp[d] = max(dp[d], MaxEnergy(t, k, f, dp) + max(s - k, 0));
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<int> f(n);
    for (int i = 0; i < n; i++)
        cin >> f[i];

    vector<int> dp(n, -1);
    int result = MaxEnergy(0, k, f, dp);
    cout << result << '\n';
}
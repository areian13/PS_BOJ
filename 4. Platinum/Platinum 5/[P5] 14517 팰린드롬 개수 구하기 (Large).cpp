#include <iostream>
#include <string>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MOD = 10'007;

int SubPalin(int l, int r, string& s, vector<vector<int>>& dp)
{
    if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];

    dp[l][r] = 0;
    if (s[l] == s[r]) dp[l][r] = SubPalin(l + 1, r - 1, s, dp) + 1;
    dp[l][r] += SubPalin(l + 1, r, s, dp) + SubPalin(l, r - 1, s, dp) - SubPalin(l + 1, r - 1, s, dp) + MOD;
    return dp[l][r] %= MOD;
}

int main()
{
    FastIO;

    string s;
    cin >> s;

    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int result = SubPalin(0, n - 1, s, dp);
    cout << result << '\n';
}
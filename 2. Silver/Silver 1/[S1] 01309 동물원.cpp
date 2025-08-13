#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MOD 9'901

int Lion(int d, vector<int>& dp)
{
    int n = dp.size();

    if (d >= n)
        return 1;
    if (dp[d] != -1)
        return dp[d];

    int a = Lion(d + 1, dp) * 2 % MOD;
    int b = Lion(d + 2, dp) % MOD;
    return dp[d] = (a + b) % MOD;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> dp(n, -1);
    int result = Lion(0, dp);
    cout << result << '\n';
}
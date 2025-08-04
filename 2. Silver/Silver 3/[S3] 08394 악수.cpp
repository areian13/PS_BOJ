#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MOD 10

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> dp = { 1,1 };
    for (int i = 2; i <= n; i++)
        dp[i & 1] = (dp[i & 1] + dp[(i + 1) & 1]) % MOD;
    cout << dp[n & 1] << '\n';
}
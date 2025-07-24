#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long Binary(int i, int j, int n, int l, vector<vector<long long>>& dp)
{
    if (i == n || j == l)
        return dp[i][j] = 1;
    if (dp[i][j])
        return dp[i][j];
    return dp[i][j] = Binary(i + 1, j, n, l, dp) + Binary(i + 1, j + 1, n, l, dp);
}
int main()
{
    int n, l;
    long long k;
    cin >> n >> l >> k;

    vector<vector<long long>> dp(n + 1, vector<long long>(l + 1, 0));
    for (int i = 1, j = 0; i <= n; i++)
    {
        long long ithCase = Binary(i, j, n, l, dp);
        bool isValid = ithCase < k;

        k -= ithCase * isValid;
        j += isValid;

        cout << isValid;
    }
}
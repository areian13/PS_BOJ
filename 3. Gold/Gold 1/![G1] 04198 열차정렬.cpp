#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Train(int l, int r, vector<int>& a, vector<vector<int>>& dp)
{
    int n = a.size();
    int& result = dp[l][r];
    if (result != -1) return result;

    result = 1;
    for (int i = l - 1; i >= 0; i--)
    {
        if (a[i] < a[r])
            result = max(result, Train(i, r, a, dp) + 1);
        else dp[i][r] = 0;
    }
    for (int i = r + 1; i < n; i++)
    {
        if (a[r] < a[i])
            result = max(result, Train(l, i, a, dp) + 1);
        else dp[i][r] = 0;
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<int>> dp(n, vector<int>(n, -1));
    int result = 0;
    for (int i = 0; i < n; i++)
        result = max(result, Train(i, i, a, dp));
    cout << result << '\n';
}
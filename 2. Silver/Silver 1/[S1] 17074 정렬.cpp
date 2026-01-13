#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

int CountSort(int d, bool del, vector<int>& a,
    vector<vector<int>>& dp)
{
    int n = a.size() - 1;
    if (d == n) return 1;
    int& result = dp[del][d];
    if (result != -1) return result;

    result = 0;
    if (d + 1 <= n && a[d] <= a[d + 1] || (!del && d == n - 1))
        result += CountSort(d + 1, del, a, dp);
    if (!del && (d + 2 <= n && a[d] <= a[d + 2]))
        result += CountSort(d + 2, true, a, dp);
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n + 1, -INF);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<vector<int>> dp(2, vector<int>(n, -1));
    int result = CountSort(0, false, a, dp);
    cout << result << '\n';
}
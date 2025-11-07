#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int MaxWine(int d, vector<int>& wine, vector<int>& dp)
{
    if (d < 0) return 0;
    if (dp[d] != -1) return dp[d];

    int a = wine[d] + (d == 0 ? 0 : wine[d - 1]) + MaxWine(d - 3, wine, dp);
    int b = wine[d] + MaxWine(d - 2, wine, dp);
    int c = MaxWine(d - 1, wine, dp);
    return dp[d] = max({ a,b,c });
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> wine(n);
    for (int i = 0; i < n; i++)
        cin >> wine[i];

    vector<int> dp(n, -1);
    int result = MaxWine(n - 1, wine, dp);
    cout << result << '\n';
}
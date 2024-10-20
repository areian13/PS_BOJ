#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

#define MAX 8

int Comb(int n, int m)
{
    static vector<vector<int>> dp(MAX + 1, vector<int>(MAX + 1, -1));

    if (n < 0 || m < 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (n == m || m == 0)
        return dp[n][m] = 1;
    return dp[n][m] = Comb(n - 1, m - 1) + Comb(n - 1, m);
}

int main()
{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;

    int kSum = 0;
    for (int i = k; i <= m; i++)
        kSum += Comb(m, i) * Comb(n - m, m - i);

    lf(9);
    double result = (double)kSum / Comb(n, m);
    cout << result << '\n';
}
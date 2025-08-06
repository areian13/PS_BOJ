#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 200'000

bool IsPrime(int n)
{
    static vector<bool> isPrime(MAX + 1, true);
    static bool init = false;

    if (!init)
    {
        init = true;
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= MAX; i++)
        {
            if (!isPrime[i])
                continue;
            for (int j = i * i; j <= MAX; j += i)
                isPrime[j] = false;
        }
    }
    return isPrime[n];
}

int MaxScore(int d, int a, int b,
    vector<vector<int>>& t, vector<int>& dp)
{
    int n = t[0].size();

    if (d >= n)
        return 0;
    if (dp[d] != -1)
        return dp[d];

    int p = (IsPrime(t[0][d] + t[1][d]) ? a : b)
        + MaxScore(d + 1, a, b, t, dp);
    int q = (d == n - 1) ? 0 :
        ((IsPrime(t[0][d] + t[0][d + 1]) ? a : b)
            + (IsPrime(t[1][d] + t[1][d + 1]) ? a : b)
            + MaxScore(d + 2, a, b, t, dp));
    return dp[d] = max(p, q);
}

int main()
{
    FastIO;

    int n, a, b;
    cin >> n >> a >> b;

    vector<vector<int>> t(2, vector<int>(n));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> t[i][j];
    }

    vector<int> dp(n, -1);
    int result = MaxScore(0, a, b, t, dp);
    cout << result << '\n';
}
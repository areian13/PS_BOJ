#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 1'000'000

bool IsPrime(int n)
{
    static vector<bool> isPrime(MAX, true);
    static bool init = false;

    if (!init)
    {
        init = true;
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i < MAX; i++)
        {
            if (!isPrime[i])
                continue;
            for (int j = i * i; j < MAX; j += i)
                isPrime[j] = false;
        }
    }

    return isPrime[n];
}

int cat(int a, int b)
{
    return stoi(to_string(a) + to_string(b));
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + IsPrime(cat(i, j));
    }

    cout << dp[n][n] - 1 << '\n';
}
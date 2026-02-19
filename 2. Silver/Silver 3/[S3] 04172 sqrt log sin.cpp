#include <iostream>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MAX = 1'000'000;
const int MOD = 1'000'000;

int X(int n, vector<int>& dp)
{
    if (dp[n] != -1) return dp[n];

    int a = X(n - sqrt(n), dp);
    int b = X(log(n), dp);
    int c = X(n * sin(n) * sin(n), dp);
    return dp[n] = (a + b + c) % MOD;
}

int main()
{
    FastIO;

    vector<int> dp(MAX + 1, -1);
    dp[0] = 1;

    while (true)
    {
        int n;
        cin >> n;

        if (n == -1)
            break;

        int result = X(n, dp);
        cout << result << '\n';
    }
}
#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long Fib(int n, vector<long long>& dp)
{
    if (n <= 2)
        return dp[n] = 1;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = Fib(n - 1, dp) + Fib(n - 2, dp);
}

long long Tile(int n)
{
    vector<long long> dp(n + 3, -1);
    return Fib(n + 2, dp) * 2;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    long long result = Tile(n);
    cout << result << '\n';
}
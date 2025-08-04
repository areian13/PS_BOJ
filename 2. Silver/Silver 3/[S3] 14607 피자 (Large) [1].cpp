#include <iostream>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long Pizza(int n, unordered_map<int, long long>& dp)
{
    if (dp.count(n) != 0)
        return dp[n];
    if (n == 1)
        return 0;

    long long result = 1LL * (n / 2) * ((n + 1) / 2);
    result += Pizza(n / 2, dp) + Pizza((n + 1) / 2, dp);
    return dp[n] = result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    unordered_map<int, long long> dp;
    long long result = Pizza(n, dp);
    cout << result << '\n';
}
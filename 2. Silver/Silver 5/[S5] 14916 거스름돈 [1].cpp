#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int MinCoin(int n)
{
    static vector<int> dp(n + 1, -1);

    if (n <= 0)
        return -1;
    if (n == 2 || n == 5)
        return dp[n] = 1;
    if (dp[n] != -1)
        return dp[n];

    int n2 = MinCoin(n - 2);
    int n5 = MinCoin(n - 5);
    if (n2 == -1 && n5 == -1)
        return dp[n] = -1;
    if (n2 == -1)
        return dp[n] = n5 + 1;
    if (n5 == -1)
        return dp[n] = n2 + 1;
    return dp[n] = min(n2, n5) + 1;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = MinCoin(n);
    cout << result << '\n';
}
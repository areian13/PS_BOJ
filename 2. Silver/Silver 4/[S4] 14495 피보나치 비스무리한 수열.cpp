#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 116

long long FakeFib(int n)
{
    static vector<long long> dp(MAX + 1, -1);

    if (n <= 3)
        return dp[n] = 1;
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = FakeFib(n - 1) + FakeFib(n - 3);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    long long result = FakeFib(n);
    cout << result << '\n';
}
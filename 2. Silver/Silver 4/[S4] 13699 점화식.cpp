#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 35

long long t(int n)
{
    static vector<long long> dp(MAX + 1, -1);

    if (n == 0)
        return dp[0] = 1;
    if (dp[n] != -1)
        return dp[n];

    long long result = 0;
    for (int i = 0; i < n; i++)
        result += t(i) * t(n - 1 - i);
    return dp[n] = result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    long long result = t(n);
    cout << result << '\n';
}
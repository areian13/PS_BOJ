#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 90

long long CountPinaryNum(int n)
{
    static vector<long long> dp(MAX + 1, -1);
    if (dp[n] != -1)
        return dp[n];
    if (n <= 1)
        return dp[n] = n;
    return dp[n] = CountPinaryNum(n - 1) + CountPinaryNum(n - 2);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    long long result = CountPinaryNum(n);
    cout << result << '\n';
}
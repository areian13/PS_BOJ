#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 100

long long P(int n)
{
    static vector<long long> dp(MAX + 1, -1);
    static bool isInited = false;

    if (!isInited)
    {
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 1;
        dp[4] = 2;
        isInited = true;
    }

    if (dp[n] != -1)
        return dp[n];
    return dp[n] = P(n - 1) + P(n - 5);
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        long long result = P(n);
        cout << result << '\n';
    }
}
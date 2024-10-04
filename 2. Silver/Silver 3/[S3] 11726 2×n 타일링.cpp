#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 1'000
#define MOD 10'007

int CountTile(int n)
{
    static vector<int> dp(MAX + 1, -1);
    static bool isInited = false;

    if (!isInited)
    {
        isInited = true;

        dp[1] = 1;
        dp[2] = 2;
    }

    if (dp[n] != -1)
        return dp[n];
    return dp[n] = (CountTile(n - 1) + CountTile(n - 2)) % MOD;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = CountTile(n);
    cout << result << '\n';
}
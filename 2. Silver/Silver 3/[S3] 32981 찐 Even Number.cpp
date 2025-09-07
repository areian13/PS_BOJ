#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 10'000'001
#define MOD 1'000'000'007

int RealEven(int n)
{
    static vector<int> dp(MAX, -1);
    dp[1] = 5, dp[2] = 20;

    if (dp[n] != -1)
        return dp[n];
    return dp[n] = RealEven(n - 1) * 5LL % MOD;
}

int main()
{
    FastIO;

    int QC;
    cin >> QC;

    for (int qc = 1; qc <= QC; qc++)
    {
        int n;
        cin >> n;

        cout << RealEven(n) << '\n';
    }
}
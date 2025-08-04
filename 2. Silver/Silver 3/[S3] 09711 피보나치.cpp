#include <iostream>
#include <cstdio>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MOD 2'000'000'000

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int p, q;
        cin >> p >> q;

        vector<int> dp = { 0,1 };
        for (int i = 2; i <= p; i++)
            dp[i & 1] = (1LL * dp[i & 1] + dp[~i & 1]) % q;

        printf("Case #%d: %d\n", tc, dp[p & 1] % q);
    }
}
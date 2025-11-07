#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MAX = 1'000;

int PalPar(int n)
{
    static vector<int> dp(MAX + 1, 1);
    if (n == 1) return 1;
    if (dp[n] != 1) return dp[n];

    for (int i = 0; i < n; i++)
    {
        if ((n - i) % 2 == 0)
            dp[n] += PalPar((n - i) / 2);
    }
    return dp[n];
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        int result = PalPar(n);
        cout << result << '\n';
    }
}
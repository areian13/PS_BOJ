#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsPalin(int s, int e, vector<int>& num, vector<vector<bool>>& dp)
{
    if (dp[s][e] == true)
        return true;

    if (s == e || s + 1 == e)
        return dp[s][e] = (num[s] == num[e]);

    return dp[s][e] = ((num[s] == num[e]) && IsPalin(s + 1, e - 1, num, dp));
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> num(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> num[i];

    int m;
    cin >> m;

    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
    while (m--)
    {
        int s, e;
        cin >> s >> e;

        cout << IsPalin(s, e, num, dp) << '\n';
    }
}
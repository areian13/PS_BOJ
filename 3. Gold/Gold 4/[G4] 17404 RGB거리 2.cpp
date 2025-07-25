#include <iostream>
#include <vector>
#include <array>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int MinPrice(int idx, int color, vector<array<int, 3>>& home, vector<array<int, 3>>& dp)
{
    if (idx == home.size() - 1)
        return home[idx][color];

    if (dp[idx][color] != 0)
        return dp[idx][color];

    int a = (color + 1) % 3;
    int b = (color + 2) % 3;

    return dp[idx][color] = home[idx][color] + min(MinPrice(idx + 1, a, home, dp), MinPrice(idx + 1, b, home, dp));
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<array<int, 3>> home(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> home[i][j];
    }

    array<int, 3> result;
    for (int i = 0; i < 3; i++)
    {
        vector<array<int, 3>> dp(n);

        int temp = home[n - 1][i];
        home[n - 1][i] = INT_MAX;
        result[i] = MinPrice(0, i, home, dp);
        home[n - 1][i] = temp;
    }

    cout << min({ result[0],result[1],result[2] }) << '\n';
}
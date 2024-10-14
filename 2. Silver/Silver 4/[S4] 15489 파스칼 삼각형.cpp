#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 30

int Pascal(int r, int c)
{
    static vector<vector<int>> dp(MAX + 1, vector<int>(MAX + 1, -1));

    if (dp[r][c] != -1)
        return dp[r][c];
    if (r == c || c == 1)
        return dp[r][c] = 1;
    return dp[r][c] = Pascal(r - 1, c) + Pascal(r - 1, c - 1);
}

int main()
{
    FastIO;

    int r, c, w;
    cin >> r >> c >> w;

    int result = 0;
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j <= i; j++)
            result += Pascal(r + i, c + j);
    }
    cout << result << '\n';
}
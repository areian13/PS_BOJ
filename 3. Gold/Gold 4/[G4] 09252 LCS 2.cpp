#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string a, b;
    cin >> a >> b;

    vector<vector<int>> dp(b.size() + 1, vector<int>(a.size() + 1, 0));
    for (int i = 1; i <= b.size(); i++)
    {
        for (int j = 1; j <= a.size(); j++)
        {
            if (b[i - 1] == a[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int y = b.size();
    int x = a.size();

    string result = "";
    while (dp[y][x] != 0)
    {
        if (dp[y][x] == dp[y - 1][x])
            y--;
        else if (dp[y][x] == dp[y][x - 1])
            x--;
        else
        {
            result += b[y - 1];
            y--;
            x--;
        }
    }
    reverse(result.begin(), result.end());
    cout << result.size() << '\n' << result << '\n';
}
#include <iostream>
#include <vector>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 2> dr = { 0,1 };
array<int, 2> dc = { 1,0 };

string add(string a, string b)
{
    if (a.size() > b.size())
        swap(a, b);

    int n = a.size(), m = b.size();
    int i = 0;
    string result = "";
    int carry = 0;
    while (i < n)
    {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result += sum % 10 + '0';
        carry = sum / 10;
        i++;
    }
    while (i < m)
    {
        int sum = (b[i] - '0') + carry;
        result += sum % 10 + '0';
        carry = sum / 10;
        i++;
    }
    if (carry != 0)
        result += carry + '0';
    return result;
}
void print(string s)
{
    reverse(s.begin(), s.end());
    cout << s << '\n';
}

string Route(int r, int c, vector<vector<int>>& map,
    vector<vector<string>>& dp)
{
    int n = dp.size();
    if (dp[r][c] != "") return dp[r][c];
    if (r == n - 1 && c == n - 1) return "1";

    dp[r][c] = "0";
    for (int i = 0; i < 2; i++)
    {
        int nr = r + dr[i] * map[r][c];
        int nc = c + dc[i] * map[r][c];

        if (nr >= n || nc >= n)
            continue;

        dp[r][c] = add(dp[r][c], Route(nr, nc, map, dp));
    }
    return dp[r][c];
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> map(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    }

    vector<vector<string>> dp(n, vector<string>(n, ""));
    string result = Route(0, 0, map, dp);
    print(result);
}
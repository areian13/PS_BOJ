#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 15

int Fib2D(int y, int x)
{
    static vector<vector<int>> dp(MAX + 1, vector<int>(MAX + 1, -1));

    if (y == 0 || x == 0)
        return 1;
    if (dp[y][x] != -1)
        return dp[y][x];
    return dp[y][x] = Fib2D(y - 1, x) + Fib2D(y, x - 1);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> m(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> m[i][j];
    }

    array<int, 2> result = { Fib2D(n, n), n * n };
    cout << result[0] << ' ' << result[1] << '\n';
}
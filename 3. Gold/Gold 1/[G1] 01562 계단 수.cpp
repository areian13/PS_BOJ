#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MOD 1'000'000'000

int DFS(int depth, int num, int isVisited, vector<vector<vector<int>>>& dp)
{
    int n = dp.size() - 1;
    int result = dp[depth][num][isVisited];

    if (result != -1)
        return result;
    if (depth == n)
        return isVisited == (1 << 10) - 1;

    result = 0;
    if (num + 1 <= 9)
        result += DFS(depth + 1, num + 1, isVisited | 1 << (num + 1), dp);
    if (num - 1 >= 0)
        result += DFS(depth + 1, num - 1, isVisited | 1 << (num - 1), dp);
    result %= MOD;

    return dp[depth][num][isVisited] = result;
}
int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(10, vector<int>(1 << 10, -1)));
    int result = 0;
    for (int i = 1; i <= 9; i++)
    {
        result += DFS(1, i, 1 << i, dp);
        result %= MOD;
    }
    cout << result << '\n';
}
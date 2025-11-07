#include <iostream>
#include <string>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

bool CanGo(char a, char b)
{
    if (a == 'B') return b == 'O';
    if (a == 'O') return b == 'J';
    return b == 'B';
}

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;

    vector<int> dp(n, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == INF)
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (!CanGo(s[i], s[j]))
                continue;
            dp[j] = min(dp[j], dp[i] + (j - i) * (j - i));
        }
    }
    if (dp[n - 1] == INF)
        cout << -1 << '\n';
    else
        cout << dp[n - 1] << '\n';
}
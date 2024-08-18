#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<array<int, 2>> grade(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grade[i][0] >> grade[i][1];
        grade[i][0]--, grade[i][1]--;
    }

    vector<array<int, 5>> dp(n);
    array<int, 5> cnt = { 0, };
    for (int i = 0; i < n; i++)
    {
        dp[i][grade[i][0]] = (i == 0 ? 0 : dp[i - 1][grade[i][0]]) + 1;
        cnt[grade[i][0]] = max(cnt[grade[i][0]], dp[i][grade[i][0]]);

        dp[i][grade[i][1]] = (i == 0 ? 0 : dp[i - 1][grade[i][1]]) + 1;
        cnt[grade[i][1]] = max(cnt[grade[i][1]], dp[i][grade[i][1]]);
    }

    int result = 0;
    for (int i = 0; i < 5; i++)
    {
        if (cnt[result] < cnt[i])
            result = i;
    }
    cout << cnt[result] << ' ' << result + 1 << '\n';
}
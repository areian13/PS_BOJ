#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MAX = 1'000'000;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> dp(MAX + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        dp[a] = max(dp[a], dp[a - 1] + 1);
    }

    int result = 0;
    for (int i = 1; i <= MAX; i++)
        result = max(result, dp[i]);
    cout << result << '\n';
}
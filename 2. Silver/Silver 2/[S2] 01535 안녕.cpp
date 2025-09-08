#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX_L 100

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> l(n), h(n);
    for (int i = 0; i < n; i++)
        cin >> l[i];
    for (int i = 0; i < n; i++)
        cin >> h[i];

    vector<int> dp(MAX_L + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = MAX_L - 1; j >= 0; j--)
        {
            if (j + l[i] >= MAX_L)
                continue;

            dp[j + l[i]] = max(dp[j + l[i]], dp[j] + h[i]);
        }
    }

    int result = 0;
    for (int i = 0; i < MAX_L; i++)
        result = max(result, dp[i]);
    cout << result << '\n';
}
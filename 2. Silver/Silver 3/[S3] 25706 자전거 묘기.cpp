#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> dp(n, 1);
    for (int i = n - 1; i >= 0; i--)
        dp[i] += (i + a[i] + 1 >= n ? 0 : dp[i + a[i] + 1]);

    for (int i = 0; i < n; i++)
        cout << dp[i] << ' ';
    cout << '\n';
}
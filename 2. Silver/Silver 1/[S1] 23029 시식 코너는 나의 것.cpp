#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Sisik(int d, vector<int>& s, vector<int>& dp)
{
    int n = s.size();
    if (d >= n) return 0;
    if (dp[d] != -1) return dp[d];

    int a = Sisik(d + 3, s, dp) + s[d] + (d + 1 < n ? s[d + 1] / 2 : 0);
    int b = Sisik(d + 2, s, dp) + s[d];
    int c = Sisik(d + 1, s, dp);
    return dp[d] = max({ a,b,c });
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    vector<int> dp(n, -1);
    int result = Sisik(0, s, dp);
    cout << result << '\n';
}
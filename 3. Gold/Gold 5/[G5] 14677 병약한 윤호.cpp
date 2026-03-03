#include <iostream>
#include <string>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Drugs(int l, int r, char p, string& d, vector<vector<int>>& dp)
{
    static const string bld = "BLD";

    if (l > r) return 0;
    int& result = dp[l][r];
    if (result != -1) return result;

    result = 0;
    if (bld[(bld.find(d[l]) + 2) % 3] == p)
        result = max(result, Drugs(l + 1, r, d[l], d, dp) + 1);
    if (bld[(bld.find(d[r]) + 2) % 3] == p)
        result = max(result, Drugs(l, r - 1, d[r], d, dp) + 1);
    return result;
}

int main()
{
    FastIO;

    int n;
    string d;
    cin >> n >> d;
    n *= 3;

    vector<vector<int>> dp(n, vector<int>(n, -1));
    int result = Drugs(0, n - 1, 'D', d, dp);
    cout << result << '\n';
}
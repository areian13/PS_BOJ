#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long MinEnergy(int i, vector<int>& r)
{
    int n = r.size();
    static vector<long long> dp(n, -1);

    if (i <= 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    return dp[i] = min(MinEnergy(i - 1, r) + r[i], MinEnergy(i - 2, r) + r[i - 1]);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> r(n);
    for (int i = 0; i < n; i++)
        cin >> r[i];

    long long result = MinEnergy(n - 1, r);
    cout << result << '\n';
}
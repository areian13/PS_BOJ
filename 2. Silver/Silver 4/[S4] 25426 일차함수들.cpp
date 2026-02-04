#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> f(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> f[i][0] >> f[i][1];
    sort(f.begin(), f.end());

    long long result = 0;
    for (int i = 0; i < n; i++)
        result += f[i][0] * (i + 1LL) + f[i][1];
    cout << result << '\n';
}
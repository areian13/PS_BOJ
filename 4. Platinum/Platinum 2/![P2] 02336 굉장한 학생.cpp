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

    vector<vector<int>> g(n, vector<int>(4));
    for (int i = 0; i < n; i++)
        g[i][3] = i;
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;

            g[k - 1][j] = i;
        }
    }
    for (auto& v : g)
        cout << v[3] << ' ' << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';

    sort(g.begin(), g.end(),
        [](const auto& a, const auto& b) { return a[0] < b[0]; }
    );

    cout << '\n';
    for (auto& v : g)
        cout << v[3] << ' ' << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';
}
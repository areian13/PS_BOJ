#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }

    vector<vector<int>> b(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> b[i][j];
    }

    vector<int> memo(n, 0);
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
            memo[j] = max(memo[j], abs(a[i][j] - b[i][j]));
    }

    int result = 0;
    for (int i = 0; i < m; i++)
    {
        int p;
        cin >> p;

        result += memo[p - 1];
    }
    cout << result << '\n';
}
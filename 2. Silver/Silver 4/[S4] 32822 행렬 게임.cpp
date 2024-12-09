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

    vector<int> maxDiff(n, -1);
    int result = 0;
    for (int tc = 1; tc <= m; tc++)
    {
        int q;
        cin >> q;
        q--;

        if (maxDiff[q] == -1)
        {
            int diff = 0;
            for (int i = 0; i < n; i++)
                diff = max(diff, abs(a[i][q] - b[i][q]));
            maxDiff[q] = diff;
        }
        result += maxDiff[q];
    }
    cout << result << '\n';
}
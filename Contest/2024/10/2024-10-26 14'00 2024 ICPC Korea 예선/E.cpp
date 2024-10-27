#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf cout.unsetf(ios::scientific);

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

    vector<int> chan(m);
    for (int i = 0; i < m; i++)
    {
        cin >> chan[i];
        chan[i]--;
    }

    int result = 0;
    unordered_map<int, int> maxDiffMap;
    for (int i = 0; i < m; i++)
    {
        if (maxDiffMap.count(chan[i]) == 1)
            result += maxDiffMap[chan[i]];
        else
        {
            int maxDiff = 0;
            for (int j = 0; j < n; j++)
                maxDiff = max(maxDiff, abs(a[j][chan[i]] - b[j][chan[i]]));
            maxDiffMap[chan[i]] = maxDiff;
            result += maxDiff;
        }
    }
    cout << result << '\n';
}
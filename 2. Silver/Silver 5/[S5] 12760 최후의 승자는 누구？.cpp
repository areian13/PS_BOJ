#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> c(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> c[i][j];
        sort(c[i].begin(), c[i].end(), greater<int>());
    }

    vector<int> cnt(n, 0);
    for (int j = 0; j < m; j++)
    {
        int maxC = 0;
        for (int i = 0; i < n; i++)
            maxC = max(maxC, c[i][j]);

        for (int i = 0; i < n; i++)
            cnt[i] += (maxC == c[i][j]);
    }

    int maxCnt = *max_element(cnt.begin(), cnt.end());
    for (int i = 0; i < n; i++)
    {
        if (cnt[i] == maxCnt)
            cout << i + 1 << ' ';
    }
    cout << '\n';
}
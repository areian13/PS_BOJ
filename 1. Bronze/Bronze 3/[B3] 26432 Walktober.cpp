#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        int m, n, p;
        cin >> m >> n >> p;

        vector<vector<int>> score(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> score[i][j];
        }

        int result = 0;
        for (int i = 0; i < n; i++)
        {
            int gap = 0;
            for (int j = 0; j < m; j++)
                gap = max(gap, max(score[j][i] - score[p - 1][i], 0));
            result += gap;
        }
        printf("Case #%d: %d\n", t, result);
    }
}
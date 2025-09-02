#include <iostream>
#include <cstdio>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n, k;
        cin >> n >> k;

        vector<vector<int>> r(4, vector<int>(n));
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> r[i][j];
        }

        int result = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int p = 0; p < n; p++)
                {
                    for (int l = 0; l < n; l++)
                        result += (r[0][i] ^ r[1][j] ^ r[2][p] ^ r[3][l]) == k;
                }
            }
        }
        printf("Case #%d: %d\n", tc, result);
    }
}
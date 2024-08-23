#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int m;
        cin >> m;

        vector<vector<long long>> kdas(m, vector<long long>(3));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < 3; j++)
                cin >> kdas[i][j];
        }

        long long k, d, a;
        cin >> k >> d >> a;

        long long result = 0;
        for (int i = 0; i < m; i++)
            result += max(kdas[i][0] * k - kdas[i][1] * d + kdas[i][2] * a, 0ll);
        cout << result << '\n';
    }
}
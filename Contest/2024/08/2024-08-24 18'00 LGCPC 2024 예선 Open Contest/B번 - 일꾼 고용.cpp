#include <iostream>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> c(n);
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
            c[i]--;
        }

        vector<long long> w(n);
        for (int i = 0; i < n; i++)
            cin >> w[i];

        vector<vector<int>> cSum(2, vector<int>(n + 1, 0));
        vector<vector<long long>> wSum(2, vector<long long>(n + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            cSum[c[i - 1]][i]++;
            wSum[c[i - 1]][i] += w[i - 1];

            cSum[0][i] += cSum[0][i - 1];
            wSum[0][i] += wSum[0][i - 1];

            cSum[1][i] += cSum[1][i - 1];
            wSum[1][i] += wSum[1][i - 1];

        }
        cout << '\n';
        for (int i = 0; i <= n; i++)
        {
            cout << cSum[0][i] << ' ' << cSum[1][i] << '\n';

        }
        cout << '\n';

        int result = 0;
        int l = 0, r = 2;
        while (r < n)
        {
            cout << l << ' ' << r << '\n';
            int a = cSum[0][r] - cSum[0][l];
            int b = cSum[1][r] - cSum[1][l];

            int aw = wSum[0][r] - wSum[0][l];
            int bw = wSum[1][r] - wSum[1][l];

            if (a == b)
            {
                //cout << l << ' ' << r << '\n';
                //cout << aw << ' ' << bw << '\n' << '\n';

                result += (abs(aw - bw) <= k);
                r++;
            }
            else
            {
                if (l == r - 2)
                    r++;
                else if (a > b && c[l] == 1)
                    l++;
                else if (a < b && c[l] == 0)
                    l++;
                else
                    r++;
            }
        }


        while (l < n - 2)
        {
            int a = cSum[0][n] - cSum[0][l];
            int b = cSum[1][n] - cSum[1][l];

            int aw = wSum[0][n] - wSum[0][l];
            int bw = wSum[1][n] - wSum[1][l];

            if (a == b)
                result += (abs(aw - bw) <= k);
            l++;
        }
        cout << result << '\n';
    }
}
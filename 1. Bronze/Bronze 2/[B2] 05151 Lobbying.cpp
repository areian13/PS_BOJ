#include <iostream>
#include <cstdio>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    for (int k = 1; k <= tc; k++)
    {
        int n, m, T;
        cin >> n >> m >> T;

        vector<double> total(n, 0);
        for (int i = 0; i < m; i++)
        {
            int idx, t;
            double d;
            cin >> idx >> t >> d;

            total[idx - 1] += d * (0 <= T - t && T - t < 1'000);
        }

        array<double, 2> result = { 0,0 };
        for (int i = 0; i < n; i++)
        {
            char vote;
            cin >> vote;

            bool isYes = (vote == 'Y');

            result[!isYes] += (isYes ? 1.0 : (1 / (1 + total[i] / 10'000)));
        }
        printf("Data Set %d:\n%.2lf %.2lf\n\n", k, result[0], result[1]);
    }
}
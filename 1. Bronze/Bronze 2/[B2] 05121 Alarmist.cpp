#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
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
        int n, w;
        cin >> n >> w;

        vector<int> s(n);
        for (int i = 0; i < n; i++)
            cin >> s[i];

        int sum = 0;
        int maxAvg = 0;
        int minAvg = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            sum += s[i];
            
            if (i + 1 < w)
                continue;

            int avg = sum / w;
            maxAvg = max(maxAvg, avg);
            minAvg = min(minAvg, avg);

            sum -= s[i + 1 - w];
        }

        int result = maxAvg - minAvg;
        printf("Data Set %d:\n%d\n\n", t, result);
    }
}
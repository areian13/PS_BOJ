#include <iostream>
#include <vector>
#include <numeric>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int h, w, c, d;
    cin >> h >> w >> c >> d;

    int minSum = h * (h - 1) / 2;
    if (d < minSum)
    {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> result(h);
    for (int i = 0; i < h; i++)
        result[i] = i;

    int rSum = d - minSum;
    for (int i = h - 1; i >= 0; i--)
    {
        int maxInc = min({ rSum, w - result[i], (i == h - 1 ? INT_MAX : result[i + 1] - 1 - result[i]) });
        result[i] += maxInc;
        rSum -= maxInc;
    }

    if (rSum != 0)
    {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0; i < h - 1; i++)
    {
        if (result[i] == result[i + 1])
        {
            cout << -1 << '\n';
            return 0;
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < result[i]; j++)
            cout << 9 << ' ';
        for (int j = 0; j < w - result[i]; j++)
            cout << 1 << ' ';
        cout << '\n';
    }
}
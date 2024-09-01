#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 256

struct Nogada
{
    int t, y;
};

int main()
{
    FastIO;

    int n, m, b;
    cin >> n >> m >> b;

    vector<int> height(MAX + 1, 0);
    for (int x = 0; x < n; x++)
    {
        for (int z = 0; z < m; z++)
        {
            int g;
            cin >> g;

            height[g]++;
        }
    }

    Nogada result = { INT_MAX, 0 };
    for (int y = 0; y <= MAX; y++)
    {
        int havingBlock = b;
        int time = 0;

        for (int ty = 0; ty <= MAX; ty++)
        {
            int block = abs(y - ty) * height[ty];

            bool isNeeded = (y > ty);
            time += (isNeeded ? 1 : 2) * block;
            havingBlock += (isNeeded ? -1 : +1) * block;
        }

        if (havingBlock < 0)
            continue;

        if (time <= result.t)
            result = { time,y };
    }
    cout << result.t << ' ' << result.y << '\n';
}
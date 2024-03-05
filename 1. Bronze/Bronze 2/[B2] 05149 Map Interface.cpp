#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int x, y;
};

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        int n, m;
        cin >> n >> m;

        vector<Pos> pos(n);
        for (int i = 0; i < n; i++)
            cin >> pos[i].x >> pos[i].y;

        int minX = INT_MAX;
        int maxX = INT_MIN;
        int minY = INT_MAX;
        int maxY = INT_MIN;

        for (int i = 0; i < m; i++)
        {
            int s;
            cin >> s;
            s--;

            minX = min(minX, pos[s].x);
            maxX = max(maxX, pos[s].x);
            minY = min(minY, pos[s].y);
            maxY = max(maxY, pos[s].y);
        }

        int result = 0;
        for (int i = 0; i < n; i++)
            result += (minX <= pos[i].x && pos[i].x <= maxX) && (minY <= pos[i].y && pos[i].y <= maxY);

        printf("Data Set %d:\n%d\n\n", t, result);
    }
}
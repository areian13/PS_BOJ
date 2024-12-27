#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y;
};

long long Area2(vector<Point>& points)
{
    int p = points.size();

    long long result = 0;
    for (int i = 0; i < p; i++)
    {
        result += 1LL * points[i].x * points[(i + 1) % p].y;
        result -= 1LL * points[i].y * points[(i + 1) % p].x;
    }

    return abs(result);
}

int main()
{
    FastIO;

    int p = 3;

    vector<Point> tri(p);
    for (int i = 0; i < p; i++)
        cin >> tri[i].x >> tri[i].y;

    vector<int> gcds(p);
    bool hasResult = true;
    for (int i = 0; i < p; i++)
    {
        int dx = abs(tri[i].x - tri[(i + 1) % p].x);
        int dy = abs(tri[i].y - tri[(i + 1) % p].y);

        gcds[i] = gcd(dx, dy);
        hasResult &= (gcds[i] != 1);
    }

    if (!hasResult)
        cout << -1 << '\n';
    else
    {
        long long maxArea = 0;
        for (int j = 0; j < 2; j++)
        {
            vector<Point> points(p);
            for (int i = 0; i < p; i++)
            {
                int dx = (tri[i].x - tri[(i + 1) % p].x) / gcds[i];
                int dy = (tri[i].y - tri[(i + 1) % p].y) / gcds[i];

                if (j == 0)
                    points[i] = { tri[i].x - dx,tri[i].y - dy };
                else
                    points[i] = { tri[(i + 1) % p].x + dx,tri[(i + 1) % p].y + dy };
            }
            maxArea = max(maxArea, Area2(points));
        }

        long long minArea = LLONG_MAX;
        for (int j = 0; j < p; j++)
        {
            vector<Point> points(p);
            for (int i = 0; i < p; i++)
            {
                int dx = (tri[i].x - tri[(i + 1) % p].x) / gcds[i];
                int dy = (tri[i].y - tri[(i + 1) % p].y) / gcds[i];

                if (i == j)
                    points[i] = { tri[i].x - dx,tri[i].y - dy };
                else
                    points[i] = { tri[(i + 1) % p].x + dx,tri[(i + 1) % p].y + dy };
            }
            minArea = min(minArea, Area2(points));
        }
        cout << maxArea << ' ' << minArea << '\n';
    }
}
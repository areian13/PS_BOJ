#include <iostream>
#include <cstdio>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y;
};

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n, s, p;
        cin >> n >> s >> p;

        vector<Point> points(n + 1);
        for (auto& point : points)
            cin >> point.x >> point.y;

        int dist = 0;
        for (int i = 0; i < n; i++)
        {
            int dx = abs(points[i].x - points[i + 1].x);
            int dy = abs(points[i].y - points[i + 1].y);
            dist += max(dx, dy);
        }

        int result = (dist * s + p - 1) / p;
        printf("Data Set %d:\n%d\n\n", tc, result);
    }
}
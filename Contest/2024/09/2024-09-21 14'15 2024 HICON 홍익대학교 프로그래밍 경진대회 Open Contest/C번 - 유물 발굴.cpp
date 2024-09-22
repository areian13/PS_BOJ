#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y;
};

long long GetArea(pair<Point, Point>& rect)
{
    if (rect.first.x == INT_MAX)
        return 0;

    int dx = rect.second.x - rect.first.x + 1;
    int dy = rect.second.y - rect.first.y + 1;
    return (long long)dx * dy;
}

int main()
{
    FastIO;

    int r, c, n;
    cin >> r >> c >> n;

    vector<pair<Point, Point>> rects(n,
        { 
            { INT_MAX,INT_MAX },
            { INT_MIN,INT_MIN }
        }
    );

    for (int i = 0; i < n; i++)
    {
        int a, v, h;
        cin >> a >> v >> h;
        a--;

        rects[a].first.x = min(rects[a].first.x, h);
        rects[a].first.y = min(rects[a].first.y, v);

        rects[a].second.x = max(rects[a].second.x, h);
        rects[a].second.y = max(rects[a].second.y, v);
    }

    int result = -1;
    long long maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        long long area = GetArea(rects[i]);
        if (area > maxArea)
        {
            maxArea = area;
            result = i;
        }
    }

    cout << result + 1 << ' ' << GetArea(rects[result]) << '\n';
}
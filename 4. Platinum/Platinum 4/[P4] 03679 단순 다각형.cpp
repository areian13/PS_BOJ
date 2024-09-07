#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y, i;

    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        long long ccw = (long long)(b.x - a.x) * (c.y - a.y)
            - (long long)(b.y - a.y) * (c.x - a.x);

        if (ccw < 0)
            return -1;
        if (ccw > 0)
            return +1;
        return 0;
    }
};

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        vector<Point> points(n);
        for (int i = 0; i < n; i++)
        {
            points[i].i = i;
            cin >> points[i].x >> points[i].y;
        }

        Point zeroPoint = *min_element(points.begin(), points.end(),
            [](const Point& a, const Point& b)
            {
                if (a.x != b.x)
                    return a.x < b.x;
                return a.y < b.y;
            }
        );
        sort(points.begin(), points.end(),
            [&zeroPoint](const Point& a, const Point& b)
            {
                int ccw = Point::CCW(zeroPoint, a, b);

                if (ccw != 0)
                    return ccw > 0;
                if (a.x != b.x)
                    return a.x < b.x;
                return a.y < b.y;
            }
        );

        int idx = n - 1;
        while (idx >= 1)
        {
            if (Point::CCW(zeroPoint, points[idx], points[idx - 1]) != 0)
                break;
            idx--;
        }
        reverse(points.begin() + idx, points.end());

        for (int i = 0; i < n; i++)
            cout << points[i].i << ' ';
        cout << '\n';
    }
}
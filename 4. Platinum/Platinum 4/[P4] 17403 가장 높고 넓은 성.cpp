#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y, i;
    bool isUsed;

    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        long long ccw = (long long)(b.x - a.x) * (c.y - a.y) - (long long)(b.y - a.y) * (c.x - a.x);

        if (ccw > 0)
            return +1;
        if (ccw < 0)
            return -1;
        return 0;
    }
};

void MakeConvexHull(vector<Point>& points, vector<int>& convexHull)
{
    int n = points.size();

    Point zeroPoint = *min_element(points.begin(), points.end(),
        [](const Point& a, const Point& b)
        {
            if (a.isUsed != b.isUsed)
                return a.isUsed < b.isUsed;

            if (a.y != b.y)
                return a.y < b.y;
            return a.x < b.x;
        }
    );
    sort(points.begin(), points.end(),
        [&zeroPoint](const Point& a, const Point& b)
        {
            if (a.isUsed != b.isUsed)
                return a.isUsed < b.isUsed;

            int ccw = Point::CCW(zeroPoint, a, b);
            if (ccw != 0)
                return ccw > 0;
            if (a.y != b.y)
                return a.y < b.y;
            return a.x < b.x;
        }
    );

    for (int i = 0; i < n && !points[i].isUsed; i++)
    {
        while (convexHull.size() >= 2)
        {
            int second = convexHull.back();
            convexHull.pop_back();
            int first = convexHull.back();

            if (Point::CCW(points[first], points[second], points[i]) > 0)
            {
                convexHull.push_back(second);
                break;
            }
        }

        convexHull.push_back(i);
    }
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
        points[i].i = i;
        points[i].isUsed = false;
    }

    vector<int> result(n, 0);
    int floor = 0;
    while (true)
    {
        vector<int> convexHull;
        MakeConvexHull(points, convexHull);

        if (convexHull.size() < 3)
            break;

        floor++;
        for (int idx : convexHull)
        {
            points[idx].isUsed = true;
            result[points[idx].i] = floor;
        }
    }

    for (int i = 0; i < n; i++)
        cout << result[i] << ' ';
    cout << '\n';
}
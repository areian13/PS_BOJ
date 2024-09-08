#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MIN_AREA 50

struct Point
{
    int x, y;

    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        long long ccw = (long long)(b.x - a.x) * (c.y - a.y) - (long long)(b.y - a.y) * (c.x - a.x);

        if (ccw < 0)
            return -1;
        if (ccw > 0)
            return +1;
        return 0;
    }
};

double MaxArea(vector<Point>& points)
{
    int n = points.size();

    Point zeroPoint = *min_element(points.begin(), points.end(),
        [](const Point& a, const Point& b)
        {
            if (a.y != b.y)
                return a.y < b.y;
            return a.x < b.x;
        }
    );
    sort(points.begin(), points.end(),
        [&zeroPoint](const Point& a, const Point& b)
        {
            long long ap = a.x - zeroPoint.x;
            long long aq = a.y - zeroPoint.y;
            long long bp = b.x - zeroPoint.x;
            long long bq = b.y - zeroPoint.y;

            if (aq * bp != ap * bq)
                return aq * bp < ap * bq;
            if (a.y != b.y)
                return a.y < b.y;
            return a.x < b.x;
        }
    );

    vector<int> convexHull;
    convexHull.push_back(0);
    convexHull.push_back(1);

    int next = 2;
    while (next < n)
    {
        while (convexHull.size() >= 2)
        {
            int second = convexHull.back();
            convexHull.pop_back();
            int first = convexHull.back();

            if (Point::CCW(points[first], points[second], points[next]) > 0)
            {
                convexHull.push_back(second);
                break;
            }
        }

        convexHull.push_back(next);
        next++;
    }

    int k = convexHull.size();
    long long s = 0;
    for (int i = 0; i < k; i++)
    {
        int j = (i + 1) % k;

        Point& a = points[convexHull[i]];
        Point& b = points[convexHull[j]];
        s += (long long)a.x * b.y;
        s -= (long long)a.y * b.x;
    }

    double result = abs(s) / 2.0;
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    int result = MaxArea(points) / MIN_AREA;
    cout << result << '\n';
}
#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y;

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
            if (a.x != b.x)
                return a.x < b.x;
            return a.y < b.y;
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
            if (a.x != b.x)
                return a.x < b.x;
            return a.y < b.y;
        }
    );

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
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<Point> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;

    vector<Point> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i].x >> b[i].y;

    vector<Point> points(n * m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            points[i * m + j] = { a[i].x + b[j].x,a[i].y + b[j].y };
    }

    vector<int> convexHull;
    MakeConvexHull(points, convexHull);

    int k = convexHull.size();
    cout << k << '\n';
    for (int i = 0; i < k; i++)
    {
        Point result = points[convexHull[i]];
        cout << result.x << ' ' << result.y << '\n';
    }
}
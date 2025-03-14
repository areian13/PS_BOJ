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
        long long ccw = 1LL * (b.x - a.x) * (c.y - a.y)
            - 1LL * (b.y - a.y) * (c.x - a.x);
        if (ccw > 0)
            return +1;
        if (ccw < 0)
            return -1;
        return 0;
    }
};

void MakeConvexHull(vector<Point>& points, vector<int>& poly)
{
    Point p0 = *min_element(points.begin(), points.end(),
        [](const Point& a, const Point& b)
        {
            if (a.y != b.y)
                return a.y < b.y;
            return a.x < b.x;
        }
    );
    sort(points.begin(), points.end(),
        [&p0](const Point& a, const Point& b)
        {
            int ccw = Point::CCW(a, b, p0);
            if (ccw != 0)
                return ccw > 0;
            if (a.y != b.y)
                return a.y < b.y;
            return a.x < b.x;
        }
    );

    int n = points.size();
    for (int i = 0; i < n; i++)
    {
        while (poly.size() >= 2)
        {
            int second = poly.back();
            poly.pop_back();
            int first = poly.back();

            if (Point::CCW(points[first], points[second], points[i]) > 0)
            {
                poly.push_back(second);
                break;
            }
        }

        poly.push_back(i);
    }
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    vector<int> poly;
    MakeConvexHull(points, poly);

    int result = poly.size();
    cout << result << '\n';
}
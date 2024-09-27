#include <iostream>
#include <vector>
#include <string>
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
            if (a.y != b.y)
                return a.y < b.y;
            return a.x < b.x;
        }
    );
    sort(points.begin(), points.end(),
        [&zeroPoint](const Point& a, const Point& b)
        {
            int ccw = Point::CCW(zeroPoint, a, b);
            if (ccw != 0)
                return ccw > 0;
            if (a.y != b.y)
                return a.y < b.y;
            return a.x < b.x;
        }
    );

    for (int i = 0; i < n; i++)
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

bool IsIn(Point p, vector<Point>& poly)
{
    int c = poly.size();

    if (c <= 2)
        return false;

    int ccw = Point::CCW(poly[c - 1], poly[0], p);
    if (ccw == 0)
        return false;

    for (int i = 0; i < c - 1; i++)
    {
        if (Point::CCW(poly[i], poly[i + 1], p) != ccw)
            return false;
    }
    return true;
}

bool CanSurvive(vector<Point>& points)
{
    int n = points.size();

    vector<int> convexHull;
    MakeConvexHull(points, convexHull);

    int c = convexHull.size();
    vector<Point> poly(c);
    for (int i = 0; i < c; i++)
        poly[i] = points[convexHull[i]];

    return !IsIn({ 0,0 }, poly);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    string result = (CanSurvive(points) ? "Yes" : "No");
    cout << result << '\n';
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y;

    static double Dist(Point a, Point b)
    {
        long long dx = a.x - b.x;
        long long dy = a.y - b.y;
        return sqrt(dx * dx + dy * dy);
    }
    static int CCW(Point a, Point b, Point c)
    {
        long long cross = 1LL * (b.x - a.x) * (c.y - a.y)
            - 1LL * (b.y - a.y) * (c.x - a.x);
        return (cross == 0 ? 0 : (cross > 0 ? +1 : -1));
    }

    friend Point operator-(Point a, Point b)
    {
        return { a.x - b.x,a.y - b.y };
    }
};

void MakeConvexHull(vector<Point>& points, vector<int>& hullIndices)
{
    Point p0 = *min_element(points.begin(), points.end(),
        [](Point& a, Point& b)
        {
            if (a.y != b.y)
                return a.y < b.y;
            return a.x < b.x;
        }
    );
    sort(points.begin(), points.end(),
        [&p0](Point& a, Point& b)
        {
            int ccw = Point::CCW(p0, a, b);
            if (ccw != 0)
                return (ccw > 0);
            if (a.y != b.y)
                return a.y < b.y;
            return a.x < b.x;
        }
    );

    int n = points.size();
    for (int i = 0; i < n; i++)
    {
        while (hullIndices.size() >= 2)
        {
            int second = hullIndices.back();
            hullIndices.pop_back();
            int first = hullIndices.back();

            if (Point::CCW(points[first], points[second], points[i]) > 0)
            {
                hullIndices.push_back(second);
                break;
            }
        }

        hullIndices.push_back(i);
    }
}

pair<Point, Point> GetDiaPoint(vector<Point>& points)
{
    vector<int> hullIndices;
    MakeConvexHull(points, hullIndices);

    int h = hullIndices.size();
    vector<Point> hull(h);
    for (int i = 0; i < h; i++)
        hull[i] = points[hullIndices[i]];

    pair<Point, Point> result = { {0,0},{0,0} };
    auto comp = [](pair<Point, Point> a, pair<Point, Point> b)
        {
            return Point::Dist(a.first, a.second) < Point::Dist(b.first, b.second);
        };
    for (int i = 0, j = 1; i < h; i++)
    {
        while (j + 1 < h &&
            Point::CCW({ 0,0 }, hull[i + 1] - hull[i], hull[j + 1] - hull[j]) >= 0)
        {
            result = max(result, { hull[i], hull[j] }, comp);
            j++;
        }
        result = max(result, { hull[i], hull[j] }, comp);
    }
    return result;
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        vector<Point> points(n);
        for (int i = 0; i < n; i++)
            cin >> points[i].x >> points[i].y;

        pair<Point, Point> result = GetDiaPoint(points);
        cout << result.first.x << ' ' << result.first.y << ' ';
        cout << result.second.x << ' ' << result.second.y << '\n';
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cfloat>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y;

    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        long long ccw = 1LL * (b.x - a.x) * (c.y - a.y)
            - 1LL * (b.y - a.y) * (c.x - a.x);
        return (ccw > 0) - (ccw < 0);
    }
    static double Dist(const Point& a, const Point& b)
    {
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        return sqrt(dx * dx + dy * dy);
    }
    friend auto operator <=> (const Point& a, const Point& b) = default;
};

vector<Point> GetHull(vector<Point>& points) {
    Point p0 = *min_element(points.begin(), points.end(),
        [](const Point& a, const Point& b)
        {
            if (a.y != b.y) return a.y < b.y;
            return a.x < b.x;
        }
    );
    sort(points.begin(), points.end(),
        [&p0](const Point& a, const Point& b)
        {
            long long ccw = Point::CCW(p0, a, b);
            if (ccw != 0) return ccw > 0;
            if (a.y != b.y) return a.y < b.y;
            return a.x < b.x;
        }
    );

    int n = points.size();
    vector<Point> hull;
    for (int c = 0; c < n; c++)
    {
        while (hull.size() >= 2)
        {
            Point& b = hull[hull.size() - 1];
            Point& a = hull[hull.size() - 2];

            if (Point::CCW(a, b, points[c]) > 0)
                break;
            hull.pop_back();
        }
        hull.push_back(points[c]);
    }
    return hull;
}

bool IsIn(const Point& p, vector<Point>& hull)
{
    int n = hull.size();
    if (n < 3) return false;
    if (Point::CCW(hull[0], hull[1], p) <= 0) return false;
    if (Point::CCW(hull[0], hull[n - 1], p) >= 0) return false;

    int start = 1, end = n - 1;
    while (start + 1 < end)
    {
        int mid = (start + end) / 2;
        if (Point::CCW(hull[0], hull[mid], p) > 0) start = mid;
        else end = mid;
    }
    return Point::CCW(hull[start], hull[end], p) > 0;
}

int next(int i, int n) { return (i + 1) % n; }
int prev(int i, int n) { return (i - 1 + n) % n; }

double MinDist(Point& s, Point& t, vector<Point>& points)
{
    vector<Point> hull = GetHull(points);

    if (IsIn(s, hull) || IsIn(t, hull))
        return -1;

    hull.push_back(s), hull.push_back(t);
    hull = GetHull(hull);

    int n = hull.size();
    int i = 0, j = 0;
    while (i < n && Point::CCW(hull[i], hull[next(i, n)], s) > 0) i++;
    while (j < n && Point::CCW(hull[j], hull[next(j, n)], t) > 0) j++;

    if (i == j || i >= n || j >= n || n <= 3) // 필자는 || n <= 3을 넣는 것이 옳다고 생각하나, 현재는 없는 것이 맞았습니다가 뜨고 있음.
        return Point::Dist(s, t);

    double l = Point::Dist(s, hull[next(i, n)]) + Point::Dist(hull[j], t);
    double r = Point::Dist(s, hull[i]) + Point::Dist(hull[next(j, n)], t);
    for (int k = next(i, n); k != j; k = next(k, n))
        l += Point::Dist(hull[k], hull[next(k, n)]);
    for (int k = i; k != next(j, n); k = prev(k, n))
        r += Point::Dist(hull[k], hull[prev(k, n)]);
    return min(l, r);
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        Point s, t;
        cin >> s.x >> s.y >> t.x >> t.y;

        int n;
        cin >> n;

        vector<Point> points(n);
        for (auto& [x, y] : points)
            cin >> x >> y;

        double result = MinDist(s, t, points);
        if (result == -1)
            printf("IMPOSSIBLE\n");
        else
            printf("%.3lf\n", result);
    }
}
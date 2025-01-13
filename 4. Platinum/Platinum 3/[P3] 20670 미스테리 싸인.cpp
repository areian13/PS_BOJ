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
            return-1;
        return 0;
    }
};

struct Poly
{
    vector<Point> points;
    int n;

    Poly(int n) : n(n)
    {
        points.resize(n);
    }

    bool IsIn(const Point& p)
    {
        if (n < 3)
            return false;
        if (Point::CCW(points[0], points[1], p) < 0)
            return false;
        if (Point::CCW(points[0], points[n - 1], p) > 0)
            return false;

        int start = 1, end = n - 1;
        while (start + 1 < end)
        {
            int mid = (start + end) / 2;

            if (Point::CCW(points[0], points[mid], p) > 0)
                start = mid;
            else
                end = mid;
        }

        return Point::CCW(points[start], points[end], p) > 0;
    }
};

int main()
{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;

    Poly a(n);
    for (int i = 0; i < n; i++)
        cin >> a.points[i].x >> a.points[i].y;

    Poly b(m);
    for (int i = 0; i < m; i++)
        cin >> b.points[i].x >> b.points[i].y;

    int result = 0;
    for (int i = 0; i < k; i++)
    {
        Point p;
        cin >> p.x >> p.y;

        result += !(a.IsIn(p) && !b.IsIn(p));
    }
    
    if (result == 0)
        cout << "YES" << '\n';
    else
        cout << result << '\n';
}
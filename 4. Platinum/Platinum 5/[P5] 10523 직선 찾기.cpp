#include <iostream>
#include <vector>

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
};

bool HasPLine(int p, vector<Point>& points)
{
    int n = points.size();

    for (int it = 0; it < 1'000; it++)
    {
        int i0 = rand() % n;
        int i1 = rand() % n;
        if (i0 == i1) i1 = (i1 + 1) % n;

        int cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += (Point::CCW(points[i0], points[i1], points[i]) == 0);

        if (cnt * 100 >= n * p)
            return true;
    }
    return false;
}

int main()
{
    FastIO;

    int n, p;
    cin >> n >> p;

    vector<Point> points(n);
    for (auto& [x, y] : points)
        cin >> x >> y;

    bool result = HasPLine(p, points);
    cout << (result ? "possible" : "impossible") << '\n';
}
#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int ITER = 20;

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

bool CanShot(int i0, int i1, vector<Point>& points)
{
    int n = points.size();

    vector<int> remain;
    remain.reserve(n);
    for (int i = 0; i < n; i++)
    {
        if (Point::CCW(points[i0], points[i1], points[i]) != 0)
            remain.push_back(i);
    }

    int m = remain.size();
    for (int i = 0; i < m - 2; i++)
    {
        Point& a = points[remain[i]];
        Point& b = points[remain[i + 1]];
        Point& c = points[remain[i + 2]];

        if (Point::CCW(a, b, c) != 0)
            return false;
    }
    return true;
}

bool Can2Shot(vector<Point>& points)
{
    int n = points.size();
    if (n <= 3) return true;

    for (int it = 0; it < ITER; it++)
    {
        int i = rand() % n;
        int j = rand() % n;
        if (i == j) j = (j + 1) % n;

        if (CanShot(i, j, points))
            return true;
    }
    return false;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Point> points(n);
    for (auto& [x, y] : points)
        cin >> x >> y;

    bool result = Can2Shot(points);
    cout << (result ? "success" : "failure") << '\n';
}
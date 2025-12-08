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
        return (ccw > 0) - (ccw < 0);
    }
};

void MakeHull(vector<Point>& points, vector<int>& indices) {
    Point p0 = *min_element(points.begin(), points.end(),
        [](const Point& a, const Point& b) {
            if (a.y != b.y) return a.y < b.y;
            return a.x < b.x;
        }
    );
    sort(points.begin(), points.end(),
        [&p0](const Point& a, const Point& b) {
            long long ccw = Point::CCW(p0, a, b);
            if (ccw != 0) return ccw > 0;
            if (a.y != b.y) return a.y < b.y;
            return a.x < b.x;
        }
    );

    int n = points.size();
    for (int c = 0; c < n; c++) {
        while (indices.size() >= 2) {
            int b = indices[indices.size() - 1];
            int a = indices[indices.size() - 2];

            if (Point::CCW(points[a], points[b], points[c]) > 0)
                break;
            indices.pop_back();
        }
        indices.push_back(c);
    }
}

double Area(vector<Point>& points)
{
    int n = points.size();
    long long result = 0;
    for (int i = 0; i < n; i++)
    {
        Point& p0 = points[i];
        Point& p1 = points[(i + 1) % n];
        result += 1LL * p0.x * p1.y - 1LL * p0.y * p1.x;
    }
    return abs(result) / 2.;
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<Point> points(n);
    for (auto& [x, y] : points)
        cin >> x >> y;

    vector<int> idx;
    MakeHull(points, idx);

    int h = idx.size();
    vector<Point> hull(h);
    for (int i = 0; i < h; i++)
        hull[i] = points[idx[i]];

    if (h <= k)
        printf("%.1lf\n", Area(hull));
    else
    {

    }
}
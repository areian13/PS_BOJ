#include <iostream>
#include <cstdio>
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

long long Area(int i, int j, int k, vector<Point>& points)
{
    Point& a = points[i], & b = points[j], & c = points[k];
    long long result = 1LL * (b.x - a.x) * (c.y - a.y)
        - 1LL * (b.y - a.y) * (c.x - a.x);
    return abs(result);
}
long long Area(vector<Point>& points)
{
    int n = points.size();
    long long result = 0;
    for (int i = 0; i < n; i++)
    {
        Point& a = points[i];
        Point& b = points[(i + 1) % n];
        result += 1LL * a.x * b.y - 1LL * a.y * b.x;
    }
    return abs(result);
}

double MaxKPoly(int k, vector<Point>& points)
{
    vector<int> indices;
    MakeHull(points, indices);

    int h = indices.size();
    vector<Point> hull(h);
    for (int i = 0; i < h; i++)
        hull[i] = points[indices[i]];

    if (h <= k)
        return Area(hull) / 2.;

    long long result = 0;
    for (int i = 0; i < h; i++)
    {
        vector dp(h, vector(k + 1, 0LL));
        for (int j = i + 2; j < h; j++)
        {
            for (int t = 3; t <= k; t++)
            {
                for (int l = i + 1; l < j; l++)
                    dp[j][t] = max(dp[j][t], dp[l][t - 1] + Area(i, l, j, hull));
            }
            result = max(result, dp[j][k]);
        }
    }
    return result / 2.;
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<Point> points(n);
    for (auto& [x, y] : points)
        cin >> x >> y;

    double result = MaxKPoly(k, points);
    printf("%.1lf\n", result);
}
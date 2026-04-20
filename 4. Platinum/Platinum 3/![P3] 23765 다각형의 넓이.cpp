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
double Area(vector<int>& idx, vector<Point>& points)
{
    int n = idx.size();
    long long result = 0;
    for (int i = 0; i < n; i++)
    {
        Point& p0 = points[idx[i]];
        Point& p1 = points[idx[(i + 1) % n]];
        result += 1LL * p0.x * p1.y - 1LL * p0.y * p1.x;
    }
    return abs(result) / 2.;
}

double KPoly(int k, int d, vector<int>& idx, vector<Point>& hull,
    vector<vector<double>>& dp)
{
    if (dp[k][d] != -1) return dp[k][d];
    if (k == 0) return Area(idx, hull);

    int h = hull.size();
    dp[k][d] = 0;
    for (int i = d + 1; i < h; i++)
    {
        idx[k - 1] = i;
        dp[k][d] = max(dp[k][d], KPoly(k - 1, i, idx, hull, dp));
    }
    return dp[k][d];
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
        return Area(hull);

    double result = 0;
    vector dp(k, vector(h, vector(h, -1.)));
    vector<int> idx(k);
    for (int i = 0; i < h; i++)
    {
        idx[k - 1] = i;
        result = max(result, KPoly(k - 1, i, idx, hull, dp));
    }
    return result;
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
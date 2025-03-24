#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>
#include <cfloat>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define INF DBL_MAX

struct Point
{
    int x, y;

    static long long Cross(const Point& a, const Point& b, const Point& c)
    {
        return (long long)(b.x - a.x) * (c.y - a.y)
            - (long long)(b.y - a.y) * (c.x - a.x);
    }
    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        long long cross = Cross(a, b, c);
        return (cross == 0 ? 0 : (cross > 0 ? +1 : -1));
    }

    friend Point operator - (const Point& a, const Point& b)
    {
        return { a.x - b.x,a.y - b.y };
    }
    friend long long operator * (const Point& a, const Point& b)
    {
        return (long long)a.x * b.x + (long long)a.y * b.y;
    }
    friend long long operator / (const Point& a, const Point& b)
    {
        return (long long)a.x * b.y - (long long)a.y * b.x;
    }
    friend bool operator == (const Point& a, const Point& b)
    {
        return a.x == b.x && a.y == b.y;
    }
    double Mag()
    {
        return hypot(x, y);
    }
};

void MakeConvexHull(vector<Point>& points, vector<int>& indices)
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
        while (indices.size() >= 2)
        {
            int second = indices.back();
            indices.pop_back();
            int first = indices.back();

            if (Point::CCW(points[first], points[second], points[i]) > 0)
            {
                indices.push_back(second);
                break;
            }
        }

        indices.push_back(i);
    }

    if (indices.size() == 2 && points[indices[0]] == points[indices[1]])
        indices.pop_back();
    indices.shrink_to_fit();
}

double GetMABR(vector<Point>& points)
{
    vector<int> indices;
    MakeConvexHull(points, indices);

    int h = indices.size();
    if (h <= 1)
        return 0;

    vector<Point> hull(h);
    for (int i = 0; i < h; i++)
        hull[i] = points[indices[i]];

    Point U0 = hull[1] - hull[0];
    int r = 0, u = 0, l = 0;
    double result = INF;
    for (int i = 0; i < h; i++)
    {
        U0 = hull[(i + 1) % h] - hull[i];
        while (U0 * (hull[(r + 1) % h] - hull[r % h]) > 0)
            r++;
        u = max(u, r);
        while (U0 / (hull[(u + 1) % h] - hull[u % h]) > 0)
            u++;
        l = max(l, u);
        while (U0 * (hull[(l + 1) % h] - hull[l % h]) < 0)
            l++;

        double width = U0 * (hull[r % h] - hull[l % h]) / U0.Mag();
        double height = U0 / (hull[u % h] - hull[i % h]) / U0.Mag();
        result = min(result, width * height);
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Point> points(n);
    for (auto& [x, y] : points)
        cin >> x >> y;

    double result = GetMABR(points);
    cout << (long long)(result + .5) << '\n';
}
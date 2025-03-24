#include <iostream>
#include <bit>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y;

    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        long long ccw = (long long)(b.x - a.x) * (c.y - a.y)
            - (long long)(b.y - a.y) * (c.x - a.x);
        return (ccw == 0 ? 0 : (ccw > 0 ? +1 : -1));
    }
    friend bool operator == (const Point& a, const Point& b)
    {
        return a.x == b.x && a.y == b.y;
    }
};

struct Poly
{
    int n;
    vector<Point> hull;

    Poly(int n) : n(n)
    {
        hull.resize(n);
    }
    bool IsIn(const Point& p)
    {
        if (n < 3)
            return false;
        if (Point::CCW(hull[0], hull[1], p) < 0)
            return false;
        if (Point::CCW(hull[0], hull[n - 1], p) > 0)
            return false;

        int start = 1, end = n - 1;
        while (start + 1 < end)
        {
            int mid = (start + end) / 2;

            if (Point::CCW(hull[0], hull[mid], p) > 0)
                start = mid;
            else
                end = mid;
        }

        return Point::CCW(hull[start], hull[end], p) >= 0;
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
                return ccw > 0;
            if (a.y != b.y)
                return a.y < b.y;
            return a.x < b.x;
        }
    );

    int n = points.size();
    for (int c = 0; c < n; c++)
    {
        while (indices.size() >= 2)
        {
            int b = indices[indices.size() - 2];
            int a = indices[indices.size() - 1];

            if (Point::CCW(points[a], points[b], points[c]) < 0)
                break;
            indices.pop_back();
        }
        indices.push_back(c);
    }

    if (indices.size() == 2 && points[indices[0]] == points[indices[1]])
        indices.pop_back();
}

void GetHulls(vector<Point>& points, vector<Poly>& hulls)
{
    while (points.size() >= 3)
    {
        vector<int> indices;
        MakeConvexHull(points, indices);

        int h = indices.size();
        Poly poly(h);
        for (int i = 0; i < h; i++)
            poly.hull[i] = points[indices[i]];
        for (int i = h - 1; i >= 0; i--)
            points.erase(points.begin() + indices[i]);
        hulls.push_back(poly);
    }
}

int Score(const Point& p, vector<Poly>& hulls)
{
    int s = 0, e = hulls.size() - 1;
    while (s <= e)
    {
        int m = (s + e) / 2;

        if (hulls[m].IsIn(p))
            s = m + 1;
        else
            e = m - 1;
    }
    return s;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Point> points(n);
    for (auto& [x, y] : points)
        cin >> x >> y;

    vector<Poly> hulls;
    GetHulls(points, hulls);

    int q;
    cin >> q;

    for (int t = 1; t <= q; t++)
    {
        Point p;
        cin >> p.x >> p.y;

        int result = Score(p, hulls);
        cout << result << '\n';
    }
}
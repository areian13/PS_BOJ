#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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
struct Line
{
    Point a, b;

    static bool OnLine(const Line& l, const Point& p)
    {
        return Point::CCW(l.a, l.b, p) == 0
            && min(l.a.x, l.b.x) <= p.x && p.x <= max(l.a.x, l.b.x)
            && min(l.a.y, l.b.y) <= p.y && p.y <= max(l.a.y, l.b.y);
    }
    static bool IsCross(const Line& l0, const Line& l1, bool bound = true)
    {
        auto& [a, b] = l0;
        auto& [c, d] = l1;

        int ab_cd = Point::CCW(a, b, c) * Point::CCW(a, b, d);
        int cd_ab = Point::CCW(c, d, a) * Point::CCW(c, d, b);

        if (ab_cd < 0 && cd_ab < 0)
            return true;
        if (!bound) return false;
        return OnLine(l0, c) || OnLine(l0, d)
            || OnLine(l1, a) || OnLine(l1, b);
    }
};

void MakeHull(vector<Point>& points, vector<int>& indices) {
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
    for (int c = 0; c < n; c++)
    {
        while (indices.size() >= 2)
        {
            int b = indices[indices.size() - 1];
            int a = indices[indices.size() - 2];

            if (Point::CCW(points[a], points[b], points[c]) > 0)
                break;
            indices.pop_back();
        }
        indices.push_back(c);
    }
}

bool IsIn(const Point& p, vector<Point>& hull)
{
    int n = hull.size();
    if (n < 3)
        return false;
    if (Point::CCW(hull[0], hull[1], p) <= 0)
        return false;
    if (Point::CCW(hull[0], hull[n - 1], p) >= 0)
        return false;

    int start = 1, end = n - 1;
    while (start + 1 < end) {
        int mid = (start + end) / 2;

        if (Point::CCW(hull[0], hull[mid], p) > 0)
            start = mid;
        else
            end = mid;
    }
    return Point::CCW(hull[start], hull[end], p) > 0;
}

void Insert(Point& p, vector<Point>& hull)
{
    int h = hull.size();
    if (find(hull.begin(), hull.end(), p) != hull.end())
        return;

    for (int i = 0; i < h; i++)
    {
        Line l = { hull[i], hull[(i + 1) % h] };
        if (Line::OnLine(l, p))
        {
            hull.insert(hull.begin() + i + 1, p);
            return;
        }
    }
    return;
}

double MinDist(Point& s, Point& t, vector<Point>& points)
{
    vector<int> indices;
    MakeHull(points, indices);

    int h = indices.size();
    vector<Point> hull(h);
    for (int i = 0; i < h; i++)
        hull[i] = points[indices[i]];

    if (IsIn(s, hull) || IsIn(t, hull))
        return -1;

    hull.push_back(s);
    hull.push_back(t);

    indices.resize(0);
    MakeHull(hull, indices);

    int k = indices.size();
    vector<Point> phull(k);
    for (int i = 0; i < k; i++)
        phull[i] = hull[indices[i]];

    int si = find(phull.begin(), phull.end(), s) - phull.begin();
    int ti = find(phull.begin(), phull.end(), t) - phull.begin();

    if ((si == k) ^ (ti == k))
        return Point::Dist(s, t);

    Insert(s, phull);
    Insert(t, phull);
    k = phull.size();

    si = find(phull.begin(), phull.end(), s) - phull.begin();
    ti = find(phull.begin(), phull.end(), t) - phull.begin();

    double rd = 0;
    for (int i = si; i != ti; i = (i + 1) % k)
        rd += Point::Dist(phull[i], phull[(i + 1) % k]);
    double ld = 0;
    for (int i = si; i != ti; i = (i - 1 + k) % k)
        ld += Point::Dist(phull[i], phull[(i - 1 + k) % k]);

    return min(rd, ld);
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
            printf("%.6lf\n", result);
    }
}
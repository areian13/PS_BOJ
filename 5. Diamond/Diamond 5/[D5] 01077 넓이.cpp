#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    double x, y;

    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        double ccw = (b.x - a.x) * (c.y - a.y)
            - (b.y - a.y) * (c.x - a.x);
        return (ccw == 0 ? 0 : ccw > 0 ? +1 : -1);
    }

    friend bool operator == (const Point& a, const Point& b)
    {
        return a.x == b.x && a.y == b.y;
    }
};
struct Line
{
    Point a, b;

    static bool OnSegment(const Line& l, const Point& p)
    {
        auto& [a, b] = l;
        if (Point::CCW(a, b, p) != 0)
            return false;
        return min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x)
            && min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
    }
    static vector<Point> GetIntersections(const Line& l0, const Line& l1)
    {
        auto& [a, b] = l0;
        auto& [c, d] = l1;

        int ab_c = Point::CCW(a, b, c);
        int ab_d = Point::CCW(a, b, d);
        int cd_a = Point::CCW(c, d, a);
        int cd_b = Point::CCW(c, d, b);

        if (ab_c * ab_d < 0 && cd_a * cd_b < 0)
        {
            double a1 = b.y - a.y;
            double b1 = a.x - b.x;
            double c1 = a1 * a.x + b1 * a.y;

            double a2 = d.y - c.y;
            double b2 = c.x - d.x;
            double c2 = a2 * c.x + b2 * c.y;

            double d = a1 * b2 - a2 * b1;
            double x = (b2 * c1 - b1 * c2) / d;
            double y = (a1 * c2 - a2 * c1) / d;

            return vector<Point>{{ x, y }};
        }

        vector<Point> intersections;
        if (OnSegment(l0, c)) intersections.push_back(c);
        if (OnSegment(l0, d)) intersections.push_back(d);
        if (OnSegment(l1, a)) intersections.push_back(a);
        if (OnSegment(l1, b)) intersections.push_back(b);

        if (intersections.size() == 2 && intersections[0] == intersections[1])
            return vector<Point>{intersections[0]};
        return intersections;
    }
};
struct Poly
{
    int n;
    vector<Point> hull;

    Poly() {}
    Poly(int n) : n(n) { hull.resize(n); }
    Poly(vector<Point>& hull) : hull(hull), n(hull.size()) {}

    double Area()
    {
        double result = 0;
        for (int i = 0; i < n; i++)
        {
            result += hull[i].x * hull[(i + 1) % n].y;
            result -= hull[i].y * hull[(i + 1) % n].x;
        }
        return abs(result) / 2;
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
    int n = points.size();
    if (n <= 1)
        return;

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

Poly Overlap(Poly& a, Poly& b)
{
    vector<Point> c;
    for (int i = 0; i < a.n; i++)
    {
        if (b.IsIn(a.hull[i]))
            c.push_back(a.hull[i]);

        Line l0 = { a.hull[i],a.hull[(i + 1) % a.n] };
        for (int j = 0; j < b.n; j++)
        {
            Line l1 = { b.hull[j],b.hull[(j + 1) % b.n] };
            vector<Point> intersections = Line::GetIntersections(l0, l1);
            if (intersections.size() == 1)
                c.push_back(intersections[0]);
        }
    }
    for (int i = 0; i < b.n; i++)
    {
        if (a.IsIn(b.hull[i]))
            c.push_back(b.hull[i]);
    }

    vector<int> indices;
    MakeConvexHull(c, indices);

    int h = indices.size();
    vector<Point> result(h);
    for (int i = 0; i < h; i++)
        result[i] = c[indices[i]];
    return Poly(result);
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    Poly a(n), b(m);
    for (auto& [x, y] : a.hull)
        cin >> x >> y;
    for (auto& [x, y] : b.hull)
        cin >> x >> y;

    Poly result = Overlap(a, b);
    printf("%.9lf\n", result.Area());
}
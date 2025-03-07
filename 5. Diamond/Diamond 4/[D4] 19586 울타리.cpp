#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    double x, y;

    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        double cross = (b.x - a.x) * (c.y - a.y)
            - (b.y - a.y) * (c.x - a.x);
        return (cross == 0 ? 0 : (cross > 0 ? +1 : -1));
    }
    static Point Perp(const Point& p)
    {
        return { p.y,-p.x };
    }
    static double Dot(const Point& a, const Point& b)
    {
        return a.x * b.x + a.y * b.y;
    }

    friend Point operator-(const Point& a, const Point& b)
    {
        return { a.x - b.x,a.y - b.y };
    }
    friend Point operator-(const Point& a)
    {
        return { -a.x,-a.y };
    }
    friend Point operator*(const Point& a, float c)
    {
        return { a.x * c,a.y * c };
    }
    friend bool operator==(const Point& a, const Point& b)
    {
        return a.x == b.x && a.y == b.y;
    }
};

struct Box
{
    array<Point, 2> U;
    array<int, 4> indices;
    double U0Len, width, height;

    Box()
    {
        U = { Point{0,0},{0,0} };
        indices = { 0,0,0,0 };
        U0Len = width = height = 0;
    }
};

void MakeConvexHull(vector<Point>& points, vector<int>& hullIndices)
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
        while (hullIndices.size() >= 2)
        {
            int second = hullIndices.back();
            hullIndices.pop_back();
            int first = hullIndices.back();

            if (Point::CCW(points[first], points[second], points[i]) > 0)
            {
                hullIndices.push_back(second);
                break;
            }
        }

        hullIndices.push_back(i);
    }

    if (hullIndices.size() == 2 && points[hullIndices[0]] == points[hullIndices[1]])
        hullIndices.pop_back();
}

Box SmallestBox(int i0, int i1, vector<Point>& hull)
{
    Box box;
    box.U[0] = hull[i1] - hull[i0];
    box.U[1] = -Point::Perp(box.U[0]);
    box.U0Len = sqrt(Point::Dot(box.U[0], box.U[0]));
    box.indices = { i1,i1,i1,i1 };

    Point& origin = hull[i1];
    vector<Point> support(4, { 0,0 });

    int n = hull.size();
    for (int i = 0; i < n; i++)
    {
        Point diff = hull[i] - origin;
        Point v = { Point::Dot(box.U[0], diff),Point::Dot(box.U[1], diff) };

        if (v.x > support[1].x ||
            (v.x == support[1].x && v.y > support[1].y))
        {
            box.indices[1] = i;
            support[1] = v;
        }
        if (v.y > support[2].y ||
            (v.y == support[2].y && v.x < support[2].x))
        {
            box.indices[2] = i;
            support[2] = v;
        }
        if (v.x < support[3].x ||
            (v.x == support[3].x && v.y < support[3].y))
        {
            box.indices[3] = i;
            support[3] = v;
        }
    }

    box.width = (support[1].x - support[3].x) / box.U0Len;
    box.height = support[2].y / box.U0Len;
    return box;
}
void ComputeAngles(Box& box, vector<pair<double, int>>& angles, vector<Point>& hull)
{
    int n = hull.size();
    for (int i0 = 3, i1 = 0; i1 < 4; i0 = i1++)
    {
        if (box.indices[i0] == box.indices[i1])
            continue;

        Point D = box.U[i0 % 2] * (i0 < 2 ? +1 : -1);
        int j0 = box.indices[i0], j1 = (j0 + 1) % n;

        Point E = hull[j1] - hull[j0];
        double dp = Point::Dot(D, Point::Perp(E));
        double eSqrLen = Point::Dot(E, E);
        double sinThetaSqr = (dp * dp) / eSqrLen;
        angles.push_back({ sinThetaSqr,i0 });
    }
}
void UpdateSupport(Box& box, vector<pair<double, int>>& angles,
    vector<Point>& hull)
{
    int n = hull.size();

    int minAngleIndex = min_element(angles.begin(), angles.end(),
        [](const auto& a, const auto& b) {
            return a.first < b.first;
        }
    )->second;
    box.indices[minAngleIndex] = (box.indices[minAngleIndex] + 1) % n;

    array<int, 4> nextIndices;
    for (int i = 0; i < 4; i++)
        nextIndices[i] = box.indices[(minAngleIndex + i) % 4];
    box.indices = nextIndices;

    int j1 = box.indices[0], j0 = (j1 - 1 + n) % n;
    box.U[0] = hull[j1] - hull[j0];
    box.U[1] = -Point::Perp(box.U[0]);

    box.U0Len = sqrt(Point::Dot(box.U[0], box.U[0]));
    box.width = Point::Dot(box.U[0], hull[box.indices[1]] - hull[box.indices[3]]) / box.U0Len;
    box.height = Point::Dot(box.U[1], hull[box.indices[2]] - hull[box.indices[0]]) / box.U0Len;
}
Box GetMABR(vector<Point>& points)
{
    vector<int> hullIndices;
    MakeConvexHull(points, hullIndices);

    int h = hullIndices.size();
    if (h <= 1)
        return Box();

    vector<Point> hull(h);
    for (int i = 0; i < h; i++)
        hull[i] = points[hullIndices[i]];

    Box minBox = SmallestBox(h - 1, 0, hull);
    Box box = minBox;
    for (int i = 0; i < h; i++)
    {
        vector<pair<double, int>> angles;
        ComputeAngles(box, angles, hull);
        UpdateSupport(box, angles, hull);

        if (box.width + box.height < minBox.width + minBox.height)
            minBox = box;
    }
    return minBox;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Point> points(n);
    for (auto& [x, y] : points)
        cin >> x >> y;

    Box result = GetMABR(points);
    printf("%.9lf\n", (result.width + result.height) * 2);
}
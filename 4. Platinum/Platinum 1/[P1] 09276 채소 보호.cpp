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

    static int CCW(Point a, Point b, Point c)
    {
        int cross = (b.x - a.x) * (c.y - a.y)
            - (b.y - a.y) * (c.x - a.x);
        return (cross == 0 ? 0 : (cross > 0 ? +1 : -1));
    }
    static Point Perp(Point p)
    {
        return { p.y,-p.x };
    }
    static double Dot(Point a, Point b)
    {
        return a.x * b.x + a.y * b.y;
    }

    friend Point operator-(Point a, Point b)
    {
        return { a.x - b.x,a.y - b.y };
    }
    friend Point operator-(Point a)
    {
        return { -a.x,-a.y };
    }
    friend Point operator*(Point a, float c)
    {
        return { a.x * c,a.y * c };
    }
};

struct Box
{
    array<Point, 2> U;
    array<int, 4> indices;
    double sqrLenU0, area, width, height;

    Box()
    {
        U = { Point{0,0},{0,0} };
        indices = { 0,0,0,0 };
        sqrLenU0 = area = width = height = 0;
    }
};

void MakeConvexHull(vector<Point>& points, vector<int>& hullIndices)
{
    Point p0 = *min_element(points.begin(), points.end(),
        [](Point& a, Point& b)
        {
            if (a.y != b.y)
                return a.y < b.y;
            return a.x < b.x;
        }
    );
    sort(points.begin(), points.end(),
        [&p0](Point& a, Point& b)
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
}

Box SmallestBox(int i0, int i1, vector<Point>& points)
{
    Box box;
    box.U[0] = points[i1] - points[i0];
    box.U[1] = -Point::Perp(box.U[0]);
    box.indices = { i1,i1,i1,i1 };
    box.sqrLenU0 = Point::Dot(box.U[0], box.U[0]);

    Point& origin = points[i1];
    vector<Point> support(4, { 0,0 });

    int n = points.size();
    for (int i = 0; i < n; i++)
    {
        Point diff = points[i] - origin;
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

    double width = support[1].x - support[3].x;
    double height = support[2].y;
    box.width = width;
    box.height = height;
    box.area = width * height / box.sqrLenU0;
    return box;
}
void ComputeAngles(Box& box, vector<pair<double, int>>& angles, vector<Point>& points)
{
    int n = points.size();
    for (int i0 = 3, i1 = 0; i1 < 4; i0 = i1++)
    {
        if (box.indices[i0] == box.indices[i1])
            continue;

        Point D = box.U[i0 % 2] * (i0 < 2 ? +1 : -1);
        int j0 = box.indices[i0], j1 = (j0 + 1) % n;

        Point E = points[j1] - points[j0];
        double dp = Point::Dot(D, Point::Perp(E));
        double eSqrLen = Point::Dot(E, E);
        double sinThetaSqr = (dp * dp) / eSqrLen;
        angles.push_back({ sinThetaSqr,i0 });
    }
}
bool UpdateSupport(Box& box, vector<pair<double, int>>& angles,
    vector<Point>& points, vector<bool>& isVisited)
{
    int n = points.size();
    int k = angles.size();

    vector<int> sortIndices(k);
    for (int i = 0; i < k; i++)
        sortIndices[i] = i;
    sort(sortIndices.begin(), sortIndices.end(),
        [&angles](int a, int b)
        {
            return angles[a].first < angles[b].first;
        }
    );

    auto& minAngle = angles[sortIndices[0]];
    for (int i = 0; i < k; i++)
    {
        auto& angle = angles[sortIndices[i]];
        if (angle.first == minAngle.first)
            box.indices[angle.second] = (box.indices[angle.second] + 1) % n;
    }

    int bottom = box.indices[minAngle.second];
    if (isVisited[bottom])
        return false;
    isVisited[bottom] = true;

    array<int, 4> nextIndices;
    for (int i = 0; i < 4; i++)
        nextIndices[i] = box.indices[(minAngle.second + i) % 4];
    box.indices = nextIndices;

    int j1 = box.indices[0], j0 = (j1 - 1 + n) % n;
    box.U[0] = points[j1] - points[j0];
    box.U[1] = -Point::Perp(box.U[0]);
    box.sqrLenU0 = Point::Dot(box.U[0], box.U[0]);

    array<Point, 2> diff =
    {
        points[box.indices[1]] - points[box.indices[3]],
        points[box.indices[2]] - points[box.indices[0]],
    };
    double width = Point::Dot(box.U[0], diff[0]);
    double height = Point::Dot(box.U[1], diff[1]);
    box.width = width;
    box.height = height;
    box.area = width * height / box.sqrLenU0;
    return true;
}
Box GetMBR(vector<Point>& points)
{
    vector<int> hullIndices;
    MakeConvexHull(points, hullIndices);

    int h = hullIndices.size();
    vector<Point> hull(h);
    for (int i = 0; i < h; i++)
        hull[i] = points[hullIndices[i]];

    vector<bool> isVisited(h, false);
    Box minBox = SmallestBox(h - 1, 0, hull);
    isVisited[minBox.indices[0]] = true;

    Box box = minBox;
    for (int i = 0; i < h; i++)
    {
        vector<pair<double, int>> angles;
        ComputeAngles(box, angles, hull);

        if (angles.size() == 0)
            break;

        if (!UpdateSupport(box, angles, hull, isVisited))
            break;

        if (box.area < minBox.area)
            minBox = box;
    }
    return minBox;
}

int main()
{
    FastIO;

    while (true)
    {
        int n;
        cin >> n;

        if (cin.eof())
            break;

        vector<Point> points(n);
        for (int i = 0; i < n; i++)
            cin >> points[i].x >> points[i].y;

        Box result = GetMBR(points);
        printf("%.9lf\n", (result.width + result.height) * 2 / sqrt(result.sqrLenU0));
    }
}
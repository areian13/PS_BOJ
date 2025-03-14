#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    long long x, y;

    static long long CCW(const Point& a, const Point& b, const Point& c)
    {
        long long ccw = (b.x - a.x) * (c.y - a.y)
            - (b.y - a.y) * (c.x - a.x);
        return (ccw == 0 ? 0 : (ccw > 0 ? +1 : -1));
    }
    friend Point operator-(const Point& a, const Point& b)
    {
        return { a.x - b.x,a.y - b.y };
    }
    friend bool operator==(const Point& a, const Point& b)
    {
        return a.x == b.x && a.y == b.y;
    }
};

long long SqrDist(const Point& a, const Point& b)
{
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    return dx * dx + dy * dy;
}

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
            long long ccw = Point::CCW(p0, a, b);
            if (ccw != 0)
                return ccw > 0;
            if (a.y != b.y)
                return a.y < b.y;
            return a.x < b.x;
        }
    );

    int n = points.size();
    for (int third = 0; third < n; third++)
    {
        while (indices.size() > 2)
        {
            int second = indices.back();
            indices.pop_back();
            int first = indices.back();

            if (Point::CCW(points[first], points[second], points[third]) > 0)
            {
                indices.push_back(second);
                break;
            }
        }
        indices.push_back(third);
    }

    if (indices.size() == 2 && points[indices[0]] == points[indices[1]])
        indices.pop_back();
}

pair<Point, Point> GetPolyDia(vector<Point>& points)
{
    vector<int> indices;
    MakeConvexHull(points, indices);

    int h = indices.size();
    vector<Point> hull(h);
    for (int i = 0; i < h; i++)
        hull[i] = points[indices[i]];

    pair<Point, Point> result = { Point{0,0},{0,0} };
    if (h <= 1)
        return result;

    auto comp = [](const pair<Point, Point>& a, const pair<Point, Point>& b)
        {
            return SqrDist(a.first, a.second) < SqrDist(b.first, b.second);
        };
    for (int i = 0, j = 1; i < h; i++)
    {
        while (j + 1 < h &&
            Point::CCW(hull[i + 1] - hull[i], hull[j + 1] - hull[j], { 0,0 }) >= 0)
        {
            result = max(result, { hull[i], hull[j] }, comp);
            j++;
        }
        result = max(result, { hull[i], hull[j] }, comp);
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

    auto result = GetPolyDia(points);
    cout << SqrDist(result.first, result.second) << '\n';
}
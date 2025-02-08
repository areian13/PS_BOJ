#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y;

    static int DistSq(Point a, Point b)
    {
        int dx = a.x - b.x;
        int dy = a.y - b.y;
        return dx * dx + dy * dy;
    }
    static int CCW(Point a, Point b, Point c)
    {
        int ccw = (b.x - a.x) * (c.y - a.y)
            - (b.y - a.y) * (c.x - a.x);
        return (ccw == 0 ? 0 : (ccw > 0 ? +1 : -1));
    }

    friend Point operator-(Point a, Point b)
    {
        return { a.x - b.x,a.y - b.y };
    }
};

void MakeConvexHull(vector<Point>& points, vector<int>& indices)
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
                return ccw > 0;
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
}

pair<Point, Point> GetDiaPoint(vector<Point>& points)
{
    vector<int> indices;
    MakeConvexHull(points, indices);

    int h = indices.size();
    vector<Point> hull(h);
    for (int i = 0; i < h; i++)
        hull[i] = points[indices[i]];

    pair<Point, Point> result = { {0,0},{0,0} };
    auto comp = [](pair<Point, Point> a, pair<Point, Point> b)
        {
            return Point::DistSq(a.first, a.second) < Point::DistSq(b.first, b.second);
        };
    for (int i = 0, j = 0; i < h; i++)
    {
        while (j + 1 < h
            && Point::CCW({ 0,0 }, hull[i + 1] - hull[i], hull[j + 1] - hull[j]) >= 0)
        {
            result = max(result, { hull[i],hull[j] }, comp);
            j++;
        }
        result = max(result, { hull[i],hull[j] }, comp);
    }
    return result;
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        vector<Point> points(n * 4);
        for (int i = 0; i < n; i++)
        {
            int x, y, w;
            cin >> x >> y >> w;

            points[i * 4 + 0] = { x,y };
            points[i * 4 + 1] = { x + w,y };
            points[i * 4 + 2] = { x,y + w };
            points[i * 4 + 3] = { x + w,y + w };
        }

        pair<Point, Point> result = GetDiaPoint(points);
        cout << Point::DistSq(result.first, result.second) << '\n';
    }
}
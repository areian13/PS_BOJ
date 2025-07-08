#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y, i;

    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        long long ccw = 1LL * (b.x - a.x) * (c.y - a.y)
            - 1LL * (b.y - a.y) * (c.x - a.x);
        return (ccw > 0) - (ccw < 0);
    }
    friend bool operator == (const Point& a, const Point& b)
    {
        return a.x == b.x && a.y == b.y;
    }
};

void MakeConvexHull(vector<Point>& points, vector<int>& indices)
{
    Point p0 = *min_element(points.begin(), points.end(),
        [](auto& a, auto& b)
        {
            if (a.y != b.y)
                return a.y < b.y;
            return a.x < b.x;
        }
    );
    sort(points.begin(), points.end(),
        [&p0](auto& a, auto& b)
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
    for (int k = 0; k < n; k++)
    {
        while (indices.size() > 2)
        {
            int j = indices.back();
            indices.pop_back();
            int i = indices.back();

            if (Point::CCW(points[i], points[j], points[k]) > 0)
            {
                indices.push_back(j);
                break;
            }
        }
        indices.push_back(k);
    }

    if (indices.size() == 2 && points[indices[0]] == points[indices[1]])
        indices.pop_back();
}

vector<int> MinRoute(int u, int v, vector<Point>& points)
{
    int n = points.size();

    for (int d : {+1, -1})
    {
        vector<Point> temp;
        for (int i = u; i != v; i = (i + d + n) % n)
            temp.push_back(points[i]);
        temp.push_back(points[v]);

        vector<int> indices;
        MakeConvexHull(temp, indices);

        int h = indices.size();
        vector<Point> hull(h);
        for (int i = 0; i < h; i++)
        {
            hull[i] = temp[indices[i]];
            cout << hull[i].i << ' ';
        }
        cout << '\n';

        /*sort(indices.begin(), indices.end(),
            [&points](const int i, const int j)
            {
                Point a = points[i], b = points[j];
                int ccw = Point::CCW(points[0], a, b);
                if (ccw != 0)
                    return ccw > 0;
                if (a.y != b.y)
                    return a.y < b.y;
                return a.x < b.x;
            }
        );*/
    }
    
    return {};
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        points[i] = { x,y,i };
    }

    int u, v;
    cin >> u >> v;

    vector<int> result = MinRoute(u, v, points);
    cout << result.size() << '\n';
    for (auto u : result)
        cout << u << ' ';
}
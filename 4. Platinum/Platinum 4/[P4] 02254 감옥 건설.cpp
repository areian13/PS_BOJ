#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y;

    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        long long ccw = (long long)(b.x - a.x) * (c.y - a.y) - (long long)(b.y - a.y) * (c.x - a.x);

        if (ccw > 0)
            return +1;
        if (ccw < 0)
            return -1;
        return 0;
    }
};

bool IsInner(Point& p, vector<Point>& points, stack<int> S)
{
    int start = S.top();
    int first = S.top();
    S.pop();
    int second = S.top();
    S.pop();

    int ccw = Point::CCW(points[first], points[second], p);
    while (!S.empty())
    {
        first = second;
        second = S.top();
        S.pop();

        if (ccw != Point::CCW(points[first], points[second], p))
            return false;
    }

    return (ccw == Point::CCW(points[second], points[start], p));
}

int MaxLayer(Point& p, vector<Point>& points)
{
    int result = 0;
    while (points.size() >= 3)
    {
        int n = points.size();

        auto comp =
            [](const Point& a, const Point& b)
            {
                if (a.y != b.y)
                    return a.y < b.y;
                return a.x < b.x;
            };

        Point zeroPoint = *min_element(points.begin(), points.end(), comp);
        sort(points.begin(), points.end(),
            [&zeroPoint](const Point& a, const Point& b)
            {
                long long ap = a.x - zeroPoint.x;
                long long aq = a.y - zeroPoint.y;
                long long bp = b.x - zeroPoint.x;
                long long bq = b.y - zeroPoint.y;

                if (aq * bp != ap * bq)
                    return aq * bp < ap * bq;
                if (a.y != b.y)
                    return a.y < b.y;
                return a.x < b.x;
            }
        );

        stack<int> S;
        S.push(0);
        S.push(1);

        int next = 2;
        while (next < n)
        {
            while (S.size() >= 2)
            {
                int second = S.top();
                S.pop();
                int first = S.top();

                if (Point::CCW(points[first], points[second], points[next]) > 0)
                {
                    S.push(second);
                    break;
                }
            }

            S.push(next);
            next++;
        }

        if (!IsInner(p, points, S))
            break;

        result++;
        while (!S.empty())
        {
            points.erase(points.begin() + S.top());
            S.pop();
        }
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    Point p;
    cin >> n >> p.x >> p.y;

    vector<Point> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    int result = MaxLayer(p, points);
    cout << result << '\n';
}
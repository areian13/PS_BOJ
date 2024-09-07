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

bool IsInner(Point& p, vector<int>& S, vector<Point>& points)
{
    int k = S.size();
    int ccw = Point::CCW(points[S[k - 1]], points[S[0]], p);
    for (int i = 0; i < k - 1; i++)
    {
        if (Point::CCW(points[S[i]], points[S[i + 1]], p) != ccw)
            return false;
    }
    return true;
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

        vector<int> S;
        S.push_back(0);
        S.push_back(1);

        int next = 2;
        while (next < n)
        {
            while (S.size() >= 2)
            {
                int second = S.back();
                S.pop_back();
                int first = S.back();

                if (Point::CCW(points[first], points[second], points[next]) > 0)
                {
                    S.push_back(second);
                    break;
                }
            }

            S.push_back(next);
            next++;
        }

        if (!IsInner(p, S, points))
            break;

        result++;
        while (!S.empty())
        {
            points.erase(points.begin() + S.back());
            S.pop_back();
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
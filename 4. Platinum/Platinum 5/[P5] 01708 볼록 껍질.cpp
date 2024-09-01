#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y;

    static long long CCW(const Point& a, const Point& b, const Point& c)
    {
        return (long long)(b.x - a.x) * (c.y - a.y) - (long long)(b.y - a.y) * (c.x - a.x);
    }
};

int ConvexHull(vector<Point>& points)
{
    int n = points.size();

    auto comp = [](const Point& a, const Point& b)
        {
            if (a.y != b.y)
                return a.y < b.y;
            return a.x < b.x;
        };

    Point zeroPoint = *min_element(points.begin(), points.end(), comp);
    sort(points.begin(), points.end(),
        [&zeroPoint, &comp](const Point& a, const Point& b)
        {
            long long ap = a.x - zeroPoint.x;
            long long aq = a.y - zeroPoint.y;
            long long bp = b.x - zeroPoint.x;
            long long bq = b.y - zeroPoint.y;

            if (aq * bp != ap * bq)
                return aq * bp < ap * bq;
            return comp(a, b);
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
            int first = S.top();
            S.pop();
            int second = S.top();

            if (Point::CCW(points[second], points[first], points[next]) > 0)
            {
                S.push(first);
                break;
            }
        }

        S.push(next);
        next++;
    }

    return S.size();
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    int result = ConvexHull(points);
    cout << result << '\n';
}
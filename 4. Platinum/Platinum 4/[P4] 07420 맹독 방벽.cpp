#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define PI 3.14159265359

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
    static double Dist(const Point& a, const Point& b)
    {
        double dx = a.x - b.x;
        double dy = a.y - b.y;

        return sqrt(dx * dx + dy * dy);
    }
    static double GetTheta(const Point& a, const Point& b, const Point& c)
    {
        double ab = Point::Dist(a, b);
        double bc = Point::Dist(b, c);
        double ca = Point::Dist(c, a);

        return acos((ab * ab + bc * bc - ca * ca) / (ab * bc * 2));
    }
};

void MakeConvexHull(vector<Point>& points, vector<int>& convexHull)
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

    convexHull.push_back(0);
    convexHull.push_back(1);

    int next = 2;
    while (next < n)
    {
        while (convexHull.size() >= 2)
        {
            int second = convexHull.back();
            convexHull.pop_back();
            int first = convexHull.back();

            if (Point::CCW(points[first], points[second], points[next]) > 0)
            {
                convexHull.push_back(second);
                break;
            }
        }

        convexHull.push_back(next);
        next++;
    }
}

double PoisonBarrier(vector<Point>& points, int l)
{
    vector<int> convexHull;
    MakeConvexHull(points, convexHull);

    int s = convexHull.size();
    double result = 0;
    for (int i = 0; i < s; i++)
    {
        int j = (i + 1) % s;
        result += Point::Dist(points[convexHull[i]], points[convexHull[j]]);

        int k = (i + 2) % s;
        double t = Point::GetTheta(points[convexHull[i]], points[convexHull[j]], points[convexHull[k]]);
        result += (PI - t) * l;
    }
    return result;
}

int main()
{
    FastIO;

    int n, l;
    cin >> n >> l;

    vector<Point> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    double result = PoisonBarrier(points, l);
    cout << (int)(result + 0.5) << '\n';
}
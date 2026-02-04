#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cfloat>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const double INF = DBL_MAX;
const double EPS = 1e-9;
bool IsZero(double v) { return abs(v) < EPS; }

struct Point
{
    double x, y;

    static double Dist(const Point& a, const Point& b)
    {
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        return sqrt(dx * dx + dy * dy);
    }
};
struct Circle
{
    Point o;
    double r;

    Circle(vector<Point>& points)
    {
        int n = points.size();
        if (n == 0)
        {
            r = -1;
            return;
        }
        if (n == 1)
        {
            o = points[0];
            r = 0;
            return;
        }
        if (n == 2)
        {
            *this = Circle(points[0], points[1]);
            return;
        }
        if (n == 3)
        {
            *this = Circle(points[0], points[1], points[2]);
            for (int i = 0; i < 3; i++)
            {
                Circle c = Circle(points[i], points[(i + 1) % 3]);
                if (c.IsIn(points[(i + 2) % 3]) && this->r > c.r)
                    *this = c;
            }
            return;
        }

        vector<Point> hull;
        *this = MEC(n, points, hull);
    }
    Circle(const Point& a, const Point& b)
    {
        o.x = (a.x + b.x) / 2;
        o.y = (a.y + b.y) / 2;
        r = Point::Dist(a, b) / 2;
    }
    Circle(const Point& a, const Point& b, const Point& c)
    {
        double A = b.x - a.x;
        double B = b.y - a.y;
        double C = c.x - a.x;
        double D = c.y - a.y;
        double E = A * (a.x + b.x) + B * (a.y + b.y);
        double F = C * (a.x + c.x) + D * (a.y + c.y);
        double G = 2 * (A * (c.y - b.y) - B * (c.x - b.x));

        if (IsZero(G))
        {
            vector<Point> temp = { a,b,c };
            sort(temp.begin(), temp.end(),
                [](auto& a, auto& b)
                {
                    if (a.x != b.x)
                        return a.x < b.x;
                    return a.y < b.y;
                }
            );
            *this = Circle(temp[0], temp[2]);
            return;
        }

        o.x = (D * E - B * F) / G;
        o.y = (A * F - C * E) / G;
        r = Point::Dist(a, o);
    }

    static Circle MEC(int n, vector<Point>& points, vector<Point>& hull)
    {
        int h = hull.size();
        if (n == 0 || h == 3)
            return Circle(hull);

        Point p = points[n - 1];
        Circle result = MEC(n - 1, points, hull);
        if (result.IsIn(p))
            return result;

        hull.push_back(p);
        result = MEC(n - 1, points, hull);
        hull.pop_back();
        return result;
    }
    bool IsIn(const Point& p)
    {
        return Point::Dist(p, o) <= r + EPS;
    }
};

double TwoCenter(vector<Point>& points)
{
    int n = points.size();

    double result = INF;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            vector<Point> a, b;
            for (int k = 0; k < n; k++)
            {
                double di = Point::Dist(points[i], points[k]);
                double dj = Point::Dist(points[j], points[k]);
                (di < dj ? a : b).push_back(points[k]);
            }
            Circle ac(a), bc(b);
            result = min(result, max(ac.r, bc.r));
        }
    }
    return result;
}

int main()
{
    FastIO;

    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        vector<Point> points(n);
        for (auto& [x, y] : points)
            cin >> x >> y;

        double result = TwoCenter(points);
        printf("%.2lf\n", result);
    }
}
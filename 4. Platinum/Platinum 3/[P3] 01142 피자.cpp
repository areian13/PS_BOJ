#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;
const double EPS = 1e-7;
bool IsZero(double d) { return abs(d) < EPS; }
const double PI = acos(-1);

struct Point
{
    double x, y;

    friend Point operator + (const Point& a, const Point& b) { return { a.x + b.x,a.y + b.y }; }
    friend Point operator - (const Point& a, const Point& b) { return { a.x - b.x,a.y - b.y }; }
    friend Point operator * (const Point& p, double d) { return { p.x * d,p.y * d }; }

    static double dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }

    friend bool operator == (const Point& a, const Point& b) { return IsZero(a.x - b.x) && IsZero(a.y - b.y); }
};
struct Line
{
    Point a, b;

    Point getSymPoint(const Point& p)
    {
        Point v = b - a;
        if (IsZero(Point::dot(v, v)))
            return a * 2 - p;
        double t = Point::dot(p - a, v) / Point::dot(v, v);
        Point h = a + v * t;
        return h * 2 - p;
    }
};

bool CanCut(Point p, vector<Point>& points)
{
    p = p * 50'000;
    Line l = { p,p * -1 };

    for (auto& i : points)
    {
        Point sp = l.getSymPoint(i);
        bool has = false;
        for (auto& j : points)
            has |= (j == sp);
        if (!has)
            return false;
    }
    return true;
}

int CountCut(vector<Point>& points)
{
    int n = points.size();
    if (n == 0 || n == 1 && points[0] == Point{ 0,0 })
        return INF;

    auto comp = [](const double& a, const double& b)
        {
            if (IsZero(a - b)) return false;
            return a < b;
        };
    set<double, decltype(comp)> result(comp);
    for (int i = 0; i < n; i++)
    {
        if (points[i] == Point{ 0,0 })
            continue;
        for (int j = i; j < n; j++)
        {
            Point p = (points[i] + points[j]) * 0.5;
            if (p == Point{ 0,0 })
                p = { -points[i].y,points[i].x };
            if (CanCut(p, points))
            {
                double t = atan2(p.y, p.x);
                if (t < 0) t += PI;
                if (t >= PI) t -= PI;
                result.insert(t);
            }
        }
    }

    return result.size();
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Point> points(n);
    for (auto& [x, y] : points)
        cin >> x >> y;

    int result = CountCut(points);
    if (result == INF)
        cout << -1 << '\n';
    else
        cout << result << '\n';
}
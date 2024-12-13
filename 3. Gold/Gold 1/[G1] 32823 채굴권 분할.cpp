#include <iostream>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define PI 3.14159265359
#define L 1'000

struct Point
{
    double x, y;

    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        double ccw = (a.x * b.y + b.x * c.y + c.x * a.y)
            - (a.y * b.x + b.y * c.x + c.y * a.x);
        if (ccw == 0)
            return 0;
        return (ccw > 0 ? +1 : -1);
    }
};

struct Line
{
    Point a, b;

    static bool onSegment(const Point& c, const Line& l) {
        return min(l.a.x, l.b.x) <= c.x && c.x <= max(l.a.x, l.b.x)
            && min(l.a.y, l.b.y) <= c.y && c.y <= max(l.a.y, l.b.y);
    }
    static bool IsIntersecting(const Line& l1, const Line& l2)
    {
        int ab_c = Point::CCW(l1.a, l1.b, l2.a);
        int ab_d = Point::CCW(l1.a, l1.b, l2.b);
        int cd_a = Point::CCW(l2.a, l2.b, l1.a);
        int cd_b = Point::CCW(l2.a, l2.b, l1.b);

        if (ab_c * ab_d < 0 && cd_a * cd_b < 0)
            return true;

        return (ab_c == 0 && onSegment(l2.a, l1))
            || (ab_d == 0 && onSegment(l2.b, l1))
            || (cd_a == 0 && onSegment(l1.a, l2))
            || (cd_b == 0 && onSegment(l1.b, l2));
    }
};

double DToR(double d)
{
    return d * PI / 180;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Line> lines(n);
    for (int i = 0; i < n; i++)
    {
        int ad, bd;
        cin >> ad >> bd;

        double ar = DToR(ad / 10.0);
        Point a = { L * cos(ar),L * sin(ar) };

        double br = DToR(bd / 10.0);
        Point b = { L * cos(br),L * sin(br) };

        lines[i] = { a,b };
    }

    int ad, al;
    cin >> ad >> al;

    double ar = DToR(ad / 10.0);
    Point a = { al * cos(ar), al * sin(ar) };

    int bd, bl;
    cin >> bd >> bl;

    double br = DToR(bd / 10.0);
    Point b = { bl * cos(br), bl * sin(br) };

    Line l = { a,b };

    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += Line::IsIntersecting(l, lines[i]);

    if (cnt % 2 == 0)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define PI 3.14159265359

struct Point
{
    long double x, y;

    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        long double ccw = a.x * b.y + b.x * c.y + c.x * a.y
            - (a.y * b.x + b.y * c.x + c.y * a.x);

        if (ccw == 0)
            return 0;
        return (ccw > 0 ? +1 : -1);
    }
    friend bool operator<(const Point& a, const Point& b)
    {
        if (a.x != b.x)
            return a.x < b.x;
        return a.y < b.y;
    }
    friend bool operator<=(const Point& a, const Point& b)
    {
        if (a.x != b.x)
            return a.x < b.x;
        return a.y <= b.y;
    }
    friend bool operator>(const Point& a, const Point& b)
    {
        if (a.x != b.x)
            return a.x > b.x;
        return a.y > b.y;
    }
};
struct Line
{
    Point p1, p2;

    static bool IsIntersecting(Line a, Line b)
    {
        int p1p2 = Point::CCW(a.p1, a.p2, b.p1) * Point::CCW(a.p1, a.p2, b.p2);
        int p3p4 = Point::CCW(b.p1, b.p2, a.p1) * Point::CCW(b.p1, b.p2, a.p2);

        if (p1p2 == 0 && p3p4 == 0)
        {
            if (a.p1 > a.p2)
                swap(a.p1, a.p2);
            if (b.p1 > b.p2)
                swap(b.p1, b.p2);

            return b.p1 <= a.p2 && a.p1 <= b.p2;
        }
        return p1p2 <= 0 && p3p4 <= 0;
    }
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    int r = 1'000;

    vector<Line> lines(n);
    for (int i = 0; i < n; i++)
    {
        int p1, p2;
        cin >> p1 >> p2;

        long double x1 = r * cos(p1 / 10.0 * PI / 180);
        long double y1 = r * sin(p1 / 10.0 * PI / 180);
        lines[i].p1 = { x1,y1 };

        long double x2 = r * cos(p2 / 10.0 * PI / 180);
        long double y2 = r * sin(p2 / 10.0 * PI / 180);
        lines[i].p2 = { x2,y2 };
    }

    int t1, r1, t2, r2;
    cin >> t1 >> r1 >> t2 >> r2;

    long double x1 = r1 * cos(t1 / 10.0 * PI / 180);
    long double y1 = r1 * sin(t1 / 10.0 * PI / 180);

    long double x2 = r2 * cos(t2 / 10.0 * PI / 180);
    long double y2 = r2 * sin(t2 / 10.0 * PI / 180);

    Line l = { {x1,y1},{x2,y2} };
    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += Line::IsIntersecting(l, lines[i]);

    string result = (cnt % 2 == 0 ? "YES" : "NO");
    cout << result << '\n';
};
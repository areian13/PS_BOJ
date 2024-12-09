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

    static bool IsIntersecting(const Line& a, const Line& b)
    {

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
        Point a = { L * cos(ar),L * sin(ar)};

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
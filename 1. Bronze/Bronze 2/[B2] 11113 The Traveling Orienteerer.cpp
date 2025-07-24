#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

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

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Point> points(n);
    for (auto& point : points)
        cin >> point.x >> point.y;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int p, s;
        cin >> p >> s;

        double result = 0;
        for (int i = 0; i < p - 1; i++)
        {
            int u;
            cin >> u;

            result += Point::Dist(points[s], points[u]);
            s = u;
        }

        printf("%d\n", (int)round(result));
    }
}
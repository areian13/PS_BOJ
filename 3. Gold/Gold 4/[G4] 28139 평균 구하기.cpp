#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y;

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

    double result = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            result += Point::Dist(points[i], points[j]);
    }
    result *= 2.0 / n;

    printf("%.6lf\n", result);
}
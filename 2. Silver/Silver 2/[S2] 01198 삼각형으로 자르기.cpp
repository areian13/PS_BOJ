#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y;
};

double Tri(const Point& a, const Point& b, const Point& c)
{
    int ccw = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    return abs(ccw) / 2.;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Point> points(n);
    for (auto& [x, y] : points)
        cin >> x >> y;

    double result = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
                result = max(result, Tri(points[i], points[j], points[k]));
        }
    }
    printf("%.1lf\n", result);
}
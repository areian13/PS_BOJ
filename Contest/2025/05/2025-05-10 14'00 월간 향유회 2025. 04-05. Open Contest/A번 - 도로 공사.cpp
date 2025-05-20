#include <iostream>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y;
};

double Dist(const Point& a, const Point& b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Point> points(n);
    for (auto& [x, y] : points)
        cin >> x >> y;

    double result = Dist(points[0], points[n - 1]);
    printf("%.4lf\n", result);
}
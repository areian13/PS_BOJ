#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    double x, y;
};

double GetArea(vector<Point>& points)
{
    int n = points.size();

    double result = 0;
    for (int i = 0; i < n; i++)
    {
        result += points[i].x * points[(i + 1) % n].y;
        result -= points[i].y * points[(i + 1) % n].x;
    }
    return abs(result) / 2;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    double result = GetArea(points);
    printf("%.1lf\n", result);
}
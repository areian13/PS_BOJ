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

double GetTriAreaAt0(int k, vector<Point>& points)
{
    double x1 = points[0].x;
    double y1 = points[0].y;
    double x2 = points[k].x;
    double y2 = points[k].y;
    double x3 = points[k + 1].x;
    double y3 = points[k + 1].y;

    return ((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)) / 2;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    vector<double> preSum(n - 1, 0);
    for (int i = 1; i <= n - 2; i++)
        preSum[i] = preSum[i - 1] + GetTriAreaAt0(i, points);

    double s = preSum[n - 2] / 2;
    int k = 0;
    while (preSum[k] <= s)
        k++;

    double r = s - preSum[k - 1];
    r /= preSum[k] - preSum[k - 1];

    printf("YES\n");
    printf("%d %.12lf\n", 1, 0.0);
    printf("%d %.12lf\n", k % n + 1, r);
}
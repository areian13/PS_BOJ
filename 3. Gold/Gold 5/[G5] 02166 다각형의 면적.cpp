#include <iostream>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

struct Point
{
    int x, y;
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    long long s = 0;
    for (int i = 0; i < n; i++)
    {
        s += (long long)points[i].x * points[(i + 1) % n].y;
        s -= (long long)points[i].y * points[(i + 1) % n].x;
    }

    lf(1);
    double result = abs(s) / 2.0;
    cout << result << '\n';
}
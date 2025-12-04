#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y;

    friend bool operator < (const Point& a, const Point& b)
    {
        if (a.x == 1'000'001) return false;
        if (b.x == 1'000'001) return true;
        return a.x != b.x && abs(1. * (b.y - a.y) / (b.x - a.x)) < 1;
    }
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Point> points(n);
    for (auto& [x, y] : points)
        cin >> x >> y;
    sort(points.begin(), points.end(),
        [](const Point& a, const Point& b)
        {
            if (a.x != b.x) return a.x < b.x;
            return a.y < b.y;
        }
    );

    vector<Point> lis(n, { 1'000'001,1'000'001 });
    int result = 0;
    for(Point& p : points)
    {
        auto low = lower_bound(lis.begin(), lis.begin() + result, p);
        *low = p;
        if (low == lis.begin() + result)
            result++;
    }
    cout << result << '\n';
}
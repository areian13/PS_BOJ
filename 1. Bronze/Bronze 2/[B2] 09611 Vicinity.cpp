#include <iostream>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y;

    static double d(Point& a, Point& b)
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

    vector<Point> ps(n);
    for (auto& p : ps)
        cin >> p.x >> p.y;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int i, d;
        cin >> i >> d;
        i--;

        int result = 0;
        for (int j = 0; j < n; j++)
            result += i != j && (Point::d(ps[i], ps[j]) <= d);
        cout << result << '\n';
    }
}
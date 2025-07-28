#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y;
};

int Thick(vector<Point>& points)
{
    if (points.empty())
        return 0;

    int mx = 1e9, Mx = -1e9, my = 1e9, My = -1e9;
    for (Point& point : points)
    {
        mx = min(mx, point.x);
        Mx = max(Mx, point.x);
        my = min(my, point.y);
        My = max(My, point.y);
    }

    Point p;
    double md = 2e9;
    double ox = (Mx + mx) * 0.5, oy = (My + my) * 0.5;
    for (Point& point : points)
    {
        double d = min(abs(ox - point.x), abs(oy - point.y));
        if (d < md)
        {
            md = d;
            p = point;
        }
    }

    return min(min(Mx - p.x, p.x - mx), min(My - p.y, p.y - my));
}

int MaxThick(vector<Point>& points)
{
    int n = points.size();

    int result = 0;
    for (int axis = 0; axis < 2; axis++)
    {
        sort(points.begin(), points.end(),
            [](const Point& a, const Point& b)
            {
                if (a.x != b.x)
                    return a.x < b.x;
                return a.y < b.y;
            }
        );

        int s = 0, e = n - 1;
        while (s <= e)
        {
            int m = (s + e) / 2;

            vector<Point> a(m + 1), b(e - m);
            for (int i = 0; i <= m; i++)
                a.push_back(points[i]);
            for (int i = m + 1; i <= e; i++)
                b.push_back(points[i]);

            int at = Thick(a);
            int bt = Thick(b);

            result = max({ result, at, bt });
            if (at < bt)
                s = m + 1;
            else
                e = m - 1;
        }

        for (auto& point : points)
            swap(point.x, point.y);
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Point> points(n);
    for (auto& point : points)
        cin >> point.x >> point.y;

    int result = MaxThick(points);
    cout << result << '\n';
}
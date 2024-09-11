#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    double x, y;

    friend bool operator==(const Point& a, const Point& b)
    {
        return a.x == b.x && a.y == b.y;
    }

    struct Hash
    {
        size_t operator()(const Point& a) const
        {
            size_t h1 = hash<double>{}(a.x);
            size_t h2 = hash<double>{}(a.y);
            return h1 ^ (h2 << 1);
        }
    };
};

int CountSimPoint(vector<Point>& points)
{
    int n = points.size();

    unordered_map<Point, int, Point::Hash> isSymPoint;
    for (int i = 0; i < n; i++)
        isSymPoint[points[i]] = 1;

    int result = 1;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            Point p = 
            { 
                (points[i].x + points[j].x) / 2,
                (points[i].y + points[j].y) / 2 
            };

            isSymPoint[p] += 2;
            result = max(result, isSymPoint[p]);
        }
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    int result = CountSimPoint(points);
    cout << result << '\n';
}
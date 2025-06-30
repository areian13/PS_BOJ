#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y;

    static long long DistSq(Point& a, Point& b)
    {
        long long dx = a.x - b.x;
        long long dy = a.y - b.y;
        return dx * dx + dy * dy;
    }
    static bool compX(Point& a, Point& b)
    {
        return a.x < b.x;
    }
    static bool compY(Point& a, Point& b)
    {
        return a.y < b.y;
    }
};

pair<Point, Point> DC(int l, int r, vector<Point>& points)
{
    static auto comp = [](pair<Point, Point> a, pair<Point, Point> b)
        {
            return Point::DistSq(a.first, a.second) < Point::DistSq(b.first, b.second);
        };

    if (l == r)
        return { {INT_MAX,INT_MAX},{0,0} };

    int mid = (l + r) / 2;
    int midX = points[mid].x;

    pair<Point, Point> lMin = DC(l, mid, points);
    pair<Point, Point> rMin = DC(mid + 1, r, points);
    pair<Point, Point> result = min(lMin, rMin, comp);
    double dist = sqrt(Point::DistSq(result.first, result.second));

    vector<Point> temp;
    for (int i = l; i <= r; i++)
    {
        if (abs(points[i].x - midX) < dist)
            temp.push_back(points[i]);
    }

    sort(temp.begin(), temp.end(), Point::compY);
    for (int i = 0; i < temp.size(); i++)
    {
        for (int j = i + 1; j < temp.size() && temp[j].y - temp[i].y < dist; j++)
            result = min(result, { temp[i],temp[j] }, comp);
    }
    return result;
}

pair<Point, Point> getClosestPoint(vector<Point>& points)
{
    sort(points.begin(), points.end(), Point::compX);
    vector<Point> temp;
    return DC(0, points.size() - 1, points);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    pair<Point, Point> result = getClosestPoint(points);
    cout << Point::DistSq(result.first, result.second) << '\n';
}
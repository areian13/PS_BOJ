#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define INF INT_MAX

struct Point
{
    int x, y;

    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        int ccw = (b.x - a.x) * (c.y - a.y)
            - (b.y - a.y) * (c.x - a.x);
        return (ccw == 0 ? 0 : (ccw > 0 ? +1 : -1));
    }
    friend Point operator-(const Point& a, const Point& b)
    {
        return { a.x - b.x,a.y - b.y };
    }
    static bool compX(const Point& a, const Point& b) { return a.x < b.x; }
    static bool compY(const Point& a, const Point& b) { return a.y < b.y; }
};

auto euclidean = [](const Point& a, const Point& b)
    {
        long long dx = a.x - b.x;
        long long dy = a.y - b.y;
        return sqrt(dx * dx + dy * dy);
    };
auto sqrEuclid = [](const Point& a, const Point& b)
    {
        long long dx = a.x - b.x;
        long long dy = a.y - b.y;
        return dx * dx + dy * dy;
    };
auto manhattan = [](const Point& a, const Point& b)
    {
        return abs(1LL * a.x - b.x) + abs(1LL * a.y - b.y);
    };
auto chebyshev = [](const Point& a, const Point& b)
    {
        return max(abs(1LL * a.x - b.x), abs(1LL * a.y - b.y));
    };

void MakeConvexHull(vector<Point>& points, vector<int>& indices)
{
    Point p0 = *min_element(points.begin(), points.end(),
        [](Point& a, Point& b)
        {
            if (a.y != b.y)
                return a.y < b.y;
            return a.x > b.x;
        }
    );
    sort(points.begin(), points.end(),
        [&p0](Point& a, Point& b)
        {
            int ccw = Point::CCW(p0, a, b);
            if (ccw != 0)
                return (ccw > 0);
            if (a.y != b.y)
                return a.y < b.y;
            return a.x > b.x;
        }
    );

    int n = points.size();
    for (int i = 0; i < n; i++)
    {
        while (indices.size() >= 2)
        {
            int second = indices.back();
            indices.pop_back();
            int first = indices.back();

            if (Point::CCW(points[first], points[second], points[i]) > 0)
            {
                indices.push_back(second);
                break;
            }
        }

        indices.push_back(i);
    }
}
pair<Point, Point> MaxEuclidean(vector<Point>& points)
{
    vector<int> indices;
    MakeConvexHull(points, indices);

    int h = indices.size();
    vector<Point> hull(h);
    for (int i = 0; i < h; i++)
        hull[i] = points[indices[i]];

    pair<Point, Point> result = { {0,0},{0,0} };
    auto comp = [](pair<Point, Point> a, pair<Point, Point> b)
        {
            return euclidean(a.first, a.second) < euclidean(b.first, b.second);
        };
    for (int i = 0, j = 1; i < h; i++)
    {
        while (j + 1 < h &&
            Point::CCW({ 0,0 }, hull[i + 1] - hull[i], hull[j + 1] - hull[j]) >= 0)
        {
            result = max(result, { hull[i], hull[j] }, comp);
            j++;
        }
        result = max(result, { hull[i], hull[j] }, comp);
    }
    return result;
}

template <typename Func>
pair<Point, Point> DC(int l, int r, vector<Point>& points, Func& dist)
{
    auto comp = [&dist](const pair<Point, Point>& a, const pair<Point, Point>& b)
        {
            return dist(a.first, a.second) < dist(b.first, b.second);
        };

    if (l == r)
        return { {INF,INF},{0,0} };

    int m = (l + r) / 2;
    pair<Point, Point> lMin = DC(l, m, points, dist);
    pair<Point, Point> rMin = DC(m + 1, r, points, dist);
    pair<Point, Point> result = min(lMin, rMin, comp);
    auto d = dist(result.first, result.second);

    vector<Point> temp;
    for (int i = l; i <= r; i++)
    {
        if (abs(points[i].x - points[m].x) < d)
            temp.push_back(points[i]);
    }
    sort(temp.begin(), temp.end(), Point::compY);

    int t = temp.size();
    for (int i = 0; i < t - 1; i++)
    {
        for (int j = i + 1; j < t && temp[j].y - temp[i].y < d; j++)
            result = min(result, { temp[i],temp[j] }, comp);
    }
    return result;
}

pair<Point, Point> MinEuclidean(vector<Point>& points)
{
    sort(points.begin(), points.end(), Point::compX);
    return DC(0, points.size() - 1, points, euclidean);
}

void Convert(vector<Point>& points, bool flag)
{
    for (auto& point : points)
    {
        auto [x, y] = point;
        point = { x + y,x - y };
        if (flag)
            point.x /= 2, point.y /= 2;
    }
}

pair<Point, Point> MaxChebyshev(vector<Point>& points)
{
    Point l = { INF,0 }, r = { -INF,0 };
    Point d = { 0,INF }, u = { 0,-INF };
    for (auto& point : points)
    {
        if (point.x < l.x)
            l = point;
        if (point.x > r.x)
            r = point;
        if (point.y < d.y)
            d = point;
        if (point.y > u.y)
            u = point;
    }

    if (chebyshev(l, r) < chebyshev(d, u))
        return { d, u };
    return { l,r };
}

pair<Point, Point> MaxManhattan(vector<Point>& points)
{
    Convert(points, false);
    auto result = MaxChebyshev(points);
    Convert(points, true);

    vector<Point> temp = { result.first, result.second };
    Convert(temp, true);
    return { temp[0], temp[1] };
}
pair<Point, Point> MinManhattan(vector<Point>& points)
{
    sort(points.begin(), points.end(), Point::compX);
    return DC(0, points.size() - 1, points, manhattan);
}

pair<Point, Point> MinChebyshev(vector<Point>& points)
{
    Convert(points, false);
    auto result = MinManhattan(points);
    Convert(points, true);

    vector<Point> temp = { result.first, result.second };
    Convert(temp, true);
    return { temp[0], temp[1] };
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Point> points(n);
    for (auto& point : points)
        cin >> point.x >> point.y;

    auto [ME1, ME2] = MaxEuclidean(points);
    cout << sqrEuclid(ME1, ME2) << '\n';
    auto [mE1, mE2] = MinEuclidean(points);
    cout << sqrEuclid(mE1, mE2) << '\n';

    auto [MM1, MM2] = MaxManhattan(points);
    cout << manhattan(MM1, MM2) << '\n';
    auto [mM1, mM2] = MinManhattan(points);
    cout << manhattan(mM1, mM2) << '\n';

    auto [MC1, MC2] = MaxChebyshev(points);
    cout << chebyshev(MC1, MC2) << '\n';
    auto [mC1, mC2] = MinChebyshev(points);
    cout << chebyshev(mC1, mC2) << '\n';
}
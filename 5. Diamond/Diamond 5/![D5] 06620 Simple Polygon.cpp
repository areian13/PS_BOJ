#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y;

    friend auto operator <=> (const Point& a, const Point& b) = default;
    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        long long ccw = 1LL * (b.x - a.x) * (c.y - a.y)
            - 1LL * (b.y - a.y) * (c.x - a.x);
        return ccw != 0 ? ccw > 0 ? +1 : -1 : 0;
    }
};

struct Line
{
    Point a, b;
    int i;

    long double YatX(int x) const { return 1.l * (b.y - a.y) / (b.x - a.x) * (x - a.x) + a.y; }
    static bool OnSegment(const Line& l, const Point& p)
    {
        return Point::CCW(l.a, l.b, p) == 0
            && min(l.a.x, l.b.x) < p.x && p.x < max(l.a.x, l.b.x)
            && min(l.a.y, l.b.y) < p.y && p.y < max(l.a.y, l.b.y);
    }
    static bool IsCross(const Line& l1, const Line& l2)
    {
        auto& [a, b, i] = l1;
        auto& [c, d, j] = l2;

        int ab_cd = Point::CCW(a, b, c) * Point::CCW(a, b, d);
        int cd_ab = Point::CCW(c, d, a) * Point::CCW(c, d, b);

        if (ab_cd < 0 && cd_ab < 0)
            return true;
        return OnSegment(l1, c) || OnSegment(l1, d)
            || OnSegment(l2, a) || OnSegment(l2, b);
    }
};
struct Event
{
    Point p;
    int idx;
    bool isEnd;

    friend bool operator < (const Event& a, const Event& b)
    {
        if (a.p.x != b.p.x)
            return a.p.x < b.p.x;
        if (a.isEnd != b.isEnd)
            return a.isEnd < b.isEnd;
        return a.p.y < b.p.y;
    }
};

bool IsAdj(int i, int j, int n)
{
    return (i + 1) % n == j || (j + 1) % n == i;
}

bool HasCross(vector<Line>& lines)
{
    int n = lines.size();

    vector<Event> events(n * 2);
    for (int i = 0; i < n; i++)
    {
        events[i * 2 + 0] = { lines[i].a,i,false };
        events[i * 2 + 1] = { lines[i].b,i,true };
    }
    sort(events.begin(), events.end());

    int curX;
    auto comp = [&curX](const Line& a, const Line& b)
        {
            long double t = a.YatX(curX) - b.YatX(curX);
            if (abs(t) > 1e-9)
                return t < 0;
            return a.a < b.a;
        };
    multiset<Line, decltype(comp)> mts(comp);
    for (auto& [p, idx, isEnd] : events)
    {
        curX = p.x;
        if (!isEnd)
        {
            auto u = mts.insert(lines[idx]);
            auto v = next(u);
            if (v != mts.end() &&
                Line::IsCross(*u, *v))
                return true;
            if (u != mts.begin() &&
                Line::IsCross(*prev(u), *u))
                return true;
        }
        else
        {
            auto u = mts.lower_bound(lines[idx]);
            if (u == mts.end())
                continue;
            auto v = next(u);
            if (u != mts.begin() && v != mts.end() &&
                Line::IsCross(*prev(u), *v))
                return true;
            mts.erase(u);
        }
    }
    return false;
}

int main()
{
    FastIO;

    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        vector<Point> points(n);
        for (auto& point : points)
            cin >> point.x >> point.y;

        vector<Line> lines(n);
        for (int i = 0; i < n; i++)
        {
            Point a = points[i], b = points[(i + 1) % n];
            if (a > b)
                swap(a, b);
            lines[i] = { a,b,i };
        }

        bool result = HasCross(lines);
        cout << result << '\n';
    }
}
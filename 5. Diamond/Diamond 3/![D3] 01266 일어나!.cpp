#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    double x, y;

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

    long double YatX(int x) const { return 1.l * (b.y - a.y) / (b.x - a.x) * (x - a.x) + a.y; }
    static bool OnSegment(const Line& l, const Point& p)
    {
        return Point::CCW(l.a, l.b, p) == 0
            && min(l.a.x, l.b.x) <= p.x && p.x <= max(l.a.x, l.b.x)
            && min(l.a.y, l.b.y) <= p.y && p.y <= max(l.a.y, l.b.y);
    }
    static bool IsCross(const Line& l1, const Line& l2)
    {
        auto& [a, b] = l1;
        auto& [c, d] = l2;

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
            auto v = next(u), p = prev(u);
            if (v != mts.end() && Line::IsCross(*u, *v))
                return true;
            if (u != mts.begin() && Line::IsCross(*u, *p))
                return true;
        }
        else
        {
            auto u = mts.lower_bound(lines[idx]);
            auto v = next(u), p = prev(u);
            if (u != mts.begin() && v != mts.end() && Line::IsCross(*p, *v))
                return true;
            mts.erase(u);
        }
    }
    return false;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Line> lines(n);
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        Point a = { x1,y1 }, b = { x2,y2 };
        if (a > b)
            swap(a, b);

        lines[i] = { a,b };
    }

    bool result = HasCross(lines);
    cout << result << '\n';
}
#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <queue>
#include <map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const double EPS = 1e-9;
bool Is0(double val) { return abs(val) < EPS; }

struct Point
{
    double x, y;

    friend Point operator + (const Point& a, const Point& b) { return { a.x + b.x,a.y + b.y }; }
    friend Point operator - (const Point& a, const Point& b) { return { a.x - b.x,a.y - b.y }; }
    friend Point operator * (const Point& a, double d) { return { a.x * d,a.y * d }; }

    static double dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
    static double cross(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }

    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        double ccw = cross(b - a, c - a);
        return (Is0(ccw) ? 0 : (ccw > 0 ? +1 : -1));
    }

    friend auto operator <=> (const Point& a, const Point& b) = default;
    friend istream& operator >> (istream& is, Point& p)
    {
        is >> p.x >> p.y;
        return is;
    }
    friend ostream& operator << (ostream& os, const Point& p)
    {
        os << p.x << ' ' << p.y;
        return os;
    }

    static Point Rotate(const Point& p, int m)
    {
        return { p.x * m - p.y,p.x + p.y * m };
    }
};

struct Segment
{
    Point a, b;

    double Slope() const { return (b.y - a.y) / (b.x - a.x); }
    double YatX(double x) const { return Slope() * (x - a.x) + a.y; }

    static bool OnSegment(const Segment& l, const Point& p)
    {
        auto& [a, b] = l;
        return Point::CCW(a, b, p) == 0
            && min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x)
            && min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
    }
    static bool IsIntersect(const Segment& l0, const Segment& l1)
    {
        auto& [a, b] = l0;
        auto& [c, d] = l1;

        int ab_cd = Point::CCW(a, b, c) * Point::CCW(a, b, d);
        int cd_ab = Point::CCW(c, d, a) * Point::CCW(c, d, b);

        if (ab_cd < 0 && cd_ab < 0)
            return true;
        return OnSegment(l0, c) || OnSegment(l0, d)
            || OnSegment(l1, a) || OnSegment(l1, b);
    }
    static Point GetIntersection(const Segment& l0, const Segment& l1)
    {
        auto& [a, b] = l0;
        auto& [c, d] = l1;

        double det = Point::cross(b - a, d - c);
        if (Is0(det)) return (b == c ? b : a);
        return a + (b - a) * (Point::cross(c - a, d - c) / det);
    }

    friend auto operator <=> (const Segment& a, const Segment& b) = default;
    friend istream& operator >> (istream& is, Segment& l)
    {
        is >> l.a >> l.b;
        return is;
    }
    friend ostream& operator << (ostream& os, const Segment& l)
    {
        os << l.a << ' ' << l.b;
        return os;
    }
};

enum EventType
{
    START, INTERSECTION, END,
};
struct Event
{
    Point point;
    EventType type;
    int i0, i1;

    Event(Point point, EventType type, int i0) : point(point), type(type), i0(i0), i1(-1) {}
    Event(Point point, EventType type, int i0, int i1) : point(point), type(type), i0(i0), i1(i1) {}

    friend bool operator < (const Event& a, const Event& b)
    {
        if (!Is0(a.point.x - b.point.x)) return a.point.x > b.point.x;
        if (!Is0(a.point.y - b.point.y)) return a.point.y > b.point.y;
        return a.type > b.type;
    }
};

struct BentelyOttmann
{
    struct SegmentCmp {
        const BentelyOttmann* bo;

        bool operator()(const Segment& l, const Segment& r) const {
            double yl = l.YatX(bo->curX), yr = r.YatX(bo->curX);
            if (!Is0(yl - yr)) return yl < yr;

            double sl = l.Slope(), sr = r.Slope();
            if (!Is0(sl - sr)) return bo->after ? (sl < sr) : (sl > sr);
            return bo->segIndex.at(l) < bo->segIndex.at(r);
        }
    };

    double curX;
    bool after;

    priority_queue<Event> events;
    multiset<Segment, SegmentCmp> activeSegments;
    map<Segment, int> segIndex;
    set<pair<int, int>> result;

    BentelyOttmann(vector<Segment> segments)
        : activeSegments(SegmentCmp(this))
    {
        int n = segments.size();
        set<int> slopes;
        for (int i = 0; i < n; i++)
        {
            auto [a, b] = segments[i];
            if (a.x != b.x) slopes.insert((b.y - a.y) / (b.x - a.x));
        }

        int m = 0;
        while (slopes.count(m) != 0)
            m++;

        for (int i = 0; i < n; i++)
        {
            auto& [a, b] = segments[i];
            a = Point::Rotate(a, m);
            b = Point::Rotate(b, m);
            if (a > b) swap(a, b);

            segIndex[segments[i]] = i;
            events.push(Event(a, EventType::START, i));
            events.push(Event(b, EventType::END, i));
        }

        after = false;
        while (!events.empty())
        {
            auto [point, type, i0, i1] = events.top();
            events.pop();

            curX = point.x;
            if (type == EventType::START)
            {
                auto u = activeSegments.insert(segments[i0]);
                auto p = prev(u), v = next(u);
                if (u != activeSegments.begin() && Segment::IsIntersect(*p, *u))
                    Push(*p, *u);
                if (v != activeSegments.end() && Segment::IsIntersect(*u, *v))
                    Push(*u, *v);
            }
            else if (type == EventType::END)
            {
                auto u = activeSegments.lower_bound(segments[i0]);
                auto p = prev(u), v = next(u);
                if (u != activeSegments.begin() && v != activeSegments.end() && Segment::IsIntersect(*p, *v))
                    Push(*p, *v);
                activeSegments.erase(u);
            }
            else if (type == EventType::INTERSECTION)
            {
                Segment a = segments[i0], b = segments[i1];
                if (a.Slope() > b.Slope()) swap(a, b);

                if (Is0(curX - a.b.x) || Is0(curX - b.b.x))
                    continue;

                activeSegments.erase(a), activeSegments.erase(b);

                after = true;

                auto lower = activeSegments.insert(a), below = prev(lower);
                auto upper = activeSegments.insert(b), above = next(upper);

                if (lower != activeSegments.begin() && Segment::IsIntersect(*lower, *below))
                    Push(*lower, *below);
                if (above != activeSegments.end() && Segment::IsIntersect(*upper, *above))
                    Push(*upper, *above);

                after = false;
            }
        }
    }

    void Push(const Segment& a, const Segment& b)
    {
        int i0 = segIndex[a], i1 = segIndex[b];

        if (i0 > i1) swap(i0, i1);
        if (result.count({ i0,i1 }) != 0) return;

        Point inter = Segment::GetIntersection(a, b);
        events.push(Event(inter, EventType::INTERSECTION, i0, i1));
        result.insert({ i0,i1 });
    }
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Segment> segments(n);
    for (Segment& segment : segments)
        cin >> segment;

    BentelyOttmann bo(segments);
    cout << bo.result.size() << '\n';
}
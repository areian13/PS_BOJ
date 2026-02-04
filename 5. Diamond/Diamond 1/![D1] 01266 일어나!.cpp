#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;
const double EPS = 1e-9;
bool IsZero(double val) { return abs(val) < EPS; }

struct Point
{
    double x, y;

    friend auto operator <=> (const Point& a, const Point& b) = default;
    friend Point operator + (const Point& a, const Point& b) { return { a.x + b.x,a.y + b.y }; }
    friend Point operator - (const Point& a, const Point& b) { return { a.x - b.x,a.y - b.y }; }
    friend Point operator * (const Point& a, double d) { return { a.x * d,a.y * d }; }

    static double dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
    static double cross(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }

    static int CCW(const Point& a, const Point& b, const Point& c)
    {
        double ccw = cross(b - a, c - b);
        return (IsZero(ccw) ? 0 : (ccw > 0 ? +1 : -1));
    }

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
};

struct Line
{
    Point a, b;

    double YatX(double x) const { return (b.y - a.y) / (b.x - a.x) * (x - a.x) + a.y; }
    double Slope() const { return IsZero(b.x - a.x) ? INF : (b.y - a.y) / (b.x - a.x); }

    static bool OnSegment(const Line& l, const Point& p)
    {
        auto& [a, b] = l;
        if (Point::CCW(a, b, p) != 0)
            return false;
        return min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x)
            && min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
    }
    static vector<Point> GetInters(const Line& l0, const Line& l1, bool bound = true)
    {
        auto& [a, b] = l0;
        auto& [c, d] = l1;

        int ab_cd = Point::CCW(a, b, c) * Point::CCW(a, b, d);
        int cd_ab = Point::CCW(c, d, a) * Point::CCW(c, d, b);

        if (ab_cd < 0 && cd_ab < 0)
            return { a + (b - a) * (Point::cross(c - a, d - c) / Point::cross(b - a, d - c)) };

        if (!bound) return {};

        set<Point> inters;
        if (OnSegment(l0, c)) inters.insert(c);
        if (OnSegment(l0, d)) inters.insert(d);
        if (OnSegment(l1, a)) inters.insert(a);
        if (OnSegment(l1, b)) inters.insert(b);
        return vector<Point>(inters.begin(), inters.end());
    }

    friend auto operator <=> (const Line& a, const Line& b) = default;
    friend istream& operator >> (istream& is, Line& l)
    {
        is >> l.a >> l.b;
        return is;
    }
    friend ostream& operator << (ostream& os, const Line& l)
    {
        os << l.a << ' ' << l.b;
        return os;
    }
};

enum EventType
{
    START, END, INTERSECTION,
};
struct Event
{
    Point p;
    EventType type;
    vector<Line> lines;

    Event(const Point& p, const Line& line, EventType type)
        : p(p), type(type)
    {
        lines.push_back(line);
    }
    Event(const Point& p, const vector<Line>& lines, EventType type)
        : p(p), type(type), lines(lines)
    {
    }

    friend bool operator == (const Event& a, const Event& b)
    {
        if (b.type == EventType::INTERSECTION)
            return a.lines[0] == b.lines[0] && a.lines[1] == b.lines[1]
            || a.lines[0] == b.lines[1] && a.lines[1] == b.lines[0];
        return a.lines[0] == b.lines[0];
    }
};

struct BentelyOttmann
{
    double curX;
    bool after;

    struct EventCmp {
        bool operator()(const Event& a, const Event& b) const {
            if (a.p != b.p) return a.p > b.p;
            return a.type > b.type;
        }
    };
    struct LineCmp {
        const BentelyOttmann* bo;

        bool operator()(const Line& l, const Line& r) const {
            double yl = l.YatX(bo->curX), yr = r.YatX(bo->curX);
            if (!IsZero(yl - yr)) return yl < yr;

            double sl = l.Slope(), sr = r.Slope();
            return bo->after ? (sl < sr) : (sl > sr);
        }
    };

    priority_queue<Event, vector<Event>, EventCmp> events;
    set<Line, LineCmp> activeLines;
    // vector<pair<Line, Line>> intersections;
    int count;

    BentelyOttmann(vector<Line> lines)
        : events(EventCmp()), activeLines(LineCmp(this))
    {
        count = 0;
        for (auto& line : lines)
        {
            auto& [a, b] = line;
            if (a > b)
                swap(a, b);

            events.push(Event(a, line, EventType::START));
            events.push(Event(b, line, EventType::END));
        }

        while (!events.empty())
        {
            Event e = events.top();
            events.pop();

            after = false;
            curX = e.p.x;
            switch (e.type)
            {
            case EventType::START:
            {
                auto u = activeLines.insert(e.lines[0]).first;
                auto p = prev(u), v = next(u);
                if (u != activeLines.begin())
                    VerifyIntersection(*p, *u, e);
                if (v != activeLines.end())
                    VerifyIntersection(*u, *v, e);
                break;
            }
            case EventType::END:
            {
                /*cout << '\n';
                for (auto& l : activeLines)
                    cout << l << '\n';
                cout << e.lines[0] << '\n';*/

                auto u = activeLines.find(e.lines[0]);
                auto p = prev(u), v = next(u);
                if (u != activeLines.begin() && v != activeLines.end())
                    VerifyIntersection(*p, *v, e);
                activeLines.erase(e.lines[0]);
                break;
            }
            case EventType::INTERSECTION:
            {
                Line& a = e.lines[0];
                Line& b = e.lines[1];

                //cout << a << ' ' << b << '\n';

                AdjustLines(a, b, e);
                //intersections.push_back(a.a < b.a ? make_pair(a, b) : make_pair(b, a));
                count++;
                return;
                break;
            }
            }
        }
    }

    void VerifyIntersection(const Line& a, const Line& b, const Event& e, bool bound = true)
    {
        vector<Point> inters = Line::GetInters(a, b, bound);
        if (inters.empty())
            return;

        Point& p = inters[0];
        Event auxE(p, { a,b }, EventType::INTERSECTION);
        if (p > e.p && VerifyEvents(a, b, auxE))
            events.push(auxE);
    }
    bool VerifyEvents(const Line& a, const Line& b, const Event& e)
    {
        auto temp(events);
        while (!temp.empty())
        {
            if (temp.top().type == EventType::INTERSECTION &&
                temp.top() == e)
                return false;
            temp.pop();
        }
        return true;
    }

    void AdjustLines(const Line& a, const Line& b, const Event& e)
    {
        activeLines.erase(a);
        activeLines.erase(b);

        after = true;
        for (auto& l : { a, b })
        {
            auto u = activeLines.insert(l).first;
            auto p = prev(u), v = next(u);

            if (u != activeLines.begin())
                VerifyIntersection(*p, *u, e, false);
            if (v != activeLines.end())
                VerifyIntersection(*u, *v, e, false);
        }
        after = false;
    }
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Line> lines(n);
    for (Line& line : lines)
        cin >> line;

    BentelyOttmann bo(lines);
    cout << !!bo.count << '\n';
}
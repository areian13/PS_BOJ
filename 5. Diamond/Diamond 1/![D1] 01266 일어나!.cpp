#include <iostream>
#include <vector>
#include <set>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

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
};

struct Line
{
    Point a, b;

    double YatX(int x) const { return (b.y - a.y) / (b.x - a.x) * (x - a.x) + a.y; }
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

    friend istream& operator >> (istream& is, Line& l)
    {
        is >> l.a >> l.b;
        return is;
    }
};

enum EventType
{
    START, END, INTERSECTION, VERTICAL
};
struct Event
{
    Point p;
    EventType type;
    double value;
    vector<Line> ls;

    Event(const Point& p, const Line& l, EventType type) 
        : p(p), value(p.x), type(type) { ls.push_back(l); }
    Event(const Point& p, const vector<Line>& ls, EventType type)
        : p(p), value(p.x), type(type), ls(ls) {}
};

struct BentelyOttmann
{
    inline static auto comp = [](const Event& a, const Event& b) { return a.value > b.value; };

    priority_queue<Event, vector<Event>, decltype(comp)> events;
    set<Line, Line> activeLines;
    vector<pair<Line, Line>> intersections;

    BentelyOttmann(vector<Line> lines) : events(comp)
    {
        for (auto& line : lines)
        {
            auto& [a, b] = line;
            if (a > b)
                swap(a, b);

            if (a.x == b.x)
                events.push(Event(a, line, EventType::VERTICAL));
            else
            {
                events.push(Event(a, line, EventType::START));
                events.push(Event(b, line, EventType::END));
            }
        }

        while (!events.empty())
        {
            Event e = events.top();
            events.pop();


        }
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
    cout << bo.intersections.size() << '\n';
}
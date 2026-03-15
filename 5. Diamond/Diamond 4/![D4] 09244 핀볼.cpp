#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;
const double EPS = 1e-9;
bool IsZero(double val) { return abs(val) < EPS; }

struct Point
{
    int x, y;

    friend bool operator < (const Point& a, const Point& b)
    {
        if (a.y != b.y) return a.y > b.y;
        return a.x < b.x;
    }
    friend bool operator == (const Point& a, const Point& b) { a.x == b.x && a.y == b.y; }
};
struct Segment
{
    Point a, b;

    double Slope() const { return 1. * (b.y - a.y) / (b.x - a.x); }
    double XatY(int y) const { return (y - a.y) / Slope() + a.x; }
    double YatX(int x) const { return Slope() * (x - a.x) + a.y; }
};
struct Event
{
    Point p;
    int idx;
    bool isEnd;

    friend bool operator < (const Event& a, const Event& b) { return a.p < b.p; }
};

bool OnOver(const Segment& s, const Point& p)
{
    return min(s.a.x, s.b.x) <= p.x && p.x <= max(s.a.x, s.b.x)
        && s.XatY(p.x) > p.y;
}

int Drop(Point ball, vector<Segment>& segments)
{
    int n = segments.size();
    if (n == 0) return ball.x;

    vector<Event> events(n * 2);
    for (int i = 0; i < n; i++)
    {
        events[i * 2] = { segments[i].a,i,false };
        events[i * 2 + 1] = { segments[i].b,i,true };
    }
    sort(events.begin(), events.end());

    auto comp = [&ball](const Segment& a, const Segment& b)
        { return a.XatY(ball.y) < b.XatY(ball.y); };
    set<Segment, decltype(comp)> active(comp);

    for (auto& [point, idx, isEnd] : events)
    {
        ball.y = point.y;

        Segment& s = segments[idx];
        if (!isEnd)
            active.insert(s);
        else
        {
            auto u = active.find(s);
            auto p = prev(u), v = next(u);

            vector<Segment> cand;
            if (OnOver(*u, ball)) cand.push_back(*u);
            if (u != active.begin() && OnOver(*p, ball)) cand.push_back(*p);
            if (v != active.end() && OnOver(*v, ball)) cand.push_back(*v);

            if (cand.empty())
                continue;

            sort(cand.begin(), cand.end(),
                [&ball](const Segment& a, const Segment& b)
                { return a.YatX(ball.x) > b.YatX(ball.x); }
            );

            ball.x = cand[0].a.y < cand[0].b.y ? cand[0].a.x : cand[0].b.x;
            active.erase(u);
        }
    }

    return ball.x;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Segment> segments(n);
    for (auto& [a, b] : segments)
    {
        cin >> a.x >> a.y >> b.x >> b.y;
        if (b < a) swap(a, b);
    }

    int x;
    cin >> x;

    int result = Drop({ x,INF }, segments);
    cout << result << '\n';
}
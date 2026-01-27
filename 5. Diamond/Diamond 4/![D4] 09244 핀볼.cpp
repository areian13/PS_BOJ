#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

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
struct Line
{
    Point a, b;

    double YatX(int x) const { return 1. * (b.y - a.y) / (b.x - a.x) * (x - a.x) + a.y; }
};
struct Event
{
    Point p;
    int idx;
    bool isEnd;

    friend bool operator < (const Event& a, const Event& b) { return a.p < b.p; }
};

int Drop(int x, vector<Line>& lines)
{
    int n = lines.size();

    vector<Event> events(n * 2);
    for (int i = 0; i < n; i++)
    {
        events[i * 2] = { lines[i].a,i,false };
        events[i * 2 + 1] = { lines[i].b,i,true };
    }
    sort(events.begin(), events.end());

    auto comp =
        [&x](const Line& a, const Line& b)
        {
            double t = a.YatX(x) - b.YatX(x);
            if (!IsZero(t)) return t < 0;
            return a.a < b.a;
        };
    multiset<Line, decltype(comp)> mts(comp);
    for (auto& [p, idx, isEnd] : events)
    {
        Line& l = lines[idx];

        if (!isEnd)
        {

        }
        else
        {

        }
    }

    return x;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Line> lines(n);
    for (auto& [a, b] : lines)
    {
        cin >> a.x >> a.y >> b.x >> b.y;
        if (b < a)
            swap(a, b);
    }

    int x;
    cin >> x;

    int result = Drop(x, lines);
    cout << result << '\n';
}
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define INF INT_MAX

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
        long long ccw = 1LL * (b.x - a.x) * (c.y - a.y)
            - 1LL * (b.y - a.y) * (c.x - a.x);
        return (ccw > 0) - (ccw < 0);
    }
    static long long Dist(const Point& a, const Point& b)
    {
        long long dx = abs(a.x - b.x);
        long long dy = abs(a.y - b.y);
        return dx + dy;
    }

    friend istream& operator >> (istream& is, Point& p)
    {
        is >> p.x >> p.y;
        return is;
    }
};

array<double, 4> dx = { 1,0,-1,0 };
array<double, 4> dy = { 0,-1,0,1 };

struct Line
{
    Point a, b;

    static bool OnSegment(const Line& l, const Point& p)
    {
        return Point::CCW(l.a, l.b, p) == 0
            && min(l.a.x, l.b.x) <= p.x && p.x <= max(l.a.x, l.b.x)
            && min(l.a.y, l.b.y) <= p.y && p.y <= max(l.a.y, l.b.y);
    }
    static vector<Point> GetInters(const Line& l0, const Line& l1)
    {
        auto& [a, b] = l0;
        auto& [c, d] = l1;

        int ab_cd = Point::CCW(a, b, c) * Point::CCW(a, b, d);
        int cd_ab = Point::CCW(c, d, a) * Point::CCW(c, d, b);

        if (ab_cd < 0 && cd_ab < 0)
            return { a + (b - a) * (1.0 * Point::cross(c - a, d - c) / Point::cross(b - a, d - c)) };

        set<Point> inters;
        if (OnSegment(l0, c)) inters.insert(c);
        if (OnSegment(l0, d)) inters.insert(d);
        if (OnSegment(l1, a)) inters.insert(a);
        if (OnSegment(l1, b)) inters.insert(b);
        return vector<Point>(inters.begin(), inters.end());
    }

    friend istream& operator >> (istream& is, Line& l)
    {
        is >> l.a >> l.b;
        return is;
    }
};

int main()
{
    FastIO;

    double l;
    int n;
    cin >> l >> n;
    l++;

    vector<Line> lines = {
        {l,l,l,-l},
        {l,-l,-l,-l},
        {-l,-l,-l,l},
        {-l,l,l,l},
        {0,0,0,0}
    };

    Point p = { 0,0 };
    int d = 0;
    long long result = 0;
    bool isLive = true;
    for (int i = 0; i < n; i++)
    {
        int k;
        char c;
        cin >> k >> c;

        Point np = p + Point{ dx[d],dy[d] } *k;
        Line l = { p,np };
        Point minInter = { INF,INF };
        for (int i = 0; i < lines.size() - 1; i++)
        {
            vector<Point> inters = Line::GetInters(l, lines[i]);
            for (Point& inter : inters)
            {
                if (Point::Dist(p, minInter) > Point::Dist(p, inter))
                    minInter = inter;
            }
        }

        if (minInter == Point{ INF, INF })
        {
            result += k;
            p = np;
            lines.push_back(l);
            if (c == 'L')
                d = (d + 3) % 4;
            else
                d = (d + 1) % 4;
        }
        else
        {
            result += Point::Dist(p, minInter);
            isLive = false;
            break;
        }
    }

    if (isLive)
    {
        Point np = p + Point{ dx[d],dy[d] } * l * 2;
        Line l = { p,np };
        Point minInter = { INF,INF };
        for (int i = 0; i < lines.size() - 1; i++)
        {
            vector<Point> inters = Line::GetInters(l, lines[i]);
            for (Point& inter : inters)
            {
                if (Point::Dist(p, minInter) > Point::Dist(p, inter))
                    minInter = inter;
            }
        }
        result += Point::Dist(p, minInter);
    }
    cout << result << '\n';
}
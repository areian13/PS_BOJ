#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y;

    friend bool operator < (const Point& a, const Point& b)
    {
        if (a.x != b.x)
            return a.x < b.x;
        return a.y < b.y;
    }
    friend bool operator == (const Point& a, const Point& b)
    {
        return a.x == b.x && a.y == b.y;
    }
    friend bool operator != (const Point& a, const Point& b)
    {
        return !(a == b);
    }
};
struct Line
{
    Point a, b;

    friend bool operator < (const Line& a, const Line& b)
    {
        if (a.a != b.a)
            return a.a < b.a;
        return a.b < b.b;
    }
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Line> lines(n);
    for (auto& line : lines)
        cin >> line.a.x >> line.a.y >> line.b.x >> line.b.y;
    sort(lines.begin(), lines.end());


}
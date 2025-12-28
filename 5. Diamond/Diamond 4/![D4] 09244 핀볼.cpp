#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y;
};
struct Line
{
    Point p0, p1;
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Line> lines(n);
    for (auto& [p0, p1] : lines)
        cin >> p0.x >> p0.y >> p1.x >> p1.y;

    int x;
    cin >> x;

    int result = Drop(x, lines);
    cout << result << '\n';
}
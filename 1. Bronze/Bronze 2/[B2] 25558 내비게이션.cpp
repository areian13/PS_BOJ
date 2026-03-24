#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y;

    friend istream& operator >> (istream& is, Point& p)
    {
        is >> p.x >> p.y;
        return is;
    }
};

long long Dist(const vector<Point>& route)
{
    int m = route.size();
    long long result = 0;
    for (int i = 0; i < m - 1; i++)
        result += 1LL * abs(route[i].x - route[i + 1].x) + abs(route[i].y - route[i + 1].y);
    return result;
}

int main()
{
    FastIO;

    int n;
    Point s, e;
    cin >> n >> s >> e;

    vector<vector<Point>> routes(n);
    for (auto& route : routes)
    {
        int m;
        cin >> m;

        route.resize(m + 2);
        route[0] = s, route[m + 1] = e;
        for (int j = 1; j <= m; j++)
            cin >> route[j];
    }

    int result = min_element(routes.begin(), routes.end(),
        [](const vector<Point>& a, const vector<Point>& b)
        { return Dist(a) <= Dist(b); }
    ) - routes.begin();
    cout << result + 1 << '\n';
}
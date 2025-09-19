#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y, z;

    friend auto operator <=> (const Point& a, const Point& b) = default;
};

int dxs(int x1, int x2) 
{ 
    int dx = x1 - x2;
    return dx * dx;
}

pair<int, int> ClosestPoints(vector<Point>& points)
{
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());

    int n = points.size();
    int dist = 1e9, cnt = 0;
    map<int, map<int, set<int>>> dim3;
    for (int l = 0, r = 0; r < n; r++)
    {
        auto& [x1, y1, z1] = points[r];
        int sq1 = sqrt(dist) + 1;
        while (l < r)
        {
            auto& [x2, y2, z2] = points[l];
            if (x1 - x2 <= sq1)
                break;

            l++;
            dim3[x2][y2].erase(z2);
            if (dim3[x2][y2].empty()) dim3[x2].erase(y2);
            if (dim3[x2].empty()) dim3.erase(x2);
        }

        for (auto& [x2, dim2] : dim3)
        {
            int sq2 = sqrt(dist - dxs(x1, x2)) + 1;
            auto it = dim2.lower_bound(y1 - sq2);
            while (it != dim2.end() && it->first <= y1 + sq2)
            {
                auto& [y2, dim1] = *it++;
                int sq3 = sqrt(dist - dxs(x1, x2) - dxs(y1, y2)) + 1;
                auto jt = dim1.lower_bound(z1 - sq3);
                while (jt != dim1.end() && *jt <= z1 + sq3)
                {
                    int z2 = *jt++;
                    int d = dxs(x1, x2) + dxs(y1, y2) + dxs(z1, z2);
                    if (dist > d)
                        dist = d, cnt = 1;
                    else if (dist == d)
                        cnt++;
                }
            }
        }

        dim3[x1][y1].insert(z1);
    }

    return { dist,cnt };
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Point> points(n);
    for (auto& [x, y, z] : points)
        cin >> x >> y >> z;

    auto [dist, cnt] = ClosestPoints(points);
    cout << dist << '\n' << cnt << '\n';
}
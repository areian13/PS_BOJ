#include <iostream>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    long long x, y, z;
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Point> points(n);
    for (auto& [x, y, z] : points)
        cin >> x >> y >> z;

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        long long x, y, z, r;
        cin >> x >> y >> z >> r;

        int result = 0;
        for (auto& [px, py, pz] : points)
        {
            long long dx = x - px;
            long long dy = y - py;
            long long dz = z - pz;

            long long d = dx * dx + dy * dy + dz * dz;
            result += (d <= r * r);
        }

        cout << result << '\n';
    }
}
#include <iostream>
#include <vector>
#include <cfloat>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

struct Pos
{
    int x, y;
};

double Dist(const Pos& a, const Pos& b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Pos> pos(n);
    for (int i = 0; i < n; i++)
        cin >> pos[i].x >> pos[i].y;

    double minDist = DBL_MAX;
    Pos result = { 0,0 };
    for (int i = 1; i < n; i++)
    {
        double dist = Dist(pos[0], pos[i]);
        if (dist < minDist)
        {
            minDist = dist;
            result = pos[i];
        }
    }

    lf(2);
    cout << pos[0].x << ' ' << pos[0].y << '\n';
    cout << result.x << ' ' << result.y << '\n';
    cout << minDist << '\n';
}
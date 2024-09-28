#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int x, y;
};

int Dist(Pos a, Pos b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Pos> pos(n);
    for (int i = 0; i < n; i++)
        cin >> pos[i].x >> pos[i].y;

    int total = 0;
    for (int i = 0; i < n - 1; i++)
        total += Dist(pos[i], pos[i + 1]);

    int skip = 0;
    for (int i = 1; i < n - 1; i++)
    {
        Pos prev = pos[i - 1];
        Pos curr = pos[i];
        Pos next = pos[i + 1];

        int course = Dist(prev, curr) + Dist(curr, next);
        int straight = Dist(prev, next);
        skip = max(skip, course - straight);
    }

    int result = total - skip;
    cout << result << '\n';
}
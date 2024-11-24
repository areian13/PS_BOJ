#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int MinRotate(int sx, int sy, int ex, int ey, int px, int py)
{
    if (sx == ex)
    {
        if (px == sx && min(sy, ey) <= py && py <= max(sy, ey))
            return 2;
        return 0;
    }
    if (sy == ey)
    {
        if (py == sy && min(sx, ex) <= px && px <= max(sx, ex))
            return 2;
        return 0;
    }
    return 1;
}

int main()
{
    FastIO;

    int sx, sy, ex, ey, px, py;
    cin >> sx >> sy >> ex >> ey >> px >> py;

    int result = MinRotate(sx, sy, ex, ey, px, py);
    cout << result << '\n';
}
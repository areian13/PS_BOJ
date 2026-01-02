#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int DistSqr(int ax, int ay, int bx, int by)
{
    int dx = ax - bx;
    int dy = ay - by;
    return dx * dx + dy * dy;
}

bool IsIn(int w, int h, int x, int y, int px, int py)
{
    if (x <= px && px <= x + w &&
        y <= py && py <= y + h)
        return true;

    int r = h / 2;
    if (DistSqr(x, y + r, px, py) <= r * r ||
        DistSqr(x + w, y + r, px, py) <= r * r)
        return true;
    return false;
}

int main()
{
    FastIO;

    int w, h, x, y, p;
    cin >> w >> h >> x >> y >> p;

    int result = 0;
    for (int i = 0; i < p; i++)
    {
        int px, py;
        cin >> px >> py;
        result += IsIn(w, h, x, y, px, py);
    }
    cout << result << '\n';
}
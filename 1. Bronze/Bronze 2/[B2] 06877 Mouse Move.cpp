#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int c, r;
    cin >> c >> r;

    int x = 0, y = 0;
    while (true)
    {
        int dx, dy;
        cin >> dx >> dy;

        if (dx == 0 && dy == 0)
            break;

        x = min(max(x + dx, 0), c);
        y = min(max(y + dy, 0), r);
        cout << x << ' ' << y << '\n';
    }
}
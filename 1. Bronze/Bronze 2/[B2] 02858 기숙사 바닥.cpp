#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 2> GetFloorSize(int r, int b)
{
    int s = r + b;

    for (int q = 1; q * q <= s; q++)
    {
        if (s % q != 0)
            continue;

        int p = s / q;
        if ((p + q - 2) * 2 == r)
            return { p,q };
    }
    return { -1,-1 };
}

int main()
{
    FastIO;

    int r, b;
    cin >> r >> b;

    array<int, 2> result = GetFloorSize(r, b);
    cout << result[0] << ' ' << result[1] << '\n';
}
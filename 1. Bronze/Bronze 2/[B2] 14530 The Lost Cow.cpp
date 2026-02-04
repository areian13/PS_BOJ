#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int x, y;
    cin >> x >> y;

    int result = 0;
    int u = x, s = 1, d = +1;
    while (u != y)
    {
        int v = x + s * d;

        if (u < y && y <= v || u > y && y >= v)
            v = y;

        result += abs(v - u);
        u = v;

        s <<= 1;
        d *= -1;
    }
    cout << result << '\n';
}